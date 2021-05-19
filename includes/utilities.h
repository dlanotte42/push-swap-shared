/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:43:34 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/19 10:59:33 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H
# include "main.h"

t_ps	*check_args(int argc, char **argv, int *res);
void	remove_ps(t_ps *ps);
int		pop(t_stack *stack);
void	push(t_stack *stack, int value);
void	reverse(t_list	*node, t_list **first, t_list **last);
void	print_stacks(t_stack *a, t_stack *b, char *str);
int		ft_table_len(char **table);
int		fval_index(int *arr, int len, int val);
int		find_min_greater(t_stack *stack, int value);
int		find_max_minor(t_stack *stack, int value);
int		nmove_totop(t_stack *stack, int stack_i, int flag);
void	move_to_top(t_stack *stack, int stack_i);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
t_ps	*init_ps(int size);
char	**get_args(int *argc, char **argv);
void	free_table(char **table);
int		ft_is_yet_sorted(t_ps *ps);
#endif