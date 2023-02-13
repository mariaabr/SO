#!/bin/bash
# For all the files in a folder, show their properties
if [[ $# -eq 1 ]] && [[ -d $1 ]]; then
    for f in $1/*; do
    echo "$f"
		if [[ -d $f ]]; then
			f_basename="$(basename $f)"
			mv "$f" "$1/new_$f_basename"
        else
            echo "hello"
		fi
    done
elif [[ $# -eq 2 ]] && [[ -d $1 ]] && [[ "$2" == "-r" ]]; then
    for f in $1/*; do
    echo "$f"
		if [[ -d $f ]]; then
			f_basename="$(basename $f)"
            renamed="${f#*_}"
			mv "$f" "$1/$renamed"
        else
            echo "hi again"
		fi
    done
else
    echo "ERRO: indique apenas um diretorio"
fi
