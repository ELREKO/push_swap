/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_sort_2_1_callculate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:35:06 by rkost             #+#    #+#             */
/*   Updated: 2023/10/16 10:37:25 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// it belongs to "ft_finde_best_choise_stack_a" 
// but ther was 2 lines to much for norminette 
int	ft_callculate_rotataion_a(int i_size, int i_count, int i_tmp)
{
	int	i_ret;

	if ((i_tmp < 0) && (i_count < (i_size / 2)))
		i_ret = i_count;
	else if ((i_tmp < 0) && (i_count >= (i_size / 2)))
		i_ret = (i_count - i_size);
	else if ((i_tmp > 0) && (i_count < (i_size / 2)))
		i_ret = i_count + 1;
	else if ((i_tmp > 0) && (i_count >= (i_size / 2)))
		i_ret = (i_count - i_size) + 1;
	return (i_ret);
}
