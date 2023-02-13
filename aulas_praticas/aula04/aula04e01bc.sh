#!/bin/bash
function imprime_coisas()
{
echo $(date)
echo $(hostname)
echo $USER

#. /home/rafaela/Documents/2ano/1semestre/SO/aulas_praticas/aula04
source /home/rafaela/Documents/2ano/1semestre/SO/aulas_praticas/aula04/aula04e01a.sh #or
source ./aula04e01a.sh
return 0
}
imprime_coisas
imprime_msg