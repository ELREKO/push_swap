#include "../includes/push_swap.h"

// forward rotating 
void ft_rotate_forw(t_stack **lst, int *error)
{
    t_stack *lst_tmp;
    t_stack *lst_tail;
    t_stack *lst_head;

    lst_tmp = *lst;
    lst_tail = ft_lst_new((*lst) ->value, (*lst)  ->index, (*lst)  ->isNum, error);
    *lst = (*lst) ->next;
    free(lst_tmp);
    lst_head = *lst;
    while ((*lst)  ->next != NULL)
        (*lst)  = (*lst)  ->next;
    (*lst) ->next = lst_tail;
    *lst = lst_head; 
}

// backward rotating
void ft_rotate_backw(t_stack **lst)
{
    t_stack *lst_tmp_head;
    t_stack *lst_tmp_ret;
    t_stack *lst_tmp;

    int i_count;
    int i_size;

    lst_tmp = *lst;
    i_size = ft_lstsize(lst_tmp);
    lst_tmp_head = ft_lastlst(*lst);
    lst_tmp_ret = lst_tmp;
    i_count = 1;
    while (i_size > i_count)
    {
        if (i_count + 1 == i_size)
            lst_tmp -> next = NULL;
        else
            lst_tmp = lst_tmp -> next;
        i_count++;
    }
    lst_tmp_head ->next = lst_tmp_ret;
    *lst = lst_tmp_head;
}

void ft_push(t_stack **lst_src, t_stack **lst_dest, int *error)
{
    t_stack *lst_tmp_src;
    t_stack *lst_tmp_front;

    lst_tmp_src = *lst_src;
    lst_tmp_front = ft_lst_new(lst_tmp_src->value, lst_tmp_src->index, lst_tmp_src->isNum, error);
    ft_lst_add_front(lst_dest, lst_tmp_front);
    ft_lst_del_front(lst_src);
}