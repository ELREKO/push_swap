/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate_bw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:32:38 by rkost             #+#    #+#             */
/*   Updated: 2023/10/07 14:44:06 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	ft_rotate_backw(t_stack **lst);

void	ft_rra(t_stack **stack_a, int *error)
{
	if (ft_lstsize(*stack_a) < 1)
		*error = 6;
	else
	{
		write(1, "rra\n", 4);
		ft_rotate_backw(stack_a);
	}
}

void	ft_rrb(t_stack **stack_b, int *error)
{
	if (ft_lstsize(*stack_b) < 1)
		*error = 6;
	else
	{
		write(1, "rrb\n", 4);
		ft_rotate_backw(stack_b);
	}
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int *error)
{
	if (ft_lstsize(*stack_a) < 1 || ft_lstsize(*stack_b) < 1)
		*error = 6;
	else
	{
		write(1, "rrr\n", 4);
		ft_rotate_backw(stack_a);
		ft_rotate_backw(stack_b);
	}
}

// backward rotating
static	void	ft_rotate_backw(t_stack **lst)
{
	t_stack	*lst_tmp_head;
	t_stack	*lst_tmp_ret;
	t_stack	*lst_tmp;
	int		i_count;
	int		i_size;

	lst_tmp = *lst;
	i_size = ft_lstsize(lst_tmp);
	lst_tmp_head = ft_lastlst(*lst);
	lst_tmp_ret = lst_tmp;
	i_count = 1;
	while (i_size > i_count)
	{
		if (i_count + 1 == i_size)
			lst_tmp -> next = NULL;
		else
			lst_tmp = lst_tmp -> next;
		i_count++;
	}
	lst_tmp_head ->next = lst_tmp_ret;
	*lst = lst_tmp_head;
}
