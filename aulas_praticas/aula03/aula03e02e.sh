#!/bin/bash
#nº maior que 5 e menor que 10

echo "$#"
if [[ $1 -gt 5 && $1 -lt 10 ]]; then
    echo "número maior do que 5 e menor do que 10"
else
    echo "número menor do que 5 ou maior do que 10"
fi