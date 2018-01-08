#!/bin/sh

XML=$1

useproject() {
    sed -i "/\/known_projects/i \
<use project = \"$1\" \n\
     repository = \"\" \n\
     test = \"$2\" \n\
     cmake_name = \"$3\"> \n\
</use> \n\
" "$XML" || exit
}

useproject "util" "clog_test" "UTIL"
useproject "malattributes" "mal_string_test" "MALATTRIBUTES"
useproject "mal" "mal_ctx_test" "MAL"
useproject "malbinary" "malbinary_encoder_test" "MALBINARY"
useproject "malsplitbinary" "malsplitbinary_encoder_test" "MALSPLITBINARY"
useproject "malzmq" "malzmq_ctx_test" "MALZMQ"
useproject "maltcp" "maltcp_ctx_test" "MALTCP"
useproject "testarea" "testarea_testservice_testcomposite_test" "TESTAREA"
useproject "malactor" "mal_actor_test" "MALACTOR"
