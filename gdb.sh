#!/bin/bash
cc src/errorhandling.c src/init.c src/lst_operation.c src/main.c src/rules_swap.c src/rules.c src/utiles.c includes/push_swap.h -g
echo "Fertig"
gdb ./a.out