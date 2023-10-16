/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_sort_2_0_callculate.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:07:26 by rkost             #+#    #+#             */
/*   Updated: 2023/10/16 10:32:19 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_finde_best_choise_stack_a(t_stack **stack_A, int index);
static int	ft_find_lowest_differnc_stack_a(t_stack **stack_a, int index);
static void	ft_callculate_max_coast(t_stack **stack_b);
static int	ft_find_best_choise(t_stack **stack_b);

// set in stack B the coast for rotating in front
// -> in "diff" die guenstigsten Kosten aus Stack A gespeichert!
// -> in "coast" die Schritte fuer die Rotation an die push position 
// -> in "max_coast" wird die Differnce zwichen den beiden gespeichert
int	ft_callculate_rotate_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*lst_tmp;
	int		i_count;
	int		i_size;

	i_size = ft_lstsize(*stack_b);
	lst_tmp = *stack_b;
	i_count = 0;
	while (lst_tmp)
	{
		lst_tmp ->diff = ft_finde_best_choise_stack_a(stack_a, lst_tmp ->index);
		if (i_count < (i_size / 2) || i_size == 1)
			lst_tmp ->coast = i_count;
		else
			lst_tmp ->coast = i_count - i_size;
		lst_tmp = lst_tmp ->next;
		i_count++;
	}
	return (ft_find_best_choise(stack_b));
}

// search next postion in stack A-> "return" the lowast 
// coast to bring Stack_A in Postion for pushing form B 
// with the given index
static	int	ft_finde_best_choise_stack_a(t_stack **stack_a, int index)
{
	t_stack	*lst_tmp;
	int		i_count;
	int		i_tmp;
	int		i_size;

	i_count = 0;
	i_tmp = ft_find_lowest_differnc_stack_a(stack_a, index);
	i_size = ft_lstsize(*stack_a);
	lst_tmp = *stack_a;
	while (lst_tmp)
	{
		if (i_tmp == index - (lst_tmp ->index))
		{
			i_tmp = ft_callculate_rotataion_a(i_size, i_count, i_tmp);
			break ;
		}
		lst_tmp = lst_tmp ->next;
		i_count++;
	}
	return (i_tmp);
}

// berechne die geringste Differnz zum index 
static	int	ft_find_lowest_differnc_stack_a(t_stack **stack_a, int index)
{
	t_stack	*lst_tmp;
	int		i_max;
	int		i_min;
	int		i_tmp;

	i_max = 2147483647;
	i_min = -2147483648;
	lst_tmp = *stack_a;
	while (lst_tmp)
	{
		i_tmp = index - (lst_tmp ->index);
		if (i_tmp <= 0 && i_tmp > i_min)
			i_min = i_tmp;
		if (i_tmp > 0 && i_tmp < i_max)
			i_max = i_tmp;
		lst_tmp = lst_tmp ->next;
	}
	if ((i_min * (-1)) < i_max && i_min != -2147483648)
		i_max = i_min;
	return (i_max);
}

// return the minmal coast wehre you could search for
static	void	ft_callculate_max_coast(t_stack **stack_b)
{
	t_stack	*lst_tmp;

	lst_tmp = *stack_b;
	while (lst_tmp)
	{
		if (lst_tmp ->diff <= 0 && lst_tmp ->coast <= 0)
		{
			if (lst_tmp->coast <= lst_tmp->diff)
				lst_tmp ->max_coast = (lst_tmp ->coast) * (-1);
			else
				lst_tmp ->max_coast = (lst_tmp ->diff * (-1));
		}
		else if (lst_tmp ->diff >= 0 && lst_tmp ->coast >= 0)
		{
			if ((lst_tmp->coast >= lst_tmp->diff))
				lst_tmp ->max_coast = lst_tmp -> coast;
			else
				lst_tmp ->max_coast = lst_tmp ->diff;
		}
		else if (lst_tmp ->diff < 0)
			lst_tmp -> max_coast = (lst_tmp ->diff * (-1)) + (lst_tmp ->coast);
		else
			lst_tmp -> max_coast = (lst_tmp ->coast * (-1)) + (lst_tmp ->diff);
		lst_tmp = lst_tmp ->next;
	}
}

static	int	ft_find_best_choise(t_stack **stack_b)
{
	t_stack	*lst_tmp;
	int		i_min;

	ft_callculate_max_coast(stack_b);
	lst_tmp = *stack_b;
	i_min = 2147483647;
	while (lst_tmp)
	{
		if (lst_tmp ->max_coast < i_min)
			i_min = lst_tmp ->max_coast;
		lst_tmp = lst_tmp ->next;
	}
	return (i_min);
}
