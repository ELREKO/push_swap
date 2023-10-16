/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:24:22 by rkost             #+#    #+#             */
/*   Updated: 2023/10/16 13:27:17 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_str_print(char *str)
{
	char	*str_tmp;

	str_tmp = str;
	while (*str_tmp)
	{
		write(1, str_tmp, 1);
		str_tmp++;
	}
}

int	ft_strlen(char *str)
{
	int	i_count;

	i_count = 0;
	while (str[i_count] != '\0')
		i_count++;
	return (i_count);
}

// Checking is one of the given nummber double
void	ft_check_double_value_lst(t_stack *lst)
{
	t_stack	*lst_tmp;
	t_stack	*lst_head;

	lst_head = lst;
	lst_tmp = lst_head;
	while (lst_tmp -> next != NULL)
	{
		lst = lst_tmp;
		while (lst -> next != NULL)
		{
			lst = lst ->next;
			if (lst_tmp->value == lst->value)
			{
				lst_tmp = NULL;
				ft_throw_error(3, &lst_head, &lst_tmp);
			}
		}
		lst_tmp = lst_tmp->next;
	}
}
