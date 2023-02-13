#!/bin/bash
# This script checks the existence of a file
[[ $# = 1 ]] || { echo "ERRO: indique apenas um ficheiro" >&2; exit 1; }
echo "Checking..."
if [[ -f $1 ]] ; then
echo "$1 existe."
else
echo "$1 não existe"
fi
echo "...done."


# falta  a alínea b) 