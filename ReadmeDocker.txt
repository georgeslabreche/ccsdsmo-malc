In order to build MAL/C with docker you have to create a docker image using one of the 2 provided
configuration files: CentOSDockerfile or OpenSuseDockerfile.
These images will contain the requirements to build MAL/C.
Then, the freshly built image can be used to build (local) MAL/C.

For example to build an OpenSuse instance of MAL/C:
1. Creates the docker image
  docker build -t malc-centos -f CentOSDockerfile .
2. Creates and launches a emporary docker container to build current project
  docker run --rm -u `id -u`:`id -g` -v $PWD:$PWD -w $PWD malc-centos ./genmakeall
  
