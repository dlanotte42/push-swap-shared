/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:43:34 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/15 11:51:01 by gcarbone         ###   ########.fr       */
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
#endif