# CCSDS MO MAL C Apps for OPS-SAT SEPP/Linux

This project includes: 
- An implementation of the [CCSDS MO MAL Standard](https://en.wikipedia.org/wiki/CCSDS_Mission_Operations) in C using [ZeroMQ](zeromq.org) as transport backend.
- [Generated MO MAL service areas](https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/tree/opssat/apps/generated_areas) for the [OPS-SAT](https://opssat1.esoc.esa.int/) spacecraft.
- Applications using the MAL C API, developed to run onboard the [OPS-SAT](https://opssat1.esoc.esa.int/) spacecraft's SEPP/Linux environment.

CCSDS Mission Operation implementations for other languages (e.g. Java) can be found on the [CCSDS MO WebSite](http://ccsdsmo.github.io/)

Complete MAL specification can be found on the [CCSDS website](http://public.ccsds.org/publications/BlueBooks.aspx) in the *published documents* section.
In particular:
  - [CCSDS 521.0-B-2, Mission Operations Message Abstraction Layer (MAL)](https://public.ccsds.org/Pubs/521x0b2e1.pdf)
  - [CCSDS 524.1-B-1, Mission Operations--MAL Space Packet Transport Binding and Binary Encoding](https://public.ccsds.org/Pubs/524x1b1.pdf)
  - [CCSDS 524.2-B-1, Mission Operations--MAL Binding to TCP/IP Transport and Split Binary Encoding](https://public.ccsds.org/Pubs/524x2b1.pdf)
  - [CCSDS 524.4-R-1, Mission Operations--MAL Binding to ZMTP Transport](https://public.ccsds.org/Lists/CCSDS%205244R1/524x4r1.pdf)

## ABOUT
- The CCSDS MO MAL C API was originally developed for the [CNES](http://cnes.fr), the French Space Agency, by [ScalAgent](http://www.scalagent.com/en/).
- The OPS-SAT MO MAL service areas were generated from XML specifications with the [CCSDS MO StubGenerator](https://github.com/georgeslabreche/CCSDS_MO_StubGenerator).
- The MAL C apps are located in the [apps folder](https://github.com/georgeslabreche/ccsdsmo-malc/tree/opssat/apps), originally developed for [ESA / ESOC](https://www.esa.int/About_Us/ESOC) by [TanagraSpace](https://tanagraspace.com/) in partnership with [VisionSpace](https://www.visionspace.com/).

## PROJECT DOCUMENTATION

CCSDS MO MAL C documentation is available at http://ccsdsmo.github.io/malc

Source code and comments in the source code are in English so you can proably get a good idea of what is goining on by just having a look at the code. A good place to start is the `test` directory for sample MO MAL interactions and in the [apps/nmfapi_c_demo](https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/tree/opssat/apps/nmfapi_c_demo) directory for sample OPS-SAT MO MAL C apps developed to run on the spacecraft's SEPP/Linux environment.

## INSTALLATION

### GSL

The project requires **GSL** version 4.1 to be installed. **GSL** can be found [here](https://github.com/imatix/gsl.git).

### ZeroMQ

The project requires **ZMQ** version 4.0.10 to be installed. The v4.0.10 tag for **ZMQ** can be found [here](https://github.com/zeromq/zeromq4-x/tree/v4.0.10).

Review the [INSTALL](https://github.com/zeromq/zeromq4-x/blob/v4.0.10/INSTALL) documentation. In a nutshell:
```
git clone https://github.com/zeromq/zeromq4-x.git
cd zeromq4-x
git checkout tags/v4.0.10 -b v4.0.10
./autogen.sh
./configure
make check
sudo make install
sudo ldconfig
```

### CZMQ

The project requires an update of **CZMQ** v3.0.2 with patches provided by the [v3.0.2-10 source package in Ubuntu](https://launchpad.net/ubuntu/+source/czmq/3.0.2-10). The patched version is tagged as v3.0.2-10 and can be found [here](https://github.com/tanagraspace/opssat-czmq/tree/v3.0.2-10). Review the "Building and Installing" of the [README](https://github.com/tanagraspace/opssat-czmq#toc3-71) documentation. In a nutshell:

```
git clone https://github.com/tanagraspace/opssat-czmq.git
cd opssat-czmq
./autogen.sh
./configure
make check
sudo make install
sudo ldconfig
```

### ZPROJECT

The project requires **zproject** to be installed. **zproject** can be found [here](https://github.com/zeromq/zproject).

After installing 'zproject', the file 'zproject_known_projects.xml' (normally located in /usr/local/bin directory)
has to be updated in order to contain the right versions of libzmq and czmq:

```xml
    <use project = "libzmq" prefix = "zmq"
        repository = "https://github.com/zeromq/zeromq4-x"
        test = "zmq_init"
        release = "v4.0.10" />

    <use project = "czmq" libname = "libczmq"
        repository = "https://github.com/tanagraspace/opssat-czmq.git"
        test = "zctx_test"
        release = "v3.0.2-10">
        <use project = "libzmq" />
    </use>
```

and the definition of new projects such as 'mal':

```xml
    <!-- MAL/C Projects -->

    <use project = "malutil"
        repository = ""
        test = "clog_test"
        cmake_name = "MALUTIL">
    </use>

    <use project = "malattributes"
        repository = ""
        test = "mal_string_test"
        cmake_name = "MALATTRIBUTES">
    </use>

    <use project = "mal"
        repository = ""
        test = "mal_ctx_test"
        cmake_name = "MAL">
    </use>

    <use project = "malbinary"
        repository = ""
        test = "malbinary_encoder_test"
        cmake_name = "MALBINARY">
    </use>

    <use project = "malsplitbinary"
        repository = ""
        test = "malsplitbinary_encoder_test"
        cmake_name = "MALSPLITBINARY">
    </use>

    <use project = "malzmq"
        repository = ""
        test = "malzmq_ctx_test"
        cmake_name = "MALZMQ">
    </use>

    <use project = "maltcp"
        repository = ""
        test = "maltcp_ctx_test"
        cmake_name = "MALTCP">
    </use>

    <use project = "testarea"
        repository = ""
        test = "testarea_testservice_testcomposite_test"
        cmake_name = "TESTAREA">
    </use>

    <use project = "malactor"
        repository = ""
        test = "mal_actor_test"
        cmake_name = "MALACTOR">
    </use>

    <!-- Library projects that depend on MAL/C projects -->

    <use project = "generated_areas"
        repository = ""
        test = "generated_areas_test"
        cmake_name = "GENERATED_AREAS">
    </use>

    <use project = "nmfapi_c"
        repository = ""
        test = "nmf_api_test"
        cmake_name = "NMFAPI_C">
    </use>
```

### MAL/C QUICK INSTALLATION

Download the sources from github (https://github.com/ccsdsmo/malc) in the MAL_HOME
directory (for example ~/cnes/malc).

Go to MAL home (MAL_HOME) directory and launch "./genmakeall" shell script. This script generates
makefiles for each module then compiles and installs the different modules.

The last modules are base tests for the multiples MAL interactions (SEND, SUBMIT, REQUEST, INVOKE,
PROGRESS and PUBLISH/SUBSCRIBE). If unwanted you can comment the call to "genmake_tests" function in
the last line of the genmakeall shell script.

The genmakeall commands accept multiples targets: 
  - all (default target): generates makefiles, then compiles and installs
  all the modules.
  - clean: cleans all the generated stuff (alternatively, use `git clean -d -f -x`)
  - gen: generates makefiles.
  - compile: compiles each modules.
  - install: installs the generated libraries and includes.
  - check: launches unit tests.

By default, the installation directory for MAL/C libraries and includes is "MAL\_HOME/local". It can be changed by defining the MAL\_LOCAL environnement variable.


### COMPILATION, INSTALLATION

The project is composed of multiples modules:
  - util: currently logging API.
  - malattributes: The MAL attributes are extracted from the MAL API to avoid a circular
  dependency between MAL API and encoding APIs.
  - malbinary: An implementation of the SPP encoding.
  - malsplitbinary: An implementation of the split binary encoding.
  - mal: The MAL/C API implementation.
  - malactor: An actor framework on top of the MAL C API, it uses the notions of poller,
  end-point and handler. It is based on the notion of CZMQ actor.
  - malzmq: An implementation of the ZMTP transport
  - maltcp: An implementation of the TCP transport.

The test directory contains examples of code for each MAL interaction: SEND, SUBMIT, REQUEST,
INVOKE, PROGRESS and PUBLISH/SUBSCRIBE. Each example constitutes a module.

Each module can be individually built using the genmake shell script in the corresponding
directory. The genmake commands accept multiples targets: 
  - all (default target): generates makefiles for the module, then compiles and installs
  the generated libraries and includes.
  - clean: cleans all the generated stuff.
  - gen: generates makefiles for the module.
  - compile: compiles the module.
  - check: launches unit tests.
  - install: installs the generated libraries and includes.

The module can be manually built as follows (corresponding to target gen + compile):

    ./generate.sh
    ./autogen.sh
    ./configure --prefix=$MAL_LOCAL
    make

The command to compile the source is:

    make

The command to launch the tests is:

    make check

The command to install the libraries and includes(in $MAL_LOCAL) is:

    make install

## OPTIONS

In 'project.xml' all dependencies must be listed in the order of the dependence,
even if a dependency depends on another. For example the project 'testarea' 
depends on:

```xml
    <use project = "malattributes" />
    <use project = "mal" />
    <use project = "malbinary" />
```

**Important:** For cross-compilation to work, as documented [here](apps/demo/README.md), projects must be listed in order of dependence. For instance, in the above example, *mal* depends on *malattributes* so the latter listed prior to the former.

C99 is required.

For bool type:

    /usr/lib/gcc/x86_64-redhat-linux/4.1.2/include/stdbool.h

For NULL Macro:

    /usr/lib/gcc/x86_64-redhat-linux/4.1.2/include/stddef.h


## CREATE NEW APP
1. Create a new app folder in the apps directory, e.g. `mkdir apps/new_program && cd apps/new_program`
2. Copy the following files from the demo app folder into the newly created app folder:
    - generate.sh
    - genmake
    - license.xml
    - project.xml
3. Update `project.xml` with configurations relevant to the new app.
    - Make sure that the names of the classes and main program code to be generated are different than the project name.
    - For instance, if the the project name is `new_program` then the main file should be named differently, e.g. `new_program_app`.
4. Create a README file.
5. Commit and push project files into the repo.
6. Invoke genmake to generate code and build the app: `./genmake`.
7. If a main program was defined in `project.xml` then run the executable binary that was created to check if it runs as expected, e.g.: `./src/new_program_app -v`
8. Make sure to only commit and push the relevant generated .c and .h files located in the `src` and `include` directories:
    - A lot of files have been generated from running `./genmake` in step 6.
    - Refer to the demo app folder in the source code repo as a reference on what to commit and what not to commit.
9. Copy the scripts folder from the demo app into the newly created app folder. These are deployment and ipk creation scripts. Update the following files:
    - scripts/sepp_package/CONTROL/control
    - scripts/env.sh
10. Review all other files in the scripts folder in case they need to be customized for the app's deployment purposes.
11. Update the `genmake_apps` function in `genmakeall` to include the newly created app (optional).

## UPDATING DOCUMENTATION

Project documentation is entirely in Markdown and lives in the `docs` directory. It is compiled into a static site thanks to [mkdocs](http://www.mkdocs.org/).

After updating the content of the `docs` directory in the `master` branch, you can automatically upload the docs to Github Pages with the following command:

    mkdocs gh-deploy --clean
