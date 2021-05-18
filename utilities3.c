/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:42:16 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/18 14:45:53 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

int		nmove_totop(t_stack *stack, int stack_i, int flag)
{
	if (stack->length == 0)
		return (0);
	//rotate
	if (flag)
		return (stack->length - stack_i - 1);
	//reverse rotate
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

int		find_min_greater(t_stack *stack, int value)
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

int		find_max_minor(t_stack *stack, int value)
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