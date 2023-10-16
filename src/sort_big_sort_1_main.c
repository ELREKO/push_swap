/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_sort_1_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:03:32 by rkost             #+#    #+#             */
/*   Updated: 2023/10/15 19:06:51 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_push_to_stack_b(t_stack **stack_a, t_stack **stack_b,
				int *i_error);

// it push all to stack_b let a rest from 3 values in stack_a
// - Sort the last 3 in stack_
// - Callculate the shortest steps for pushing back to stack_a 
// from stack_b --> Callculate the maximum Step for each value in
// stack_b to move back in stack_a in the right way! 
// for callculate using a index to callculate a differce
// Than push back the Value with lowest steps! 
int	ft_big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i_count;
	int	i_err;

	i_err = 0;
	i_count = 0;
	i_count = ft_push_to_stack_b(stack_a, stack_b, &i_err);
	if (i_err != 0)
		ft_throw_error(i_err, stack_a, stack_b);
	i_count = i_count + ft_sort_three(stack_a, stack_b);
	i_count = i_count + ft_sort_back(stack_a, stack_b, &i_err);
	if (i_err != 0)
		ft_throw_error(i_err, stack_a, stack_b);
	i_count = i_count + ft_rotate_first_positon(stack_a, &i_err);
	if (i_err != 0)
		ft_throw_error(i_err, stack_a, stack_b);
	return (i_count);
}

// Alle bis auf 3 nach Stack B Scheiben 
static int	ft_push_to_stack_b(t_stack **stack_a, t_stack **stack_b, int *error)
{
	int	i_size;
	int	i_count;

	i_size = ft_lstsize(*stack_a);
	i_count = 0;
	while (i_size-- > 3)
	{
		ft_pb(stack_a, stack_b, error);
		i_count++;
	}
	return (i_count);
}
