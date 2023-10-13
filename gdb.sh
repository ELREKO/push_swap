#!/bin/bash
cc      src/errorhandling.c \
        src/init.c \
        src/lst_operation.c \
        src/main.c src/rules_push.c \
        src/rules_rotate_fw.c \
        src/rules_rotate_bw.c \
        src/rules_swap.c \
        sort_big_sort_1_main.c \
	sort_big_sort_2_callculate.c \
	sort_big_sort_3_pushback.c \
        src/sort_simple_sort.c \
        src/set_index.c \
        src/utiles.c \
        includes/push_swap.h -g
echo "Fertig"
gdb ./a.out