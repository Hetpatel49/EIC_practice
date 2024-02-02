#!/bin/bash
#this code will take values of x and y and print whether x is greater, equal or less than y

read x
if ! [ "$x" -eq "$x" ] 2>/dev/null
then
	echo "Invalid integer"
else
	read y
	if ! [ "$y" -eq "$y" ] 2>/dev/null
	then 
		echo "Invalid integer"
	else
		if [ "$x" -eq "$y" ]	
		then 
			echo "X is equal to Y"
		elif [ "$x" -gt "$y" ]	
		then 
			echo "X is greater than Y"
		else	
			echo "X is less than Y"
		fi	
	fi
fi
