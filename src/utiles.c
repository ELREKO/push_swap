/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:54:14 by rkost             #+#    #+#             */
/*   Updated: 2023/10/05 20:14:55 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// Private function
static	int	ft_pow_b_10(int pow);

//Changing the given String to a Nummber
int	ft_char_nbr(char *str, int *error, int i_len)
{
	int		i_count;
	long	i_ret;
	int		i_sign;

	i_count = 0;
	i_ret = 0;
	i_sign = 0;
	if (str[i_count] == '-')
	{
		i_sign++;
		i_count++;
		i_len--;
	}
	if (i_len > 10)
		*error = 1;
	while (i_len > 0)
	{
		i_ret = i_ret + ((str[i_count++] - 48) * ft_pow_b_10(i_len--));
		if ((i_sign && (i_ret > 2147483648)) || 
			((!i_sign) && (i_ret > 2147483647)))
			*error = 2;
	}
	if (i_sign)
		i_ret *= (-1);
	return (i_ret);
}

//Pruefen auf Fehler 
//- es eine Zahl ist!
//- es groeser als int ist!
int	ft_check_on_nbr(char *str, int *error)
{
	int		i_count;

	i_count = 0;
	while (str[i_count] != '\0')
	{
		if (str[0] != '-' && (str[0] < 48 || str[0] > 57))
		{
			if ((str[i_count] < 48 || str[i_count] > 57))
			{
				*error = 2;
				return (0);
			}
		}
		i_count++;
	}
	*error = 0;
	return (i_count);
}

// print from int lst
void	ft_lst_print(t_stack *lst)
{
	while (lst->next != NULL)
	{
		printf("Value: |%i| -- index |%i| -- isNum: |%i|\n",
			lst->value, lst->index, lst->isNum);
		lst = lst->next;
	}
	printf("Value: |%i| -- index |%i| -- isNum: |%i|\n",
		lst->value, lst->index, lst->isNum);
}

// Erzeugen der Zehnerpotenz
static	int	ft_pow_b_10(int pow)
{
	int	i_ret; 

	i_ret = 1;
	while (pow > 1)
	{
		i_ret = i_ret * 10;
		pow--;
	}
	return (i_ret);
}
