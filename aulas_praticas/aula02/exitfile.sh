#!/bin/bash
#recebe como argumento o nome de um ficheiro e imprime
#o codigo de saida do comando file para esse ficheiro

echo "$*"
file $1
echo "Exit code: $?"