#!/bin/bash
function numbers()
{
    if (($1==$2)); then
        return 0
    elif (($1<$2)); then
        return 1
    else
        return 2
    fi
}

echo $# #numero de argumentos
echo $? #valor de retorno
echo $1
echo $2
numbers $1 $2

case "$?" in
    0)
        echo "é igual"
        ;;
    1)
        echo "é menor"
        ;;
    2)
        echo "é maior"
        ;;
esac