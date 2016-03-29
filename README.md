# CCSDS MO MAL C API

This project is an implementation of the [CCSDS MO MAL Standard](https://en.wikipedia.org/wiki/CCSDS_Mission_Operations) in C using [ZeroMQ](zeromq.org) as transport backend.

Complete standard specification can be found on the [CCSDS website](http://public.ccsds.org/publications/BlueBooks.aspx) in the published docue.

## ABOUT

The CCSDS MO MAL C API was originally developed for the [CNES](http://cnes.fr), the French Space Agency, by [ScalAgent](http://www.scalagent.com/en/), a french company specialized in distributed technologies. All contributations are welcome.

## PROJECT DOCUMENTATION

Project documentation is available at http://ccsdsmo.github.io/malc

Documentation is in French for the time being. Documentation in English is planned and will be uploaded as soon as possible. 

Source code and comments in the source code are in English so you can proably get a good idea of what is goining on by just having a look at the code. A good place to start is the `samples` directory.

## INSTALLATION

The module requires **zproject** to be installed. **zproject** can be found [here](https://github.com/zeromq/zproject).

Before installing 'zproject', the file 'zproject_known_projects.xml' has to be updated
in order to contain the right versions of czmq, and the definition of new projects such
as 'mal':

```xml
    <use project = "util"
        repository = ""
        test = "clog_test"
        cmake_name = "UTIL">
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

    <use project = "malzmq"
        repository = ""
        test = "malzmq_ctx_test"
        cmake_name = "MALZMQ">
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
```
    
The installed 'zproject_known_projects.xml' is in the directory:

    /usr/local/bin

Note: This document assumes that the project is in the $HOME/cnes/malzmq directory.

If a local library dir is used, the following environment properties
have to be set:

    export CFLAGS=-I$HOME/cnes/malzmq/local/include
    export LDFLAGS=-L$HOME/cnes/malzmq/local/lib
    export LD_LIBRARY_PATH=/usr/local/lib:$HOME/cnes/malzmq/local/lib

In 'project.xml' all dependencies must be listed in the order of the dependence,
even if a dependency depends on another. For example the project 'testarea' 
depends on:

```xml
    <use project = "malattributes" />
    <use project = "malbinary" />
    <use project = "mal" />
```

Each project is built as follows:

    ./generate.sh
    ./autogen.sh
    ./configure --prefix=$HOME/cnes/malzmq/local
    make

For tests:

    make check

For installing the libraries (in $HOME/cnes/malzmq/local):

    make install

The script 'genmake' compiles all the projects.

C99 is required.

For bool type:

    /usr/lib/gcc/x86_64-redhat-linux/4.1.2/include/stdbool.h

For NULL Macro:

    /usr/lib/gcc/x86_64-redhat-linux/4.1.2/include/stddef.h

## UPDATING DOCUMENTATION

Project documentation in entirely in Markdown and lives in the `docs` directory. It is compiled into a static site thanks to [mkdocs](http://www.mkdocs.org/).

After updating the content of the `docs` directory in the `master` branch, you can autmatically upload the docs to Github Pages with the following command:

    mkdocs gh-deploy --clean
