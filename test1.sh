#!/bin/bash

arr=( */ )
declare -i j=0

for i in "${arr[@]}";
do 
    echo "$j => $i"
    ((j++))
done

# declare -i k=0
# for i in {0..10};
# do 
#     echo "$k => ${arr[$i]}"
#     ((k++))
# done