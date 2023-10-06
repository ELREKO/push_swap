#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack 
{
    int value;
    int index;
    int isNum;
    struct s_stack *next;
} t_stack;

// init.c
t_stack *ft_read_arg(int argc, char **arg);

// utiles.c
int ft_char_nbr(char *str, int *error , int i_len);
int	ft_check_on_nbr(char *str, int *error);


// lst_operation
void ft_lst_print(t_stack *lst);
int ft_lstsize (t_stack *lst);
t_stack *ft_lastlst(t_stack *lst);
t_stack *ft_lst_new (int value, int index, int isNum);
void ft_lst_add_front (t_stack **lst_mod, t_stack *lst_front );
void ft_lst_del_front (t_stack **lst_mod);


// rules.c
void ft_swap_revers(t_stack **stack, int i_sort);
void ft_rotate_forw(t_stack **lst);
void ft_rotate_backw(t_stack **lst);
void ft_push(t_stack **lst_src, t_stack **lst_dest);

// errorhandling.c
void ft_free_lst(t_stack *lst);
void ft_throw_error(int errNum, t_stack **lst);

#endif