#!/bin/bash
clear
make
while true;
do
ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
RET=$(./push_swap $ARG  | ./checker $ARG)
echo $RET
if [ "$RET" != "OK" ]
then
	echo $ARG
	read -n 1 k <&1
fi
done;