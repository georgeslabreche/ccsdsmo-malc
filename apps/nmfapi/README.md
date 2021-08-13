
## NMF API
The [NMF](https://nanosat-mo-framework.github.io/) API uses the MAL C API and is built for the [OPS-SAT spacecraft](https://opssat1.esoc.esa.int/),

## Build and deploy
The api library can be built and deployed for either the local development environment or for the SEPP environment on the spacecraft.

The app can be build and deployed for either the local development environment or for the SEPP environment on the spacecraft.
### For local development
Invoking the `genmake_tests` function inside the *genmakeall* script can be commented out for a quicker build. However, running `genmake_tests` at least once is a good way to make sure that all required dependencies are installed and running as expected before trying to build the app.

```bash
./../../genmakeall 
```

### For the spacecraft
Building for the spacecraft uses zproject/gsl's cross-compilation mechanism for the Raspberry Pi ARM 32 bit target environment. Using the Raspberry Pi toolchain is non-ideal but workable **temporary** solution. As a permanent solution a zproject_sepp.gsl script must be written that will cross-compile using the SEPP toolchain instead of using [zproject_rpi.gsl](https://github.com/zeromq/zproject/blob/master/zproject_rpi.gsl).

Read the comments for all script files in the scripts directory before executing the following commands to build and deploy the app to the spacecraft:

```bash
./../../genmakeall
./genmake
cd scripts
./build4target.sh
./deploy2sepp.sh
```

Then ssh into SEPP to untar and install the shared libraries and binary:

```
tar -xzvf malc_nmf_api.tar.gz
./sepp_install.sh
```