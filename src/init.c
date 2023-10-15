/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:00:05 by rkost             #+#    #+#             */
/*   Updated: 2023/10/15 18:27:20 by rkost            ###   ########.fr       */
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
			{
				lst_tmp = NULL;
				ft_throw_error(3, &lst_head, &lst_tmp);
			}
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
				lst_ret = ft_lst_new(i_nbr, 0, 0, error);
			else
			{
				lst_tmp = ft_lst_new(i_nbr, 0, 0, error);
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

void	ft_split_arg(t_stack **lst_ret, char *str, int *error)
{
	t_stack	*lst_tmp;
	int		i_count;
	int		i_count_read;
	char	*str_value;

	i_count = ft_strlen(str) - 1;
	while (i_count >= 0)
	{
		i_count_read = 0;
		while (str[i_count] != ' ' && str[i_count] != '\t' && 
			str[i_count] != '\0')
		{
			i_count_read++;
			i_count--;
		}
		if (i_count_read > 0)
		{
			str_value = (char *)malloc(sizeof (char) * (i_count_read + 1));
			if (!str_value)
			{
				*error = 2;
				return ;
			}
			i_count_read = 0;
			i_count++;
			while (str[i_count] != ' ' && str[i_count] != '\t' && 
				str[i_count] != '\0')
				str_value[i_count_read++] = str[i_count++];
			str_value[i_count_read] = '\0';
			ft_add_arg(lst_ret, str_value, error);
			if (*error)
			{
				printf ("error %i\n", *error);
				lst_tmp = NULL;
				ft_throw_error (*error, lst_ret, &lst_tmp);
			}
			free(str_value);
			i_count = i_count - i_count_read;
		}
		i_count--;
	}
	return ;
}

//Fill the list 
t_stack	*ft_lst_fill_arg(int argc, char **arg)
{
	t_stack	*lst_ret;
	t_stack *lst_tmp;
	int		i_count;
	int		error;

	i_count = argc;
	lst_ret = NULL;
	if (argc == 2)
		ft_split_arg(&lst_ret, arg[i_count - 1], &error);
	else
	{
		while (i_count <= argc && i_count > 1)
		{
			ft_add_arg(&lst_ret, arg[i_count - 1], &error);
			if (error)
			{
				lst_tmp = NULL;
				ft_throw_error (error, &lst_ret, &lst_tmp);
			}
			i_count--;	
		}
	}
	return (lst_ret);
}

//check Arguments > 2 
t_stack	*ft_read_arg(int argc, char **arg)
{
	t_stack	*lst_ret;
	t_stack *lst_tmp;

	if (argc < 2)
	{
		lst_ret = NULL;
		lst_tmp = NULL;
		ft_throw_error(-100, &lst_ret, &lst_tmp);
	}
	lst_ret = ft_lst_fill_arg(argc, arg);
	ft_check_double(lst_ret);
	return (lst_ret);
}
