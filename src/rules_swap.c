/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:09:27 by rkost             #+#    #+#             */
/*   Updated: 2023/10/06 18:40:03 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	ft_swap(t_stack **stack, int *error);

void	ft_sa(t_stack **stack_a, int *error)
{
	if (ft_lstsize(*stack_a) < 2)
		*error = 4;
	else
	{
		write(1, "sa\n", 3);
		ft_swap(stack_a, error);
	}
}

void	ft_sb(t_stack **stack_b, int *error)
{
	if (ft_lstsize(*stack_b) < 2)
		*error = 4;
	else
	{
		write(1, "sb\n", 3);
		ft_swap(stack_b, error);
	}
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int *error)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		*error = 4;
	else
	{
		write(1, "ss\n", 3);
		ft_swap(stack_a, error);
		ft_swap(stack_b, error);
	}
}

static	void	ft_swap(t_stack **stack, int *error)
{
	t_stack	*lst_head;
	t_stack	*lst_next;
	t_stack	*lst_tmp;

	lst_tmp = *stack;
	lst_head = ft_lst_new(lst_tmp ->value, lst_tmp ->index, 
			lst_tmp ->diff, lst_tmp ->coast, lst_tmp ->direction, error);
	lst_tmp = lst_tmp ->next;
	lst_next = ft_lst_new(lst_tmp ->value, lst_tmp ->index, 
			lst_tmp ->diff, lst_tmp ->coast, lst_tmp ->direction, error);
	lst_tmp = *stack;
	lst_tmp ->value = lst_next ->value;
	lst_tmp ->index = lst_next ->index;
	lst_tmp ->diff = lst_next ->diff;
	lst_tmp = lst_tmp ->next;
	ft_free_lst(lst_next);
	lst_tmp ->value = lst_head ->value;
	lst_tmp ->index = lst_head ->index;
	lst_tmp ->diff = lst_head ->diff;
	ft_free_lst(lst_head);
}

// !!!! Don't delete !!!! it is for revesr sort 

// // changed the list reverse of the size you want! 
// static	void	ft_revers(t_stack **stack, int i_rever_size, int *error)
// {
// 	t_stack	*lst_tmp[i_rever_size + 1];
// 	int		i_count;

// 	lst_tmp[0] = *stack;
// 	i_count = 1;
// 	while (i_count <= i_rever_size)
// 	{
// 		lst_tmp[i_count++] = ft_lst_new(lst_tmp[0] ->value, lst_tmp[0] ->index, 
// 			lst_tmp[0] ->diff, error);
// 		lst_tmp[0] = lst_tmp[0]->next;
// 	}
// 	i_count--;
// 	lst_tmp[0] = *stack;
// 	while (i_count >= 1)
// 	{
// 		lst_tmp[0] ->value = lst_tmp[i_count] ->value;
// 		lst_tmp[0] ->index = lst_tmp[i_count] ->index;
// 		lst_tmp[0] ->diff = lst_tmp[i_count] ->diff;
// 		lst_tmp[0] = lst_tmp[0] ->next;
// 		ft_free_lst(lst_tmp[i_count--]);
// 	}
// }
