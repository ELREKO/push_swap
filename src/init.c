/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:00:05 by rkost             #+#    #+#             */
/*   Updated: 2023/10/05 19:49:58 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Checking is one of the given nummber double
void	ft_check_double(t_stack *lst)
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
				ft_throw_error(3, &lst_head, NULL);
		}
		lst_tmp = lst_tmp->next;
	}
}

// check an fill the list
int	ft_add_arg(t_stack **lst, char *str, int *error)
{
	t_stack	*lst_ret;
	t_stack	*lst_tmp;
	int		i_nbr;

	i_nbr = ft_check_on_nbr(str, error);
	if (*error == 0)
	{
		i_nbr = ft_char_nbr(str, error, i_nbr);
		if (*error == 0)
		{
			lst_ret = *lst;
			if (lst_ret == NULL)
				lst_ret = ft_lst_new(i_nbr, 0, 1, error);
			else
			{
				lst_tmp = ft_lst_new(i_nbr, 0, 1, error);
				ft_lst_add_front(&lst_ret, lst_tmp);
			}
			*lst = lst_ret;
		}
		else
			*error = 2;
		return (1);
	}
	return (0);
}

//Fill the list 
t_stack	*ft_lst_fill_arg(int argc, char **arg)
{
	t_stack	*lst_ret;
	int		i_count;
	int		error;

	i_count = argc;
	lst_ret = NULL;
	while (i_count <= argc && i_count > 1)
	{
		ft_add_arg(&lst_ret, arg[i_count - 1], &error);
		if (error)
			ft_throw_error (error, &lst_ret, NULL);
		i_count--;
	}
	return (lst_ret);
}

//check Arguments > 2 
t_stack	*ft_read_arg(int argc, char **arg)
{
	t_stack	*lst_ret;

	if (argc <= 2)
		ft_throw_error(-100, &lst_ret, NULL);
	lst_ret = ft_lst_fill_arg(argc, arg);
	ft_check_double(lst_ret);
	return (lst_ret);
}
