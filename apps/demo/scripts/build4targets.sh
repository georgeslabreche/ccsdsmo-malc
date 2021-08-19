
#!/usr/bin/env bash

# DESCRIPTION
# ===========
#
# A cross-compilation build script.
# This script is a workaround for problems related to the generated cross-compilation build.sh script.
# It addresses these problems prior by "hotfixing" the generated build.sh scripts before invoking them.
#
# Prerequisite: run the genmake command in the app's project directory.
#
# THE PROBLEM
# ===========
#
# The mal dependencies are listed as projects in the zproject_known_projects.xml file.
# However, these mal projects have blank values set as their git repository urls.
# This results in a cross-compilation build.sh file with invalid git clone commands — e.g.:
#
# git clone --quiet --depth 1  malattributes
#
# Instead of something like this:
#
# git clone --quiet --depth 1 -b v1.2.0 https://github.com/georgeslabreche/malattributes.git malattributes
#
# This can't be resolved unless we create dedicated git repositories for each mal project.
# It doesn't seem like zproject supports setting a file system path for a project directory instead of a
# repository url. Furthermore, the cross-compilation build.sh script cannot simply be edited because it 
# is generated and will be overwritten each time the app project's genmake script is invoked.
#
# THE SOLUTION
# ============
#
# This build4targets.sh script is a workaround to the aforementioned problem. It replaces the invalid git
# clone commands with commands that will copy the mal project directories where they would normally be 
# cloned into if they had dedicated repositories — i.e., into builds/rpi/tmp-deps/

# Set the bash script variables.
source env.sh

# List target environments that we want to cross-compile against.
# These tagets are listed as <target name="" /> elements in project.xml — e.g., <target name = "rpi" />
TARGETS=('rpi')

# List the mal project dependencies.
MAL_PROJECTS=('malutil' 'malattributes' 'mal' 'malbinary' 'malsplitbinary' 'malzmq' 'maltcp' 'malactor')

# List the apps project dependencies.
APPS_PROJECTS=('generated_areas' 'nmfapi')

# Parse the "incremental" parameter if given.
# For the purposes of this script, an "incremental" build is understood as just rebuilding the app,
# i.e. don't rebuild the dependencies.
while [[ $# -gt 0 ]]; do
    key="$1"
    case $key in
        -i|--incremental)
        INCREMENTAL=0
        ;;
        *)
        # unknown option
        ;;
    esac
    shift # past argument or value
done

# Got the app's directory.
cd ..

# Cross compile for each taget environment.
for target in "${TARGETS[@]}"
do
    # Check that cross-compilation directory exists.
    if [ ! -d "builds/${target}" ]; then
        echo "The 'builds/${target}' target environment directory does not exist. Skipping..."
    else

        # Clean things up before starting.
        make clean

        # Make sure that already built depedencies are not deleted if we build with the "incremental" parameter.
        sed -i 's/\if \[ -d ".\/tmp" \]/\if \[ ! $INCREMENTAL \] \&\& \[ -d ".\/tmp" \]/g' builds/${target}/build.sh
        sed -i 's/\if \[ -d ".\/tmp-deps" \]/\if \[ ! $INCREMENTAL \] \&\& \[ -d ".\/tmp-deps" \]/g' builds/${target}/build.sh

        # If incremental flag is set then we need to explicitely delete the build's bin directory.
        # This is because this delete is disabled in the build.sh with the previous sed commands.
        if [ $INCREMENTAL ] && [ -d "./builds/${target}/tmp/bin" ]; then
            rm -rf builds/${target}/tmp/bin
        fi

        # Cross-compile target environment message.
        echo "Setting up cross-compilation for '${target}' target environment."

        for proj in "${MAL_PROJECTS[@]}"
        do
            # Some verbosity.
            echo "Preparing the '${proj}' dependency."

            # Remove all generated files before copying the project into builds/${target}/tmp-deps
            cd ../../${proj} && git clean -d -f -x && cd ../apps/${PROJECT_NAME}

            # Replace the git clone commands with rsync commands.
            sed -i "s/git clone --quiet --depth 1  ${proj}$/mkdir ${proj} \&\& cp -R ..\/..\/..\/..\/..\/${proj}\/{generate.sh,genmake,include,license.xml,project.xml,src} ${proj}\/ \&\& cd ${proj} \&\& .\/generate.sh/g" builds/${target}/build.sh
        done

        # Do the same for the apps project dependencies.
        for proj in "${APPS_PROJECTS[@]}"
        do
            # Some verbosity.
            echo "Preparing the '${proj}' dependency."

            # Remove all generated files before copying the project into builds/${target}/tmp-deps
            cd ../${proj} && git clean -d -f -x && cd ../${PROJECT_NAME}

            # Replace the git clone commands with rsync commands.
            sed -i "s/git clone --quiet --depth 1  ${proj}$/mkdir ${proj} \&\& cp -R  ..\/..\/..\/..\/..\/apps\/${proj}\/{generate.sh,genmake,include,license.xml,project.xml,src} ${proj}\/ \&\& cd ${proj} \&\& .\/generate.sh/g" builds/${target}/build.sh
        done

        # Build the app using the Rasberry Pi cross-compilation script.
        cd builds/${target}

        # Invoke incremental build or not.
        if [ $INCREMENTAL ]; then
            ./build.sh -i
        else
            ./build.sh
        fi

        # Display file info of the output libraries to check that they were correctly built for the target environment.
        # Do this for the MAL libraries
        for proj in "${MAL_PROJECTS[@]}"
        do
            file tmp/lib/lib${proj}*
        done

        # Also do it for the Apps libraries.
        for proj in "${APPS_PROJECTS[@]}"
        do
            file tmp/lib/lib${proj}*
        done

        # And also for this project's bin file.
        file tmp/bin/${BIN_FILENAME}
    fi
done