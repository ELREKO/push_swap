/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:29:30 by rkost             #+#    #+#             */
/*   Updated: 2023/10/16 13:32:36 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// to give the integer of steps use
// --> AFTER LINE 30 "ft_str_print(str_tmp)";
// to sehe the sortete list use
// --> AFTER LINE 30 "ft_lst_print(stack_a);"
int	main(int argc, char **arg)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str_tmp;

	stack_b = 0;
	stack_a = ft_read_arg(argc, arg);
	ft_set_index(&stack_a);
	if (ft_lstsize(stack_a) < 4)
		str_tmp = ft_itoa(ft_sort_three(&stack_a, &stack_b));
	else
		str_tmp = ft_itoa(ft_big_sort(&stack_a, &stack_b));
	free(str_tmp);
	ft_free_lst(stack_a);
	ft_free_lst(stack_b);
}
