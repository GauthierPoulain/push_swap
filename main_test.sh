#!/bin/bash
# clear
make re -j
ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
# clear
./push_swap $ARG  | ./checker $ARG
