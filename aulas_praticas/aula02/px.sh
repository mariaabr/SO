#!/bin/bash
#da ao utilizador permissao para executar
#os programas cujo seu nome e um parametro

echo "$#" #diz o numero de argumentas existentes e, $*
 for i in $*; do #$valor do input
    chmod u+x $i
done

echo "Os programas, têm agora, permissão para serem executados!"