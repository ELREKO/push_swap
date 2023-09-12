#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack 
{
    int value;
    int index;
    struct s_stack *next;
} t_stack;

int ft_pow_b_10(int pow);
int ft_char_nbr(char *str);
t_stack *ft_lst_fill_arg(int argc, char **arg);
void ft_lst_print(t_stack *lst);

#endif