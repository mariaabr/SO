#!/bin/bash
# select structure to create menus
PS3="escolha a sua comidinha (e to exit): "
select arg in $@; do
    echo "You picked $arg ($REPLY)."
    if [[ $arg == "e" ]]; then
        echo $?
    fi
done

#não sei fazer a alínea b)?!