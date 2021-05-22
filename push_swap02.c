/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:38:41 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/22 12:34:39 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

void 	sort2n(t_stack *stack)
{
	int	i;

	i = find_min(stack);
	if (i == 0)
		sx(stack, 1);
}

void 	sort3n(t_stack *stack)
{
	int	i;
	int	j;
	int	k;

	i = find_min(stack);
	j = find_min_greater(stack, stack->arr[i]);
	k = (stack->length + i - 1) % stack->length;
	if (k == j)
	{
		if (i == 1)
			rx(stack, 1);
		else if (i == 0)
			rrx(stack, 1);
	}
	else
	{
		sx(stack, 1);
		i = find_min(stack);
		if (i == 1)
			rx(stack, 1);
		else if (i == 0)
			rrx(stack, 1);
	}
}

void	sort10loop(t_stack *first, t_stack *second, int size)
{
	int	i;

	i = -1;
	if (size <= 1)
		return ;
	if (size == 2)
		sort2n(first);
	else if (size == 3)
		sort3n(first);
	else
	{
		move_to_top(first, find_min(first));
		px(second, first, 1);
		if (size > 4)
		{
			move_to_top(first, find_min(first));
			px(second, first, 1);
		}
		sort10loop(first, second, first->length);
		px(first, second, 1);
		if (size > 4)
			px(first, second, 1);
	}
}

/* 
	11 -> 500 numbers 
	5  -> 100 numbers
	0.015 = *((11-5)/400) 
*/

void 	set_limits(t_ps *ps, int *nchunk, int *chunk_size)
{
	if (ps->size <= 20)
		*nchunk = 1;
	else if (ps->size < 50)
		*nchunk = 2;
	else if (ps->size == 100)
		*nchunk = 1;
	else if (ps->size == 500)
		*nchunk = 1;
	else
	{
		*nchunk = 5 + (0.015 * (ps->size - 100));
	}
	*chunk_size = ps->size / *nchunk;
	ps->rest = ps->size % *chunk_size;
}
