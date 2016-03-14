# CCSDS MO MAL C API

This project is an implementation of the CCSDS MO MAL Standard in C using ZeroMQ as transport backend.

## INSTALLATION

The module 'zproject' needs to be installed: https://github.com/zeromq/zproject

Before installing 'zproject' the file 'zproject_known_projects.xml' has to be updated
in order to contain the right versions of czmq, and the definition of new projects such
as 'mal':

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

    <use project = "malattributes" />
    <use project = "malbinary" />
    <use project = "mal" />

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


