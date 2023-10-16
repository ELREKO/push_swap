/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_copy.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:38:51 by rkost             #+#    #+#             */
/*   Updated: 2023/10/16 14:03:39 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack 
{
	int	value;
	int	index;
	int	diff;
	int	coast;
	int	direction;
	int	max_coast;
	struct	s_stack	*next;
}	t_stack;

void	ft_free_lst(t_stack *lst);
void	ft_throw_error(int errNum, t_stack **lst_a, t_stack **lst_b);
void	ft_throw_error_ft_arg(t_stack **lst_ret, int error);
t_stack	*ft_read_arg(int argc, char **arg);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lastlst(t_stack *lst);
t_stack	*ft_lst_new(int value, int index, int diff, int *error);
void	ft_lst_add_front(t_stack **lst_mod, t_stack *lst_front);
void	ft_lst_del_front(t_stack **lst_mod);
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int *error);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int *error);
void	ft_rra(t_stack **stack_a, int *error);
void	ft_rrb(t_stack **stack_b, int *error);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int *error);
void	ft_ra(t_stack **stack_a, int *error);
void	ft_rb(t_stack **stack_a, int *error);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int *error);
void	ft_sa(t_stack **stack_a, int *error);
void	ft_sb(t_stack **stack_b, int *error);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int *error);
void	ft_set_index(t_stack **stack_a);
int		ft_big_sort(t_stack **stack_a, t_stack **stack_b);
int		ft_callculate_rotate_stack_b(t_stack **stack_a, t_stack **stack_b);
int		ft_callculate_rotataion_a(int i_size, int i_count, int i_tmp);
int		ft_sort_back(t_stack **stack_a, t_stack **stack_b, int *error);
int		ft_rotate_first_positon(t_stack **stack_a, int *error);
int		ft_sort_three(t_stack **stack_a, t_stack **stack_b);
int		ft_char_nbr(char *str, int *error, int i_len);
int		ft_check_on_nbr(char *str, int *error);
void	ft_lst_print(t_stack *lst);
int		ft_check_range(t_stack *stack_a);
void	ft_str_print(char *str);
int		ft_strlen(char *str);
void	ft_check_double_value_lst(t_stack *lst);
char	*ft_itoa(int n);

#endif
