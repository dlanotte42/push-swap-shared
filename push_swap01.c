/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:38:33 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:36:18 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

static int	get_min_support(int *type, int nmoves[4])
{
	*type = 0;
	if (nmoves[1] < nmoves[0])
	{
		*type = 1;
		nmoves[0] = nmoves[1];
	}
	if (nmoves[2] < nmoves[0])
	{
		*type = 2;
		nmoves[0] = nmoves[2];
	}
	if (nmoves[3] < nmoves[0])
	{
		*type = 3;
		nmoves[0] = nmoves[3];
	}
	return (nmoves[0]);
}

int 	getnchunk(t_ps *ps, int value, int chunk_size)
{
	int	index;
	int	flag;
	int	base;
	int	i;

	flag = 0;
	index = fval_index(ps->sorted, ps->size, value);
	if (ps->rest)
	{
		flag = 1;
		base = (chunk_size * ps->rest) + ps->rest;
		i = (index >= base) * (ps->rest);
		if (i)
			return (i + ((index - base) / chunk_size));
	}
	return (index / (chunk_size + flag));
}

int	where_put_in_stack(t_stack *stack, int value, int asc)
{
	int	stack_i;

	stack_i = stack->length - 1;
	if (stack->length == 0)
		return (0);
	if (asc)
	{
		stack_i = find_min_greater(stack, value);
		if (stack_i == -1)
			stack_i = find_min(stack);
	}
	else
	{
		stack_i = find_max_minor(stack, value);
		if (stack_i == -1)
			stack_i = find_max(stack);
	}
	return (stack_i);
}

int	best_choice(t_ps *ps, int nchunk, int chunk_size, int *index)
{
	int	moves1;
	int	moves2;
	int	ichunk;
	int	type;
	int	index2;

	if (*index < 0)
		return (-1);
	index2 = *index - 1;
	moves2 = best_choice(ps, nchunk, chunk_size, &index2);
	ichunk = getnchunk(ps, ps->a.arr[*index], chunk_size);
	moves1 = moves2;
	if (ichunk == nchunk)
	{
		moves1 = get_min_move(ps, &type, *index, 0);
		if (index2 == -1)
			moves2 = moves1 + 1;
	}
	if (moves2 <= moves1)
	{
		*index = index2;
		return (moves2);
	}
	return (moves1);
}

//0 - ra-rb, 1 - ra-rrb, 2 - rra-rb, 3 - rra-rrb
//ra-rb, ra-rrb, rra-rb, rra-rrb
int	get_min_move(t_ps *ps, int *type, int from, int flag)
{
	int		move;
	int		to;
	t_stack	*first;
	t_stack	*second;
	int		nmoves[4];

	first = &ps->a;
	second = &ps->b;
	if (flag)
	{
		first = &ps->b;
		second = &ps->a;
	}
	to = where_put_in_stack(second, first->arr[from], flag);
	nmoves[0] = nmove_totop(first, from, 1);
	move = nmove_totop(second, to, 1);
	if (move > nmoves[0])
		nmoves[0] = move;
	nmoves[3] = nmove_totop(first, from, 0);
	move = nmove_totop(second, to, 0);
	if (move > nmoves[3])
		nmoves[3] = move;
	nmoves[1] = nmove_totop(first, from, 1) + nmove_totop(second, to, 0);
	nmoves[2] = nmove_totop(first, from, 0) + nmove_totop(second, to, 1);
	return (get_min_support(type, nmoves));
}
