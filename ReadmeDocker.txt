In order to build MAL/C with docker you have to create a docker image using one of the 2 provided
configuration files: CentOSDockerfile or OpenSuseDockerfile.

For example to build an OpenSuse instance of MAL/C:
1. Creates the docker image
  docker build -t malc-centos -f .\CentOSDockerfile .
2. Creates and launches the docker container
  docker run -it malc-centos /bin/bash
3. Build the MAL/C
  cd malc && ./genmakeall
  