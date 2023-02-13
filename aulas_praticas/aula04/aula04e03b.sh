#!/bin/bash
lista=( $(seq 2 3 15) )

echo vals ${lista[@]}
echo count ${#lista[@]}
echo index ${!lista[@]}
for ((i = 0; i < ${#lista[@]}; i++)); do
    lista[i]=$((${lista[i]}+1))
    echo "$i: ${lista[i]}"
done

unset lista[1]
unset lista[3]

echo count ${#lista[@]}

for i in ${!lista[@]}; do #o !array[@] e utilizado para quando se quer ter acesso ao indice de cada elemento
    echo "$i: ${lista[i]}"
done