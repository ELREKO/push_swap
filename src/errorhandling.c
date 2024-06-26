/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:06:49 by rkost             #+#    #+#             */
/*   Updated: 2023/10/16 09:46:01 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// free the list
void	ft_free_lst(t_stack *lst)
{
	t_stack	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	lst = NULL;
}

// becouse i could not have more than 25 lines per function 
// i have to read this short function
void	ft_throw_error_ft_arg(t_stack **lst_ret, int error)
{
	t_stack	*lst_tmp;

	lst_tmp = NULL;
	ft_throw_error(error, lst_ret, &lst_tmp);
}

void	ft_throw_error(int errNum, t_stack **lst_a, t_stack **lst_b)
{
	if ((*lst_a) != NULL)
		ft_free_lst(*lst_a);
	if ((*lst_b) != NULL)
		ft_free_lst(*lst_b);
	if (errNum < 100)
		write(1, "ERROR\n", 6);
	exit (0);
}
// // Error handling
// // - Errror till 3 a errors for init
// void	ft_throw_error(int errNum, t_stack **lst_a, t_stack **lst_b)
// {
// 	if ((*lst_a) != NULL)
// 		ft_free_lst(*lst_a);
// 	if ((*lst_b) != NULL)
// 		ft_free_lst(*lst_b);
// 	if (errNum == -100)
// 	{
// 		write(1, "ERROR\n", 6);
// 		write(1, "-- nothing to sort --\n", 22);
// 	}
// 	if (errNum == 1)
// 	{
// 		write(1, "ERROR\n", 6);
// 		write(1, "-- malloc lst --\n", 17);
// 	}
// 	if (errNum == 2)
// 	{
// 		write(1, "ERROR\n", 6);
// 		write(1, "-- no integer --\n", 17);
// 	}
// 	if (errNum == 3)
// 	{
// 		write(1, "ERROR\n", 6);
// 		write(1, "-- dbl integer --\n", 18);
// 	}
// 	if (errNum == 4)
// 	{
// 		write(1, "ERROR\n", 6);
// 		write(1, "-- swap stack lower 2--\n", 25);
// 	}
// 	if (errNum == 5)
// 	{
// 		write(1, "ERROR\n", 6);
// 		write(1, "-- Push stack is Empty --\n", 26);
// 	}
// 	if (errNum == 6)
// 	{
// 		write(1, "ERROR\n", 6);
// 		write(1, "-- noting to rotate --\n", 24);
// 	}
// 	write(1, "EXIT - PROGRAMM\n", 16);
// 	printf("error %i\n",errNum); 
// 	exit (0);
// }
