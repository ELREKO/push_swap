/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:38:40 by rkost             #+#    #+#             */
/*   Updated: 2023/10/09 12:40:51 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// find and set the heigest index
static void	ft_set_high_index(t_stack **stack_a, int *i_max, int *i_size);

void    ft_set_index(t_stack **stack_a)
{
    t_stack *lst_tmp;
    t_stack *lst_cmp;
    int i_max;
    int i_size;

    i_size = ft_lstsize(*stack_a);
    while (i_size > 0)
    {
        i_max = -2147483648;
        ft_set_high_index(stack_a, &i_max, &i_size);
        i_size--;    
    }
}

static void	ft_set_high_index(t_stack **stack_a, int *i_max, int *i_size)
{
	t_stack	*lst_tmp;
	t_stack	*lst_head;

	lst_tmp = *stack_a;
	lst_head = lst_tmp;
	while (lst_tmp ->next != NULL)
	{
		if (*i_max < lst_tmp ->value && lst_tmp ->index == 0)
			*i_max = lst_tmp ->value;
		lst_tmp = lst_tmp ->next;
	}
	lst_tmp = *stack_a;
	while (lst_tmp ->value != *i_max && lst_tmp ->next != NULL)
		lst_tmp = lst_tmp ->next;
	lst_tmp ->index = *i_size;
	*stack_a = lst_head;
}



