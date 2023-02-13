#!/bin/bash
# For all the files in a folder, show their properties
if [[ $# -eq 1 ]] && [[ -d $1 ]]; then
    for f in $1/*; do
    file "$f"
    done
else
    echo "ERRO: indique apenas um diretorio"
fi
