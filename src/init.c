/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:00:05 by rkost             #+#    #+#             */
/*   Updated: 2023/10/16 13:36:34 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	t_stack	*ft_lst_fill_arg(int argc, char **arg);
static	void		ft_split_arg(t_stack **lst_ret, char *str, int *error);
static	char		*ft_read_int_from_sting(int i_count_read, int i_count, 
					char *str, int *error);
static	int		ft_add_arg(t_stack **lst, char *str, int *error);

//check Arguments < 2 
t_stack	*ft_read_arg(int argc, char **arg)
{
	t_stack	*lst_ret;
	t_stack	*lst_tmp;

	if (argc < 2)
	{
		lst_ret = NULL;
		lst_tmp = NULL;
		ft_throw_error(-100, &lst_ret, &lst_tmp);
	}
	lst_ret = ft_lst_fill_arg(argc, arg);
	ft_check_double_value_lst(lst_ret);
	return (lst_ret);
}

//Fill one list 
// - if the sting as one Argument given " ARG"1 2 3"; ./push_swap $ARG " 
//      --> go to split the Arg 'ft_split_arg' 
// - else read each arg[i] using a while 
static t_stack	*ft_lst_fill_arg(int argc, char **arg)
{
	t_stack	*lst_ret;
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
				ft_throw_error_ft_arg(&lst_ret, error);
			i_count--;
		}
	}
	return (lst_ret);
}

// If the sting as one Argument given " ARG"1 2 3"; ./push_swap $ARG " 
// 	--> go to split the Arg 'ft_split_arg' 
// - Read the Sting revers 
// - count the leng of the Nummer in the Sting 
static void	ft_split_arg(t_stack **lst_ret, char *str, int *error)
{
	int		i_count;
	int		i_count_read;
	char	*str_value;

	i_count = ft_strlen(str) - 1;
	while (i_count >= 0)
	{
		i_count_read = 0;
		while (str[i_count] != ' ' && str[i_count] != '\t'
			&& str[i_count] != '\0')
		{
			i_count_read++;
			i_count--;
		}
		if (i_count_read > 0)
		{
			str_value = ft_read_int_from_sting(i_count_read,
					i_count, str, error);
			ft_add_arg(lst_ret, str_value, error);
			if (*error)
			{
				free(str_value);
				ft_throw_error_ft_arg(lst_ret, *error);
			}
		}
		i_count--;
	}
}

// Belongs to "ft_split arg"
// - Read the Nummber as char -- convert to integer
static char	*ft_read_int_from_sting(int i_count_read, int i_count, 
		char *str, int *error)
{
	char	*str_value;

	str_value = malloc(sizeof (char) * (i_count_read + 1));
	if (!str_value)
	{
		*error = 2;
		return (NULL);
	}
	i_count_read = 0;
	i_count++;
	while (str[i_count] != ' ' && str[i_count] != '\t' && str[i_count] != '\0')
		str_value[i_count_read++] = str[i_count++];
	str_value[i_count_read] = '\0';
	i_count = i_count - i_count_read;
	return (str_value);
}

// check an fill the list
static int	ft_add_arg(t_stack **lst, char *str, int *error)
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
