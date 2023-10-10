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
    int diff;
    struct s_stack *next;
} t_stack;

// errorhandling.c
void ft_free_lst(t_stack *lst);
void ft_throw_error(int errNum, t_stack **lst_a, t_stack **lst_b);

// init.c
t_stack *ft_read_arg(int argc, char **arg);

// lst_operation
int ft_lstsize (t_stack *lst);
t_stack *ft_lastlst(t_stack *lst);
t_stack *ft_lst_new (int value, int index, int isNum, int *error);
void ft_lst_add_front (t_stack **lst_mod, t_stack *lst_front);
void ft_lst_del_front (t_stack **lst_mod);

// ---rules---- 
// rules_push.c
void ft_pa(t_stack **stack_a, t_stack **stack_b, int *error);
void ft_pb(t_stack **stack_a, t_stack **stack_b, int *error);

// rules_rotate_bw.c
void ft_rra(t_stack **stack_a, int *error);
void ft_rrb(t_stack **stack_b, int *error);
void ft_rrr(t_stack **stack_a, t_stack **stack_b, int *error);

// rules_rotate_fw.c
void ft_ra(t_stack **stack_a, int *error);
void ft_rb(t_stack **stack_a, int *error);
void ft_rr(t_stack **stack_a, t_stack **stack_b, int *error);

// rules_swap.c
void ft_sa(t_stack **stack_a, int *error);
void ft_sb(t_stack **stack_b, int *error);
void ft_ss(t_stack **stack_a, t_stack **stack_b, int *error);

// set_index.c
void ft_set_index(t_stack **stack_a);

// sort_stack_sort.c
int ft_sort_three(t_stack **stack_a, int *error);
int ft_sort_stack(t_stack **stack_a, int *error);

// utiles.c
int ft_char_nbr(char *str, int *error , int i_len);
int	ft_check_on_nbr(char *str, int *error);
void ft_lst_print(t_stack *lst);
int ft_check_range(t_stack *stack_a);


#endif