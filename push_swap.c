/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:31:32 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/14 18:33:13 by gcarbone         ###   ########.fr       */
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

int	fval_index(int *arr, int len, int val)
{
	int	i;

	i = 0;
	while (i < len && arr[i] != val)
		i++;
	if (i < len)
		return (i);
	return (-1);
}

void	put_in_a(t_ps *ps, int stack_i)
{
	move_to_top(&ps->b, stack_i);
	px(&ps->a, &ps->b);
}

void	put_in_b(t_ps *ps, int stack_i)
{
	move_to_top(&ps->a, stack_i);
	px(&ps->b, &ps->a);
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

int		where_put_in_a0(t_ps *ps, int value_b)
{
	int	stack_i;

	stack_i = ps->a.length - 1;
	while (stack_i >= 0 && value_b > ps->a.arr[stack_i])
		stack_i--;
	if (stack_i < 0)
		stack_i = 0;
	return (stack_i);
}

int		where_put_in_a(t_ps *ps, int value_b, int flag)
{
	int	stack_i;
	int	i;
	int n;

	stack_i = fval_index(ps->a.arr, ps->a.length, ps->a.ssmin);
	n = ps->a.sequences[0]->length;
	i = stack_i;
	while (--n >= 0 && value_b > ps->a.arr[i])
		i = (ps->a.length + i - 1) % ps->a.length;
	if (!flag)
		return (i);
	if (value_b < ps->a.ssmin)
		ps->a.ssmin = value_b;
	ps->a.sequences[0]->length++;
	return (i);
}

int		where_put_in_b(t_ps *ps, int value_a)
{
	int	stack_i;
	int	i;
	int n;

	stack_i = fval_index(ps->b.arr, ps->b.length, ps->b.ssmin);
	n = ps->b.sequences[0]->length;
	i = stack_i;
	while (--n >= 0 && value_a > ps->b.arr[i])
		i = (ps->b.length + i - 1) % ps->b.length;
	if (value_a < ps->b.ssmin)
		ps->b.ssmin = value_a;
	ps->b.sequences[0]->length++;
	return (i);
}

/*int		where_put_in_a(t_ps *ps, int value_b, int min_greater, int max_minor)
{
	value_b = value_b + 1;
	if (min_greater == -1)
		return ((ps->a.length + max_minor - 1) % ps->a.length);
	return (min_greater);
}*/

/*int		where_put_in_a(t_ps *ps, int value_b, int min_greater, int max_minor)
{
	int	i;
	int	j;
	int	k;

	if (min_greater == -1)
		return (max_minor);
	if (max_minor == -1)
		return (min_greater);
	i = fval_index(ps->sorted, ps->size, ps->a.arr[min_greater]);
	j = fval_index(ps->sorted, ps->size, value_b);
	k = fval_index(ps->sorted, ps->size, ps->a.arr[max_minor]);
	// se value_b nell' array ordinato e' piu' vicino a min_greater rispetto a max_minor
	if ((j - i) < (k - j))
		return(min_greater);
	if ((k - j) < (j - i))
		return((ps->a.length + max_minor - 1) % ps->a.length);
	if (min_greater < ((ps->a.length - 1) / 2))
		i = min_greater + 1;
	else
		i = ps->a.length - 1 - min_greater;
	if (max_minor <= ((ps->a.length - 1) / 2))
		k = max_minor;
	else
		k = ps->a.length - max_minor;
	if (i < k)
		return (min_greater);
	return ((ps->a.length + max_minor - 1) % ps->a.length);
}*/

int		get_min_move(t_ps *ps, int *type, int *nmove)
{
	int i;
	int	istack_a;
	int	min;
	int imin;
	int move;
	//ra-rb, ra-rrb, rra-rb, rra-rrb
	int	nmoves[4];

	imin = -1;
	i = ps->b.length;
	min = -1;
	while (--i >= 0)
	{
		//ra-rb
		//istack_a = where_put_in_a(ps, ps->b.arr[i], 0);
		istack_a = where_put_in_a0(ps, ps->b.arr[i]);
		nmoves[0] = nmove_totop(&ps->a, istack_a, 1);
		move = nmove_totop(&ps->b, i, 1);
		if (move > nmoves[0])
			nmoves[0] = move;
		//rra-rrb
		nmoves[3] = nmove_totop(&ps->a, istack_a, 0);
		move = nmove_totop(&ps->b, i, 0);
		if (move > nmoves[3])
			nmoves[3] = move;
		//ra-rrb
		nmoves[1] = nmove_totop(&ps->a, istack_a, 1) + nmove_totop(&ps->b, i, 0);
		//rra-rb
		nmoves[2] = nmove_totop(&ps->a, istack_a, 0) + nmove_totop(&ps->b, i, 1);
		if (imin == -1 || nmoves[0] < min || nmoves[1] < min || nmoves[2] < min || nmoves[3] < min)
		{
			imin = i;
			min = nmoves[0];
			*type = 0;
		}
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
	}
	*nmove = min;
	return (imin);
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

/*void	make_it_easy(t_ps *ps, int type, int istack_a, int istack_b)
{
	if (istack_a == ps->a.length && istack_b == ps->b.length)
		return;
	if (istack_a != ps->a.length && istack_b == ps->b.length)
	{
		if (type == 0)
		{
			rr(&ps->a, &ps->b);
			istack_a++;
			istack_b++;
		}
		else if (type == 3)
		{
			rrr(&ps->a, &ps->b);
			istack_a = (ps->a.length + (istack_a - 1)) % ps->a.length;
			istack_b = (ps->b.length + (istack_b - 1)) % ps->b.length;
		}
	}
	if (istack_a != ps->a.length)
	{
		if (type == 0)
		{
			rr(&ps->a, &ps->b);
			istack_a++;
		}
	}
}*/

void	ft_union2(t_ps *ps)
{
	int istack_b;
	int	istack_a;
	int	type;
	int	nmove;

	if (ps->b.length == 0)
		return ;
	while (ps->b.length > 0)
	{
		istack_b = get_min_move(ps, &type, &nmove);		
		//istack_a = where_put_in_a(ps, ps->b.arr[istack_b], 0);
		istack_a = where_put_in_a0(ps, ps->b.arr[istack_b]);
		make_it_easy(ps, type, istack_a, istack_b);
		put_in_a(ps, ps->b.length - 1);
	}
}

void	ft_union3(t_ps *ps)
{
	int istack_b;
	int	istack_a;
	int	type;
	int	nmove;

	if (ps->b.length == 0)
		return ;
	while (ps->b.length > 0)
	{
		istack_b = get_min_move(ps, &type, &nmove);		
		//istack_a = where_put_in_a(ps, ps->b.arr[istack_b], 0);
		istack_a = where_put_in_a0(ps, ps->b.arr[istack_b]);
		make_it_easy(ps, type, istack_a, istack_b);
		put_in_a(ps, ps->b.length - 1);
	}
}

/*void	ft_union(t_ps *ps)
{
	int i;
	//int	min_greater;
	//int	max_minor;
	int	stack_i;
	int	n;

	if (ps->b.length == 0)
		return ;
	n = ps->b.length;
	i = n - 1;
	while (n > 0)
	{
		ps->b.pos = (ps->b.length + (i - 1)) % ps->b.length;
		//min_greater = find_min_greater(&ps->a, ps->b.arr[i]);
		//max_minor = find_max_minor(&ps->a, ps->b.arr[i]);
		//stack_i = where_put_in_a(ps, ps->b.arr[i], min_greater, max_minor);
		stack_i = where_put_in_a(ps, ps->b.arr[i]);
		if (stack_i != ps->a.length - 1)
			move_to_top(&ps->a, stack_i);
		put_in_a(ps, i);
		i = ps->b.pos;
		n--;
	}
}*/

/*int		is_sort(t_stack *stack, int left, int right)
{
	int i;

	i = left;
	while (i < right && stack->arr[i] >= stack->arr[i + 1])
		i++;
	return (i == right);
}*/

void	partition_a(t_ps *ps)
{
	int		i;
	int		n;
	n = ps->a.length;
	i = n - 1;
	while (n > 0)
	{
		ps->a.pos = (ps->a.length + (i - 1)) % ps->a.length;
		if (fval_index(ps->a.arr2, ps->size, ps->a.arr[i]) >= 0)
			put_in_b(ps, i);
		i = ps->a.pos;
		n--;
	}
}

void	partition(t_ps *ps, int flag)
{
	int		i;
	int		n;

	n = (flag * (ps->a.length)) + (!flag * (ps->b.length));
	i = n - 1;
	while (n > 0)
	{
		if (flag)
		{
			ps->a.pos = (ps->a.length + (i - 1)) % ps->a.length;
			if (fval_index(ps->a.arr2, ps->size, ps->a.arr[i]) >= 0)
				put_in_b(ps, i);
			i = ps->a.pos;
		}
		else{
			ps->b.pos = (ps->b.length + (i - 1)) % ps->b.length;
			if (fval_index(ps->b.arr2, ps->size, ps->b.arr[i]) >= 0)
				put_in_a(ps, i);
			i = ps->b.pos;
		}
		n--;
	}
}

void	set_seq(t_stack *stack, int start, int next)
{
	if (next < start)
		stack->sequences[stack->n_seq]->length = start - next;
	else
		stack->sequences[stack->n_seq]->length = start + 1 + (stack->length - next - 1);
	stack->sequences[stack->n_seq]->stack_i = start;
	stack->n_seq++;
}

void	set_sequences(t_stack *stack)
{
	int	imin;
	int	next;
	int	prev;
	int	start;

	if (stack->length == 0)
		return;
	imin = find_min_index(stack);
	next = ((stack->length + (imin - 1)) % stack->length);
	prev = imin;
	start = imin;
	stack->n_seq = 0;
	while (next != imin)
	{
		if (stack->arr[next] < stack->arr[prev])
		{
			set_seq(stack, start, next);
			start = next;
			prev = next;
		}
		else
		{
			prev = next;
			next = ((stack->length + (next - 1)) % stack->length);
		}
	}
	set_seq(stack, start, next);
}

void	set_arr(t_stack *stack)
{
	int	i_seq;
	int	j;
	int	k;
	int	num;
	int index;

	i_seq = 1;
	num = stack->length - stack->sequences[0]->length;
	k = 0;
	while (i_seq < stack->n_seq)
	{
		if (num <= stack->length / 2)
		{
			j = -1;
			while (++j < stack->sequences[i_seq]->length)
			{
				index = stack->sequences[i_seq]->stack_i - j;
				index = (stack->length + index) % stack->length;
				stack->arr2[k] = stack->arr[index];
				k++;
			}
		}
		num -= stack->sequences[i_seq]->length;
		i_seq++;
	}
	index = k - 1;
	while (k < stack->length)
	{
		stack->arr2[k] = stack->arr2[index];
		k++;
	}
}

void	set_arr2(t_ps *ps)
{
	int	i_seq;
	int	k;
	int index;

	i_seq = 1;
	k = -1;
	while (++k < ps->a.sequences[i_seq]->length)
	{
		index = ps->a.sequences[i_seq]->stack_i - k;
		index = (ps->a.length + index) % ps->a.length;
		ps->a.arr2[k] = ps->a.arr[index];
		k++;
	}
	index = k - 1;
	while (k < ps->a.length)
	{
		ps->a.arr2[k] = ps->a.arr2[index];
		k++;
	}
}

void	gfd_sort(t_ps *ps)
{
	set_sequences(&ps->a);
	ft_sort_sequences(ps->a.sequences, ps->a.n_seq);
	if (ps->a.n_seq <= 1)
		return;
	ps->a.ssmin = ps->a.arr[ps->a.sequences[0]->stack_i];
	set_arr(&ps->a);
	partition(ps, 1);
	//print_stacks(&ps->a, &ps->b, "PARTITION A");
	//ft_union(ps, 1);
	ft_union2(ps);
	//print_stacks(&ps->a, &ps->b, "UNION B->A");
	gfd_sort(ps);
}

int		get_min_move2(t_ps *ps, int *type, int	istack_a)
{
	int	min;
	int move;
	int	istack_b;
	//ra-rb, ra-rrb, rra-rb, rra-rrb
	int	nmoves[4];
	//ra-rb
	//istack_a = where_put_in_a(ps, ps->b.arr[i], 0);
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

void	put_in_b0(t_ps *ps, int istack_a, int type)
{
	int	istack_b;

	istack_b = where_put_in_stack(&ps->b, ps->a.arr[istack_a], 0);	
	make_it_easy(ps, type, istack_a, istack_b);
	//move_to_top(&ps->a, istack_a);
	//(&ps->b, istack_b);
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
			mvtop = get_min_move2(ps, &type, top);
		if (ps->a.length && getnchunk(ps, ps->a.arr[bottom], chunk_size) == nchunk)
			mvbottom = get_min_move2(ps, &type2, bottom);
		if (mvtop == -1)
			break;
		if (mvtop < mvbottom)
			put_in_b0(ps, top, type);
		else
			put_in_b0(ps, bottom, type2);
		//print_stacks(&ps->a, &ps->b, "put_in_b0");
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

	if (size < 50)
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
	int		res;
	t_ps	*ps;
	int		nchunk;
	int		chunk_size;

	ps = check_args(argc, argv, &res);
	set_limits(ps->size, &nchunk, &chunk_size);
	if (res)
	{
		//print_stacks(&ps->a, &ps->b, "INIT");
		//gfd_sort(ps);
		//quick_sort(ps, 0, ps->size - 1, 1);
		//quick_sort3(ps, 0, ps->size - 1, 1);
		//i = fval_index(ps->a.arr, ps->a.length, ps->sorted[ps->a.length - 1]);
		//if (i != ps->a.length - 1)
			//move_to_top(&ps->a, i);
		//printf("\n");
		chunk_sort(ps, nchunk - 1, chunk_size);
		print_stacks(&ps->a, &ps->b, "SORTED?");
	}
	remove_ps(ps);	
}