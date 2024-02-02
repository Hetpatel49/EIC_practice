#!/bin/bash
#print countries from 3 to 7 index inclusive from list
while read line
do
    arr=(${arr[@]} $line)
    echo ${arr[@]}
done<contries.txt
echo ${arr[@]:3:5}
