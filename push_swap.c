/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:31:32 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/15 16:11:02 by gcarbone         ###   ########.fr       */
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

int	find_min_index(t_stack *stack)
{
	int	i;
	int	imin;
	int	min;

	if (stack->length == 0)
		return (0);
	min = stack->arr[0];
	i = -1;
	imin = 0;
	while (++i < stack->length)
	{
		if (stack->arr[i] < min)
		{
			imin = i;
			min = stack->arr[i];
		}
	}
	return (imin);
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

int		find_min(t_stack *stack)
{
	int	i;
	int	imin;

	i = -1;
	imin = 0;
	while (++i < stack->length)
	{
		if (stack->arr[i] < stack->arr[imin])
			imin = i;
	}
	return (imin);
}

int		find_max(t_stack *stack)
{
	int	i;
	int	imax;

	i = -1;
	imax = 0;
	while (++i < stack->length)
	{
		if (stack->arr[i] > stack->arr[imax])
			imax = i;
	}
	return (imax);
}

int		where_put_in_stack(t_stack *stack, int value, int asc)
{
	int	stack_i;

	stack_i = stack->length - 1;
	if (stack->length == 0)
		return (0);
	if (asc)
	{
		stack_i = find_min_greater(stack, value);
		if (stack_i == -1)
			stack_i = 0;
	}
	else
	{
		stack_i = find_max_minor(stack, value);
		if (stack_i == -1)
			stack_i = find_max(stack);
	}
	return (stack_i);
}

void	make_it_easy(t_ps *ps, int type, int istack_a, int istack_b)
{
	while ((ps->a.length > 0 && istack_a != ps->a.length - 1) || (ps->b.length > 0 && istack_b != ps->b.length - 1))
	{
		if (type == 0 && istack_a != ps->a.length - 1 && istack_b != ps->b.length - 1)
		{
			rr(&ps->a, &ps->b);
			istack_a++;
			istack_b++;
		}
		else if (type == 3 && istack_a != ps->a.length - 1 && istack_b != ps->b.length - 1)
		{
			rrr(&ps->a, &ps->b);
			istack_a = (ps->a.length + (istack_a - 1)) % ps->a.length;
			istack_b = (ps->b.length + (istack_b - 1)) % ps->b.length;
		}
		else 
		{
			if (ps->a.length > 0 && istack_a != ps->a.length - 1)
			{
				if (type <= 1)
				{
					rx(&ps->a, 1);
					istack_a++;
				}
				else {
					rrx(&ps->a, 1);
					istack_a = (ps->a.length + (istack_a - 1)) % ps->a.length;
				}
			}
			if (ps->b.length > 0 && istack_b != ps->b.length - 1)
			{
				if (type == 0 ||  type == 2)
				{
					rx(&ps->b, 1);
					istack_b++;
				}
				else
				{
					rrx(&ps->b, 1);
					istack_b = (ps->b.length + (istack_b - 1)) % ps->b.length;
				}
			}
		}
	}
}

int		get_min_move(t_ps *ps, int *type, int	istack_a)
{
	int	min;
	int move;
	int	istack_b;
	//ra-rb, ra-rrb, rra-rb, rra-rrb
	int	nmoves[4];
	//ra-rb
	istack_b = where_put_in_stack(&ps->b, ps->a.arr[istack_a], 0);
	nmoves[0] = nmove_totop(&ps->a, istack_a, 1);
	move = nmove_totop(&ps->b, istack_b, 1);
	if (move > nmoves[0])
		nmoves[0] = move;
	//rra-rrb
	nmoves[3] = nmove_totop(&ps->a, istack_a, 0);
	move = nmove_totop(&ps->b, istack_b, 0);
	if (move > nmoves[3])
		nmoves[3] = move;
	//ra-rrb
	nmoves[1] = nmove_totop(&ps->a, istack_a, 1) + nmove_totop(&ps->b, istack_b, 0);
	//rra-rb
	nmoves[2] = nmove_totop(&ps->a, istack_a, 0) + nmove_totop(&ps->b, istack_b, 1);
	min = nmoves[0];
	*type = 0;

	if (nmoves[1] < min)
	{
		*type = 1;
		min = nmoves[1];
	}
	if (nmoves[2] < min)
	{
		*type = 2;
		min = nmoves[2];
	}
	if (nmoves[3] < min)
	{
		*type = 3;
		min = nmoves[3];
	}
	return (min);
}

int 	getnchunk(t_ps *ps, int value, int chunk_size)
{
	int index;

	index = fval_index(ps->sorted, ps->size, value);
	return (index  / chunk_size);
}

void	put_in_b(t_ps *ps, int istack_a, int type)
{
	int	istack_b;

	istack_b = where_put_in_stack(&ps->b, ps->a.arr[istack_a], 0);	
	make_it_easy(ps, type, istack_a, istack_b);
	px(&ps->b, &ps->a);
}

void	pchunk(t_ps *ps, int nchunk, int chunk_size)
{
	int		mvtop;
	int		mvbottom;
	int		top;
	int		bottom;
	int		type;
	int		type2;

	while (ps->a.length > 0)
	{
		top = ps->a.length - 1;
		bottom = 0;
		while (top > 0 && getnchunk(ps, ps->a.arr[top], chunk_size) != nchunk)
			top--;
		while (bottom < ps->a.length && getnchunk(ps, ps->a.arr[bottom], chunk_size) != nchunk)
			bottom++;
		mvtop = -1;
		mvbottom = -1;
		if (ps->a.length && getnchunk(ps, ps->a.arr[top], chunk_size) == nchunk)
			mvtop = get_min_move(ps, &type, top);
		if (ps->a.length && getnchunk(ps, ps->a.arr[bottom], chunk_size) == nchunk)
			mvbottom = get_min_move(ps, &type2, bottom);
		if (mvtop == -1)
			break;
		if (mvtop < mvbottom)
			put_in_b(ps, top, type);
		else
			put_in_b(ps, bottom, type2);
		//print_stacks(&ps->a, &ps->b, "put_in_b");
	}
}

void	chunk_sort(t_ps *ps, int nchunk, int chunk_size)
{
	int index;

	if (nchunk < 0)
	{
		index = fval_index(ps->b.arr, ps->b.length, ps->sorted[0]);
		move_to_top(&ps->b, index);
		while (ps->b.length > 0)
			px(&ps->a, &ps->b);
		return ;
	}
	pchunk(ps, nchunk, chunk_size);
	//print_stacks(&ps->a, &ps->b, "CHUNKED");
	chunk_sort(ps, nchunk - 1, chunk_size);
}

void 	set_limits(int size, int *nchunk, int *chunk_size)
{
	//float	fl;

	if (size < 10)
		*nchunk = 1;
	else if (size < 50)
		*nchunk = 2;
	else if (size == 100)
		*nchunk = 5;
	else if (size == 500)
		*nchunk = 11;
	else
	{
		//fl = 5 + (0.015 * (size - 100));
		*nchunk = 5 + (0.015 * (size - 100));
	}
	*chunk_size = size / *nchunk;
	if (size % *chunk_size != 0)
		(*nchunk)++;
}

int		main(int argc, char **argv)
{
	int		error;
	t_ps	*ps;
	int		nchunk;
	int		chunk_size;

	ps = check_args(argc, argv, &error);
	if (!error)
	{
		set_limits(ps->size, &nchunk, &chunk_size);
		//print_stacks(&ps->a, &ps->b, "INIT");
		chunk_sort(ps, nchunk - 1, chunk_size);
		//print_stacks(&ps->a, &ps->b, "SORTED?");
	}
	remove_ps(ps);	
}