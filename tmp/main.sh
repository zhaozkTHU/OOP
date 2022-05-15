#!/bin/bash
filename=test
for par in $@;
do
mkdir output-$par && python3 ${filename}.py $par 
done