#!/bin/bash
color()(set -o pipefail;"$@" 2>&1>&3|sed $'s,.*,\e[31m&\e[m,'>&2)3>&1
clear 

make checker

# ARG=`ruby -e "puts (1..10).to_a.shuffle.join(' ')"`
# echo "test with $ARG"

printf "\-\-\-\-\RUN/-/-/-/-/\n"

color ./checker 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
# color ./checker $ARG
printf "/-/-/-/-/END\-\-\-\-\n"