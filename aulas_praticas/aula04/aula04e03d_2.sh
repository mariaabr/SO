#!/bin/bash

if (($# != 1)); then
    echo "Introduza apenas um argumento, um ficheiro .txt"
    exit 2
else
    arr=($(cat $1)) #le o ficheiro introduzido no terminal ao executar o programa

    #echo $arr
    #echo $(cat $1)

    for ((i = 0; i < ${#arr[@]}; i++)); do
        for ((j = i+1; j < ${#arr[@]}; j++)); do
            #echo ${arr[j]}
            if ((${arr[j]} < ${arr[i]})); then
                ssi=${arr[i]}
                ssj=${arr[j]}
                arr[i]=$ssj
                arr[j]=$ssi
                #${arr[i]} = ${arr[j]}
                #${arr[j]} = ${arr[i]}
            fi
        done
    done
fi

#echo ${arr[@]}

for i in ${!arr[@]}; do
    echo "$(($i+1)): ${arr[i]}"
done