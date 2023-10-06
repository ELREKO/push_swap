#include "../includes/push_swap.h"

// free the list
void ft_free_lst(t_stack *lst)
{
    t_stack *tmp;

    
    while (lst != NULL)
    {
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
    lst = NULL;
}

// Error handling
void ft_throw_error(int errNum, t_stack **lst)
{
    if (errNum == -100)
    {
        write(1, "ERROR\n", 6);
        write(1, "-- nothing to sort --\n",22);
    }
    if (errNum < 5)
    {
        ft_free_lst(*lst);
        if (errNum == 1)
        {
            write(1, "ERROR\n", 6);
            write(1, "-- malloc lst --\n",17);
        }
        if (errNum == 2)
        {
            write(1, "ERROR\n", 6);
            write(1, "-- no integer --\n",17);
        }
        if (errNum == 3)
        {
            write(1, "ERROR\n", 6);
            write(1, "-- dbl integer --\n",18);
        }
        if (errNum == 4)
        {
            write(1, "ERROR\n", 6);
            write(1, "-- sa(stack) or sb(stack) --\n",29);
        }
    }

    //5 -- erro sa or sb
    exit(0);  
}
