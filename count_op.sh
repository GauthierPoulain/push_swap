make re -j
clear
while true;
do
ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap $ARG | wc -l
done;