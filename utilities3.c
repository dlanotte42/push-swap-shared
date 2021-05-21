/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:37:34 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:36:25 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

void	free_table(char **table)
{
	int	i;

	if (table)
	{
		i = ft_table_len(table);
		while (--i >= 0)
			free(table[i]);
		free(table);
	}
}

// if (flag == 0) {rotate} else reverse rotate
int	nmove_totop(t_stack *stack, int stack_i, int flag)
{
	if (stack->length == 0)
		return (0);
	if (flag)
		return (stack->length - stack_i - 1);
	return (stack_i + 1);
}

void	move_to_top(t_stack *stack, int stack_i)
{
	int	move;
	int	rotx;
	int	revx;

	rotx = nmove_totop(stack, stack_i, 1);
	revx = nmove_totop(stack, stack_i, 0);
	move = ((rotx <= revx) * rotx) + ((rotx > revx) * revx);
	while (move > 0)
	{
		if (rotx <= revx)
			rx(stack, 1);
		else
			rrx(stack, 1);
		move--;
	}
}

int	find_min_greater(t_stack *stack, int value)
{
	int	i;
	int	imin;

	i = -1;
	imin = -1;
	while (++i < stack->length)
	{
		if (stack->arr[i] > value)
		{
			if (imin == -1)
				imin = i;
			if (stack->arr[i] < stack->arr[imin])
				imin = i;
		}
	}
	return (imin);
}

int	find_max_minor(t_stack *stack, int value)
{
	int	i;
	int	index;

	i = -1;
	index = -1;
	while (++i < stack->length)
	{
		if (stack->arr[i] < value)
		{
			if (index == -1)
				index = i;
			if (stack->arr[i] > stack->arr[index])
				index = i;
		}
	}
	return (index);
}
