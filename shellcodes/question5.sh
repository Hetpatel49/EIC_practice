#!/bin/bash
#expression evaluation

read expression
printf "%0.3f\n" `echo "$expression" | bc -l`
