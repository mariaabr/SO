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

echo "write 2 numbers:"
read num1
read num2

numbers $num1 $num2

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