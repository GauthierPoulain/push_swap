#!/bin/bash
color()(set -o pipefail;"$@" 2>&1>&3|sed $'s,.*,\e[31m&\e[m,'>&2)3>&1
clear 

make checker

ARG=`ruby -e "puts (1..10000).to_a.shuffle.join(' ')"`
# echo "test with $ARG"

printf "\-\-\-\-\RUN/-/-/-/-/\n"

color ./checker $ARG
printf "/-/-/-/-/END\-\-\-\-\n"