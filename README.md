# CCSDS MO MAL C API

This project is an implementation of the [CCSDS MO MAL Standard](https://en.wikipedia.org/wiki/CCSDS_Mission_Operations) in C using [ZeroMQ](zeromq.org) as transport backend.

CCSDS Mission Operation implementations for other languages (e.g. Java) can be found on the [CCSDS MO WebSite](http://ccsdsmo.github.io/)

Complete MAL specification can be found on the [CCSDS website](http://public.ccsds.org/publications/BlueBooks.aspx) in the *published documents* section.
In particular:
  - [CCSDS 521.0-B-2, Mission Operations Message Abstraction Layer (MAL)](https://public.ccsds.org/Pubs/521x0b2e1.pdf)
  - [CCSDS 524.1-B-1, Mission Operations--MAL Space Packet Transport Binding and Binary Encoding](https://public.ccsds.org/Pubs/524x1b1.pdf)
  - [CCSDS 524.2-B-1, Mission Operations--MAL Binding to TCP/IP Transport and Split Binary Encoding](https://public.ccsds.org/Pubs/524x2b1.pdf)
  - [CCSDS 524.4-R-1, Mission Operations--MAL Binding to ZMTP Transport](https://public.ccsds.org/Lists/CCSDS%205244R1/524x4r1.pdf)

## ABOUT

The CCSDS MO MAL C API was originally developed for the [CNES](http://cnes.fr), the French Space Agency, by [ScalAgent](http://www.scalagent.com/en/), a french company specialized in distributed technologies. All contributions are welcome.

## PROJECT DOCUMENTATION

Project documentation is available at http://ccsdsmo.github.io/malc

Source code and comments in the source code are in English so you can proably get a good idea of what is goining on by just having a look at the code. A good place to start is the `samples` directory.

## INSTALLATION

### GSL

The project requires **GSL** version 4.1 to be installed. **GSL** can be found [here](https://github.com/imatix/gsl.git).


### CZMQ

The project requires **CZMQ** version 3.0.3 to be installed. **CZMQ** can be found [here](http://github.com/zeromq/czmq).

### ZPROJECT

The project requires **zproject** to be installed. **zproject** can be found [here](https://github.com/zeromq/zproject).

After installing 'zproject', the file 'zproject_known_projects.xml' (normally located in /usr/local/bin directory)
has to be updated in order to contain the right versions of czmq, and the definition of new projects such as 'mal':

```xml
    <!-- MAL/C Projects -->

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
```

### ZEROMQ

Download the current stable version of ZeroMQ (4.1.3) from [here](http://zeromq.org/intro:get-the-software).

### MAL/C QUICK INSTALLATION

Download the sources from github (https://github.com/ccsdsmo/malc) in the MAL_HOME
directory (for example ~/cnes/malc).

Go to MAL_HOME directory and launch "./genmakeall" shell script. This script generates
makefiles for each module then compiles and installs the different modules.

The last modules are base tests for the multiples MAL interactions (SEND, SUBMIT, REQUEST, INVOKE,
PROGRESS and PUBLISH/SUBSCRIBE). If unwanted you can comment the call to "genmake_tests" function in
the last line of the genmakeall shell script.

The genmakeall commands accept multiples targets: 
  - all (default target): generates makefiles, then compiles and installs
  all the modules.
  - clean: cleans all the generated stuff.
  - gen: generates makefiles.
  - compile: compiles each modules.
  - install: installs the generated libraries and includes.
  - check: launches unit tests.

By default, the installation directory for MAL/C libraries and includes is "MAL_HOME/local".
It can be changed in "MAL_HOME/bin/env.sh" shell script, this script defines various
environment variables depending of the installation directory:

    export MAL_LOCAL=$MAL_HOME/local
    export CFLAGS=-I$MAL_LOCAL/include
    export LDFLAGS=-L$MAL_LOCAL/lib
    export LD_LIBRARY_PATH=/usr/local/lib:$MAL_LOCAL/lib

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
    <use project = "malbinary" />
    <use project = "mal" />
```

C99 is required.

For bool type:

    /usr/lib/gcc/x86_64-redhat-linux/4.1.2/include/stdbool.h

For NULL Macro:

    /usr/lib/gcc/x86_64-redhat-linux/4.1.2/include/stddef.h

## UPDATING DOCUMENTATION

Project documentation is entirely in Markdown and lives in the `docs` directory. It is compiled into a static site thanks to [mkdocs](http://www.mkdocs.org/).

After updating the content of the `docs` directory in the `master` branch, you can automatically upload the docs to Github Pages with the following command:

    mkdocs gh-deploy --clean
