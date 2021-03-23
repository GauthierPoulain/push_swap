#!/bin/bash
color()(set -o pipefail;"$@" 2>&1>&3|sed $'s,.*,\e[31m&\e[m,'>&2)3>&1

make checker

printf "\-\-\-\-\RUN/-/-/-/-/\n"

color ./checker $@
printf "/-/-/-/-/END\-\-\-\-\n"