#include "../includes/push_swap.h"

int ft_pow_b_10(int pow)
{
    int i_ret; 

    i_ret = 1;
    while (pow > 1)
    { 
        i_ret = i_ret * 10;
        pow--;
    }
    return (i_ret);
}

int ft_char_nbr(char *str)
{
    int i_count;
    int i_len;
    int i_ret;

    i_len = 0;
    i_count = 0;
    i_ret = 0;
    while (str[i_len] != '\0')
        i_len++;
    while (i_len > 0)
        i_ret = i_ret + ((str[i_count++] - 48) * ft_pow_b_10(i_len--));
    return(i_ret);
}

t_stack *ft_lst_fill_arg(int argc, char **arg)
{
    t_stack *lst_ret;
    t_stack *lst_head;
    int i_count;
    int i_arg;

    i_count = 1;
    lst_ret = malloc(sizeof(t_stack));
    if (!lst_ret)
        return(NULL);
    lst_head = lst_ret;
    while (i_count < argc)
    {
        i_arg = ft_char_nbr(arg[i_count++]);
        lst_ret->value = i_arg;
            if (i_count < argc) 
            {
                lst_ret->next = malloc(sizeof(t_stack));
                if (!lst_ret->next)
                    return (NULL);
                lst_ret = lst_ret->next;
            }
            else
                lst_ret->next = NULL;
    }
    lst_ret->next = NULL;
    return(lst_head);
}

void ft_lst_print(t_stack *lst)
{
    while (lst->next != NULL)
    {
        printf("%i \n", lst->value );
        lst = lst->next;
    }
    printf("%i \n", lst->value );
}
