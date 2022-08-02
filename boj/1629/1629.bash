#!/bin/bash

read A
numArr=($A)

ret=${numArr[0]}

initial=$(echo -n "$ret % ${numArr[2]}" | bc)

i=1


while [ $i -lt ${numArr[1]} ]; do
	ret=$(echo -n "$ret * ${numArr[0]}" | bc)
	ret=$(echo -n "$ret % ${numArr[2]}" | bc)
	if [ $i -eq $initial ]; then
		cnt=$i
		break
	fi
	((i++))
done

numArr[1]=$(echo -n "${numArr[1]} % $cnt" | bc)
while [ $i -lt ${numArr[1]} ]; do
	ret=$(echo -n "$ret * ${numArr[0]}" | bc)
	ret=$(echo -n "$ret % ${numArr[2]}" | bc)
done


echo $ret
