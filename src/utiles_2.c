#include "../includes/push_swap.h"

void ft_str_print(char *str)
{
    char *str_tmp;

    str_tmp = str;
    while (*str_tmp)
    {
        write(1, str_tmp, 1); 
        str_tmp++;
    }
    write(1, "\n", 1); 
}

int ft_strlen(char *str)
{
    int i_count;

    char *str_tmp;
    str_tmp = str;
    while (*str_tmp++)
        i_count++;
    return (i_count);
}