/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_sort_4_rotat_first_postion.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:12:00 by rkost             #+#    #+#             */
/*   Updated: 2023/10/16 11:19:56 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	ft_find_direction(t_stack **stack_a);

int	ft_rotate_first_positon(t_stack **stack_a, int *error)
{
	int	i_count;

	i_count = 0;
	if (ft_find_direction(stack_a))
	{
		while ((*stack_a)->index != 1)
		{
			ft_ra(stack_a, error);
			i_count++;
		}
	}
	else
	{
		while ((*stack_a)->index != 1)
		{
			ft_rra(stack_a, error);
			i_count++;
		}
	}
	return (i_count);
}

// return the way to rotat 
// -> 1 rotate forward --> ra
// -> 0 rotate backward --> rra
static	int	ft_find_direction(t_stack **stack_a)
{
	t_stack	*lst_tmp;
	int		i_count;
	int		i_size;

	lst_tmp = *stack_a;
	i_count = 0;
	while (lst_tmp)
	{
		if (lst_tmp ->index == 1)
			break ;
		lst_tmp = lst_tmp ->next;
		i_count++;
	}
	i_size = ft_lstsize(*stack_a);
	if (i_count < (i_size / 2))
		i_count = 1;
	else
		i_count = 0;
	return (i_count);
}
