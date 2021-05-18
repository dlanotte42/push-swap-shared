/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:31:32 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/18 14:55:49 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

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

int get_min_move(t_ps *ps, int *type, int from, int flag)
{
	int		move;
	int		to;
	t_stack	*first;
	t_stack *second;
	//ra-rb, ra-rrb, rra-rb, rra-rrb
	int	nmoves[4];

	first = &ps->a;
	second = &ps->b;
	//ra-rb
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
	//rra-rrb
	nmoves[3] = nmove_totop(first, from, 0);
	move = nmove_totop(second, to, 0);
	if (move > nmoves[3])
		nmoves[3] = move;
	//ra-rrb
	nmoves[1] = nmove_totop(first, from, 1) + nmove_totop(second, to, 0);
	//rra-rb
	nmoves[2] = nmove_totop(first, from, 0) + nmove_totop(second, to, 1);
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
	int index;
	int flag;
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
			return (i + ((index - base)  / chunk_size));
	}
	return (index  / (chunk_size + flag));
}

void	put_in_a(t_ps *ps, int istack_b, int type)
{
	int	istack_a;

	istack_a = where_put_in_stack(&ps->a, ps->b.arr[istack_b], 1);	
	make_it_easy(ps, type, istack_a, istack_b);
	px(&ps->a, &ps->b);
}

void	put_in_b(t_ps *ps, int istack_a, int type)
{
	int	istack_b;

	istack_b = where_put_in_stack(&ps->b, ps->a.arr[istack_a], 0);	
	make_it_easy(ps, type, istack_a, istack_b);
	px(&ps->b, &ps->a);
}

int	best_choice(t_ps *ps, int nchunk, int chunk_size, int *index)
{
	int moves1;
	int moves2;
	int ichunk;
	int type;
	int index2;

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

void	pchunk(t_ps *ps, int nchunk, int chunk_size)
{
	int		stack_i;
	int		type;

	stack_i = ps->a.length - 1;
	while (ps->a.length > 0)
	{
		best_choice(ps, nchunk, chunk_size, &stack_i);
		if (stack_i == -1)
			break;
		get_min_move(ps, &type, stack_i, 0);
		put_in_b(ps, stack_i, type);
		stack_i = ps->a.length - 1;
	}
}

void 	set_limits(t_ps * ps, int *nchunk, int *chunk_size)
{
	if (ps->size <= 20)
		*nchunk = 1;
	else if (ps->size < 50)
		*nchunk = 2;
	else if (ps->size == 100)
		*nchunk = 5;
	else if (ps->size == 500)
		*nchunk = 11;
	else
	{
		*nchunk = 5 + (0.015 * (ps->size - 100));
	}
	*chunk_size = ps->size / *nchunk;
	ps->rest = ps->size % *chunk_size;
}

void 	sort2n(t_stack *stack)
{
	int i;

	i = find_min(stack);
	if (i == 0)
		sx(stack);
}

void 	sort3n(t_stack *stack)
{
	int i;
	int j;
	int k;

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
		sx(stack);
		i = find_min(stack);
		if (i == 1)
			rx(stack, 1);
		else if (i == 0)
			rrx(stack, 1);
	}
}

void	sort10loop(t_stack *first, t_stack *second, int size)
{
	int i;

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
		px(second, first);
		if (size > 4)
		{
			move_to_top(first, find_min(first));
			px(second, first);
		}
		sort10loop(first, second, first->length);
		px(first, second);
		if (size > 4)
			px(first, second);
	}
}

void	chunk_sort(t_ps *ps, int nchunk, int chunk_size)
{
	int index;
	int	r;

	if (nchunk == 0 && chunk_size > 11 && chunk_size <= 20)
	{
		r = chunk_size / (chunk_size - 10);
		ps->rest = chunk_size % (chunk_size - 10);
		pchunk(ps, r - 1, chunk_size - 10);
		sort10loop(&ps->a, &ps->b, ps->a.length);
		nchunk = -1;
	}
	if (nchunk < 0)
	{
		index = find_max(&ps->b);
		move_to_top(&ps->b, index);
		while (ps->b.length > 0)
			px(&ps->a, &ps->b);
		return ;
	}
	pchunk(ps, nchunk, chunk_size);
	chunk_sort(ps, nchunk - 1, chunk_size);
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
		if (ps->size <= 10)
			sort10loop(&ps->a, &ps->b, ps->size);
		else
		{
			set_limits(ps, &nchunk, &chunk_size);
			chunk_sort(ps, nchunk - 1, chunk_size);
		}
	}
	remove_ps(ps);	
}