#include "../includes/push_swap.h"

// changed the list reverse of the size you want! 
// -make a new list 
void ft_swap_revers(t_stack **stack, int i_rever_size)
{
    t_stack *lst_tmp[i_rever_size + 1];
    int i_count;

    lst_tmp[0] = *stack;
    i_count = 1;
    while (i_count <= i_rever_size)
    {
        lst_tmp[i_count++] = ft_lst_new(lst_tmp[0] ->value, lst_tmp[0] ->index, lst_tmp[0] ->isNum);
        lst_tmp[0] = lst_tmp[0] ->next;
    }
    i_count--;
    lst_tmp[0] = *stack;
    while (i_count >= 1)
    {
        lst_tmp[0] ->value = lst_tmp[i_count] ->value;
        lst_tmp[0] ->index = lst_tmp[i_count] ->index;
        lst_tmp[0] ->isNum = lst_tmp[i_count] ->isNum;
        lst_tmp[0] = lst_tmp[0] ->next;
        ft_free_lst(lst_tmp[i_count--]);
    } 
}

void ft_rotate_forw(t_stack **lst)
{
    t_stack *lst_tmp_head;
    t_stack *lst_tmp_next;
    int i_tmp[3];

    lst_tmp_head = *lst;
    i_tmp[0] = lst_tmp_head ->value;
    i_tmp[1] = lst_tmp_head ->index;
    i_tmp[2] = lst_tmp_head ->isNum;

    while (lst_tmp_head->next != NULL)
    {
        lst_tmp_next = lst_tmp_head ->next;
        lst_tmp_head ->value = lst_tmp_next ->value;
        lst_tmp_head ->index = lst_tmp_next ->index;
        lst_tmp_head ->isNum = lst_tmp_next ->isNum;
        lst_tmp_head = lst_tmp_head ->next;
    }

    lst_tmp_head ->value = i_tmp[0];
    lst_tmp_head ->index = i_tmp[1];
    lst_tmp_head ->isNum = i_tmp[2]; 
}

// backward rotating
// - find and sorage the last postion
// - count the stack 
// - stop at the penultimate position
// - set the "next" to null, 
// - contactet bothe together!
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

void ft_push(t_stack **lst_src, t_stack **lst_dest)
{
    t_stack *lst_tmp_src;
    t_stack *lst_tmp_front;

    
    lst_tmp_src = *lst_src;
    lst_tmp_front = ft_lst_new(lst_tmp_src->value, lst_tmp_src->index, lst_tmp_src->isNum);
    ft_lst_add_front(lst_dest, lst_tmp_front);
    ft_lst_del_front(lst_src);
}