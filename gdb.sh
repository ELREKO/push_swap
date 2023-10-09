#!/bin/bash
cc      src/errorhandling.c \
        src/init.c \
        src/lst_operation.c \
        src/main.c src/rules_push.c \
        src/rules_rotate_fw.c \
        src/rules_rotate_bw.c \
        src/rules_swap.c \
        src/set_index.c \
        src/utiles.c \
        includes/push_swap.h -g
echo "Fertig"
gdb ./a.out