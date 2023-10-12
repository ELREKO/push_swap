/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate_fw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:44:33 by rkost             #+#    #+#             */
/*   Updated: 2023/10/07 14:53:00 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	ft_rotate_forw(t_stack **lst, int *error);

void	ft_ra(t_stack **stack_a, int *error)
{
	if (ft_lstsize(*stack_a) < 1)
		*error = 6;
	else
	{
		write(1, "ra\n", 3);
		ft_rotate_forw(stack_a, error);
	}
}

void	ft_rb(t_stack **stack_b, int *error)
{
	if (ft_lstsize(*stack_b) < 1)
		*error = 6;
	else
	{
		write(1, "rb\n", 3);
		ft_rotate_forw(stack_b, error);
	}
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int *error)
{
	if (ft_lstsize(*stack_a) < 1 || ft_lstsize(*stack_b) < 1)
		*error = 6;
	else
	{
		write(1, "rr\n", 3);
		ft_rotate_forw(stack_a, error);
		ft_rotate_forw(stack_b, error);
	}
}

// forward rotating 
static	void	ft_rotate_forw(t_stack **lst, int *error)
{
	t_stack	*lst_tmp;
	t_stack	*lst_tail;
	t_stack	*lst_head;

	lst_tmp = *lst;
	lst_tail = ft_lst_new((*lst)->value, (*lst)->index,
			(*lst)->diff, (*lst)->coast, (*lst)->direction, error);
	*lst = (*lst)->next;
	free(lst_tmp);
	lst_head = *lst;
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	(*lst)->next = lst_tail;
	*lst = lst_head; 
}
