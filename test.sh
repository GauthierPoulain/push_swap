#!/bin/bash
clear
make
ITER=$2
MAX=0
MIN=-1
COUNT=0
AVG=0
TOTAL=0
while [ $COUNT -lt $ITER ]; do
	ARG=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")
	RET=$(./push_swap $ARG | ./checker $ARG)
	NB=$(./push_swap $ARG | wc -l)
	TOTAL=$(expr $TOTAL + $NB)
	COUNT=$(expr $COUNT + 1)
	AVG=$(expr $TOTAL / $COUNT)
	if [ $NB -gt $MAX ]; then
		MAX=$(expr $NB)
	fi
	if [ $MIN == -1 ]; then
		MIN=$(expr $NB)
	fi
	if [ $NB -lt $MIN ]; then
		MIN=$(expr $NB)
	fi
	clear
	echo "$COUNT / $ITER"
	echo $RET
	echo $NB
	echo "min = $MIN"
	echo "max = $MAX"
	echo "avg = $AVG"
	if [ "$RET" != "OK" ]; then
		echo $ARG
		read -n 1 k <&1
	fi
done
