/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:31:32 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/12 18:09:41 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

void	move_to_top(t_stack *stack, int stack_i)
{
	int	move;
	int	rxf;

	if (stack_i + 1 < stack->length - stack_i - 1)
		move = stack_i + 1;
	else
		move = stack->length - stack_i - 1;
	rxf = ((stack->length - stack_i - 1) <= stack_i + 1);
	while (move > 0)
	{
		if (rxf)
			rx(stack);
		else
			rrx(stack);
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

void	partiton_b(t_ps *ps)
{
	int i;
	int	stack_i;
	int	n;

	if (ps->b.length == 0)
		return ;
	n = ps->b.length;
	i = n - 1;
	while (n > 0)
	{
		ps->b.pos = (ps->b.length + (i - 1)) % ps->b.length;
		stack_i = find_min_greater(&ps->a, ps->b.arr[i]);
		if (stack_i != ps->a.length - 1)
			move_to_top(&ps->a, stack_i);
		put_in_a(ps, i);
		i = ps->b.pos;
		n--;
	}
}

/*int		is_sort(t_stack *stack, int left, int right)
{
	int i;

	i = left;
	while (i < right && stack->arr[i] >= stack->arr[i + 1])
		i++;
	return (i == right);
}

int		check_if_put(int *arr, int	length, int pivot, int value)
{
	int	ipivot;
	int	ivalue;
	int	i;

	ipivot = fval_index(arr, length, pivot);
	ivalue = fval_index(arr, length, value);
	if (value > pivot)
		return (0);
	i = (ipivot + 1) % length;
	while (i != ivalue && arr[i] < pivot)
		i = (i + 1) % length;
	return (i != ivalue);
}

int		check_if_pa(t_ps *ps, int left, int right)
{
	int	index;
	int	i;
	int n;

	index = fval_index(ps->a.arr, ps->a.length, ps->sorted[left]);
	n = right - left + 1;
	//i = (ipivot + 1) % length;
	i = -1;
	while (++i < n && ps->a.arr[index] == ps->sorted[left + i])
	{
		index = (index + 1) % ps->a.length;
	}
	return (i < n);
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

void	set_arr(t_ps *ps)
{
	int	i_seq;
	int	j;
	int	k;
	int	num;
	int index;

	i_seq = 0;
	num = ps->a.length;
	k = 0;
	while (i_seq < ps->a.n_seq)
	{
		if (num <= ps->a.length / 2)
		{
			j = -1;
			while (++j < ps->a.sequences[i_seq]->length)
			{
				index = ps->a.sequences[i_seq]->stack_i - j;
				index = (ps->a.length + index) % ps->a.length;
				ps->a.arr2[k] = ps->a.arr[index];
				k++;
			}
		}
		num -= ps->a.sequences[i_seq]->length;
		i_seq++;
	}
	index = k - 1;
	while (k < ps->a.length)
	{
		ps->a.arr2[k] = ps->a.arr[index];
		k++;
	}
}

void	gfd_sort(t_ps *ps)
{

	set_sequences(&ps->a);
	ft_sort_sequences(ps->a.sequences, ps->a.n_seq);
	if (ps->a.n_seq <= 1)
		return;
	set_arr(ps);
	partition_a(ps);
	print_stacks(&ps->a, &ps->b, "PARTITION A");
	partiton_b(ps);
	gfd_sort(ps);
}	

int		main(int argc, char **argv)
{
	int		res;
	t_ps	*ps;
	//int		i;

	ps = check_args(argc, argv, &res);
	if (res)
	{
		print_stacks(&ps->a, &ps->b, "INIT");
		gfd_sort(ps);
		//quick_sort(ps, 0, ps->size - 1, 1);
		//quick_sort3(ps, 0, ps->size - 1, 1);
		//i = fval_index(ps->a.arr, ps->a.length, ps->sorted[ps->a.length - 1]);
		//if (i != ps->a.length - 1)
			//move_to_top(&ps->a, i);
		//printf("\n");
		print_stacks(&ps->a, &ps->b, "SORTED?");
	}
	remove_ps(ps);	
}