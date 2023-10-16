/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_sort_3_pushback.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:38:10 by rkost             #+#    #+#             */
/*   Updated: 2023/10/16 11:11:11 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	ft_pushback_to_a(t_stack **stack_a, t_stack **stack_b, 
					int i_pos, int *error);
static	int	ft_both_negativ(t_stack **stack_a, t_stack **stack_b,
					int diff, int coast);
static	int	ft_both_positv(t_stack **stack_a, t_stack **stack_b, int diff,
					int coast);
static	int	ft_both_different(t_stack **stack_a, t_stack **stack_b,
					int diff, int coast);

// Pruefe index b und sort ein 
int	ft_sort_back(t_stack **stack_a, t_stack **stack_b, int *error)
{
	int	i_pos;
	int	i_count;

	i_pos = 0;
	i_count = 0;
	while ((*stack_b))
	{
		i_pos = ft_callculate_rotate_stack_b(stack_a, stack_b);
		ft_pushback_to_a(stack_a, stack_b, i_pos, error);
		i_count = i_count + i_pos + 1;
	}
	return (i_count);
}

static	void	ft_pushback_to_a(t_stack **stack_a, t_stack **stack_b,
			int i_pos, int *error)
{
	t_stack	*lst_tmp;

	lst_tmp = *stack_b;
	while (lst_tmp)
	{
		if (i_pos == (lst_tmp->max_coast))
		{
			if (lst_tmp ->diff <= 0 && lst_tmp ->coast <= 0)
				*error = ft_both_negativ(stack_a, stack_b,
						lst_tmp ->diff, lst_tmp ->coast);
			else if (lst_tmp ->diff >= 0 && lst_tmp ->coast >= 0)
				*error = ft_both_positv(stack_a, stack_b,
						lst_tmp ->diff, lst_tmp ->coast);
			else
				*error = ft_both_different(stack_a, stack_b,
						lst_tmp ->diff, lst_tmp ->coast);
			break ;
		}
		lst_tmp = lst_tmp ->next;
	}
	ft_pa(stack_a, stack_b, error);
}

static	int	ft_both_negativ(t_stack **stack_a, t_stack **stack_b,
			int diff, int coast)
{
	int	i_tmp;
	int	error;

	error = 0;
	if (diff <= coast)
	{
		i_tmp = coast;
		while (i_tmp++ < 0)
			ft_rrr(stack_a, stack_b, &error);
		i_tmp = diff + (coast * (-1));
		while (i_tmp++ < 0)
			ft_rra(stack_a, &error);
	}
	else
	{
		i_tmp = diff;
		while (i_tmp++ < 0)
			ft_rrr(stack_a, stack_b, &error);
		i_tmp = coast + (diff * (-1));
		while (i_tmp++ < 0)
			ft_rrb(stack_b, &error);
	}
	return (error);
}

static	int	ft_both_positv(t_stack **stack_a, t_stack **stack_b,
			int diff, int coast)
{
	int	i_tmp;
	int	error;

	error = 0;
	if (diff >= coast)
	{
		i_tmp = coast;
		while (i_tmp-- > 0)
			ft_rr(stack_a, stack_b, &error);
		i_tmp = diff - coast;
		while (i_tmp-- > 0)
			ft_ra(stack_a, &error);
	}
	else
	{
		i_tmp = diff;
		while (i_tmp-- > 0)
			ft_rr(stack_a, stack_b, &error);
		i_tmp = coast - diff;
		while (i_tmp-- > 0)
			ft_rb(stack_b, &error);
	}
	return (error);
}

static	int	ft_both_different(t_stack **stack_a, t_stack **stack_b,
			int diff, int coast)
{
	int	i_tmp;
	int	error;

	error = 0;
	if (coast <= 0)
	{
		i_tmp = coast;
		while (i_tmp++ < 0)
			ft_rrb(stack_b, &error);
		i_tmp = diff;
		while (i_tmp-- > 0)
			ft_ra(stack_a, &error);
	}
	else
	{
		i_tmp = coast;
		while (i_tmp-- > 0)
			ft_rb(stack_b, &error);
		i_tmp = diff;
		while (i_tmp++ < 0)
			ft_rra(stack_a, &error);
	}
	return (error);
}
