/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:45:09 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/12 14:15:41 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES2_H
# define UTILITIES2_H
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int		val;
	struct	s_list	*next;
}				t_list;

typedef struct s_seq
{
	int	stack_i;
	int	length;
}				t_seq;

typedef struct s_stack
{
	t_list	*first;
	t_list	*last;
	t_seq	**sequences;
	int		*sorted;
	int		*arr;
	int		*arr2;
	int		length;
	int		left;
	int		right;
	int		n_ok;
	int		pivot;
	int		ipivot;
	int		pos;
	int		n_seq;
}				t_stack;

typedef struct s_ps
{
	int		size;
	t_stack	a;
	t_stack	b;
	int		*sorted;
}				t_ps;

void	reverse(t_list	*node, t_list **first, t_list **last);
void	print_stacks(t_stack *a, t_stack *b, char *str);
void	ft_sort_sequences(t_seq **tab, int size);
#endif