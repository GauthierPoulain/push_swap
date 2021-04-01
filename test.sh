#!/bin/bash
clear
make
MAX=0
while true;
do
ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
# echo $ARG
RET=$(./push_swap $ARG | ./checker $ARG)
NB=$(./push_swap $ARG | wc -l)
clear
echo $RET
echo $NB
if [ $NB -gt $MAX ]
then
	MAX=$NB
fi
echo "max = $MAX"
if [ "$RET" != "OK" ]
then
	echo $ARG
	read -n 1 k <&1
fi
done;