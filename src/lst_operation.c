/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:57:39 by rkost             #+#    #+#             */
/*   Updated: 2023/10/07 15:05:47 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// count the list element 
int	ft_lstsize(t_stack *lst)
{
	int	i_count;

	i_count = 0;
	while (lst)
	{
		lst = lst ->next;
		i_count++;
	}
	return (i_count);
}

// find last list sruct
t_stack	*ft_lastlst(t_stack *lst)
{
	t_stack	*lst_ret;

	lst_ret = lst;
	while (lst_ret ->next != NULL)
		lst_ret = lst_ret ->next;
	return (lst_ret);
}

// create a new lst node and fill 
t_stack	*ft_lst_new(int value, int index, int diff, int rotation, int direktion,  int *error)
{
	t_stack	*lst_ret;

	lst_ret = malloc(sizeof(t_stack));
	if (!lst_ret)
	{
		*error = 1;
		return (NULL);
	}
	lst_ret ->value = value;
	lst_ret ->index = index;
	lst_ret ->diff = diff;
	lst_ret ->coast = rotation;
	lst_ret ->direction = direktion;
	lst_ret ->next = NULL;
	return (lst_ret);
}

void	ft_lst_add_front(t_stack **lst_mod, t_stack *lst_front )
{
	lst_front -> next = *lst_mod;
	*lst_mod = lst_front;
}

void	ft_lst_del_front(t_stack **lst_mod)
{
	t_stack	*lst_tmp;

	lst_tmp = *lst_mod;
	*lst_mod = lst_tmp ->next;
	free(lst_tmp);
}
