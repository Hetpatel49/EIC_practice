#!/bin/bash
#average of n numbers

read N
sum=0
i=0
while [[ i -lt $N ]]
do
	read x
	let sum=sum+x
	let i=i+1
done
printf "%0.3f\n" $(echo "$sum / $N" | bc -l)
