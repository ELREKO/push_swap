/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:29:31 by rkost             #+#    #+#             */
/*   Updated: 2023/10/07 13:32:01 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	ft_push(t_stack **lst_src, t_stack **lst_dest, int *error);

void	ft_pa(t_stack **stack_a, t_stack **stack_b, int *error)
{
	if (!(*stack_b))
		*error = 5;
	else
	{
		write(1, "pa\n", 3);
		ft_push(stack_b, stack_a, error);
	}
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, int *error)
{
	if (!(*stack_a))
		*error = 5;
	else
	{
		write(1, "pb\n", 3);
		ft_push(stack_a, stack_b, error);
	}
}

static	void	ft_push(t_stack **lst_src, t_stack **lst_dest, int *error)
{
	t_stack	*lst_tmp_src;
	//t_stack *lst_tmp_dest;
	t_stack	*lst_tmp_front;

	lst_tmp_src = *lst_src;
	//lst_tmp_dest = *lst_dest;
	lst_tmp_front = ft_lst_new(lst_tmp_src->value, lst_tmp_src->index,
			lst_tmp_src->diff, lst_tmp_src ->coast, lst_tmp_src ->direction, error);
	if (lst_dest == NULL || *lst_dest == NULL)
		*lst_dest = lst_tmp_front;
	else
		ft_lst_add_front(lst_dest, lst_tmp_front);
	ft_lst_del_front(lst_src);
}
