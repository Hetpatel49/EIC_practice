#!/bin/bash
#this code will take two numbers and print thier sum,difference,multiplication and division

read num1
if ! [ "$num1" -eq "$num1" ] 2> /dev/null
then
    echo "Invalid integer"
else
	read num2
	if ! [ "$num2" -eq "$num2" ] 2> /dev/null
	then
  	     echo "Invalid integer"
 	else
		echo $((num1+num2))
		echo $((num1-num2))
 		echo $((num1*num2))
 		echo $((num1/num2))
	fi
fi
