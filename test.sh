#!/bin/bash
clear
make
MAX=0
MIN=0
COUNT=0
MOY=0
TOTAL=0
while true;
do
ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
# echo $ARG
RET=$(./push_swap $ARG | ./checker $ARG)
NB=$(./push_swap $ARG | wc -l)
TOTAL=$(expr $TOTAL + $NB)
COUNT=$(expr $COUNT + 1)
MOY=$(expr $TOTAL / $COUNT)
clear
if [ $NB -gt $MAX ]
then
	MAX=$NB
fi
if [ $MIN == 0 ]
then
	MIN=$NB
fi
if [ $NB -lt $MIN ]
then
	MIN=$NB
fi
echo $RET
echo $NB
echo "min = $MIN"
echo "max = $MAX"
echo "avg = $MOY"
if [ "$RET" != "OK" ]
then
	echo $ARG
	read -n 1 k <&1
fi
done;