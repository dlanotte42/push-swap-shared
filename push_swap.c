/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:31:32 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/11 11:50:35 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	set_to(t_stack *stack, int f, int t)
{
	int i;

	if (f >= t)
		return;
	i = -1;
	while (++i < f)
		rx(stack);
	sx(stack);
	rx(stack);
	t = t - f - 1;
	f = 0;
	set_to(stack, f, t);
}*/

/*int		stoai(t_stack *stack, int stack_i)
{
	int	arr_i;

	arr_i = stack_i % stack->length;
	arr_i = stack->length - 1 - arr_i;s
	return (arr_i);
}

int		stack_to_array_index(t_stack *stack, int arr_i)
{
	int	arr_i;

	arr_i = stack_i % stack->length;
	arr_i = stack->length - 1 - arr_i;
	return (stack->length - arr_i - 1);
}*/

/*void	set_to(t_stack *stack, int f, int t, int count)
{
	int i;

	if (count <= 0)
		return;
	i = -1;
	while (f > 0)
	{
		rx(stack);
		f--;
		t = (stack->length + t - 1) % stack->length;
	}
	sx(stack);
	if (count > 1)
		rx(stack);
	t--;
	count--;
	set_to(stack, 0, t, count);
}

void	find_place(t_stack *stack, int stack_i, int len)
{
	int	pos;
	int	arr_i;
	int	i;

	pos = stoai(stack, stack_i);
	arr_i = stoai(stack, stack_i + 1);
	i = 0;
	while (i < len && stack->arr[pos] < stack->arr[arr_i])
	{
		i++;
		arr_i = stoai(stack, pos + i);
	}
	if (i)
	{
		set_to(stack, stack_i, (stack_i + i) % stack->length, i);
	}
}*/

void	move_to_top(t_stack *stack, int stack_i)
{
	int move;
	int rxf;

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

int		fval_index(int *arr, int len, int val)
{
	int i;

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

void put_in_a_pivot(t_ps *ps, int pivot)
{
	int i;
	int	stack_i;

	if (ps->b.length == 0)
		return ;
	i = 0;
	stack_i = fval_index(ps->a.arr, ps->a.length, pivot);
	if (stack_i != ps->a.length - 1)
		move_to_top(&ps->a, stack_i);
	while (ps->b.length > 0)
		px(&ps->a, &ps->b);
}

void partiton_b(t_ps *ps, int pivot)
{
	int i;
	int	stack_i;
	int	n;

	if (ps->b.length == 0)
		return ;
	i = 0;
	stack_i = 0;
	while (++i < ps->a.length)
	{
		if (ps->a.arr[i] < ps->a.arr[stack_i])
			stack_i = i;
	}
	if (stack_i != ps->a.length - 1)
		move_to_top(&ps->a, stack_i);
	n = ps->b.length;
	i = n - 1;
	while (n > 0)
	{
		ps->b.pos = (ps->b.length + (i - 1)) % ps->b.length;
		//if (ps->b.arr[i] >= pivot)
		if (ps->b.arr[i] > pivot)
		{
			put_in_a(ps, i);
		}
		i = ps->b.pos;
		n--;
	}
}

int		find_mgreater(t_stack *stack, int value)
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

void	partiton_b2(t_ps *ps, int pivot)
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
		//if (ps->b.arr[i] >= pivot)
		if (ps->b.arr[i] > pivot)
		{
			stack_i = find_mgreater(&ps->a, ps->b.arr[i]);
			if (stack_i != ps->a.length - 1)
				move_to_top(&ps->a, stack_i);
			put_in_a(ps, i);
		}
		i = ps->b.pos;
		n--;
	}
}

int		is_sort(t_stack *stack, int left, int right)
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
}

void	partition(t_ps *ps, int n, int pivot)
{
	int	flag;
	int	i;
	int	count;

	i = fval_index(ps->a.arr, ps->a.length, pivot);
	i = (ps->a.length + (i - 1)) % ps->a.length;
	flag = 1;
	count = -1;
	ps->a.pos = i;
	//while (++count < ps->a.length && n > 0)
	while (n > 0)
	{
		if (ps->a.arr[i] > pivot)
			flag = 0;
		if (ps->a.arr[i] < pivot)
		{
			n--;
			ps->a.pos = (ps->a.length + (i - 1)) % ps->a.length;
			//if (!flag)
			if(check_if_put(ps->a.arr, ps->a.length, pivot, ps->a.arr[i]))
				put_in_b(ps, i);
			i = ps->a.pos;
		}
		else
			i = (ps->a.length + (i - 1)) % ps->a.length;
	}
	put_in_a_pivot(ps, pivot);
}

void	quick_sort(t_ps *ps, int left, int right, int rbranch)
{
	int	pivot;
	int	ipivot;

	if (left > right)
		return ;
	ipivot = left + ((right - left) / 2);
	pivot = ps->sorted[ipivot];
	//printf("\n[%d, %d] pivot = %d\n", left, right, pivot);
	partition(ps, ps->size - ipivot - 1, pivot);
	rbranch = 0;
	//printf("[%d, %d]", left, right);
	/*if (rbranch)
		printf(" dx");
	else
		printf(" sx");
	printf(" pivot: %d\n", pivot);*/
	//print_stacks(&ps->a, &ps->b, "partition");
	//if (is_sort(&ps->a, left, right))
	//	return;
	quick_sort(ps, ipivot + 1, right, 1);
	quick_sort(ps, left, ipivot - 1, 0);
}

void	quick_sort2(t_ps *ps, int left, int right, int rbranch)
{
	int	pivot;
	int	ipivot;

	if (left > right)
		return ;
	ipivot = left + ((right - left) / 2);
	pivot = ps->sorted[ipivot];
	//printf("\n[%d, %d] pivot = %d\n", left, right, pivot);
	rbranch = 0;
	//printf("[%d, %d]", left, right);
	/*if (rbranch)
		printf(" dx");
	else
		printf(" sx");
	printf(" pivot: %d\n", pivot);*/
	//print_stacks(&ps->a, &ps->b, "partition");
	//if (is_sort(&ps->a, left, right))
	//	return;
	quick_sort2(ps, ipivot + 1, right, 1);
	quick_sort2(ps, left, ipivot - 1, 0);
	partition(ps, ps->size - ipivot - 1, pivot);	
}

void	partition_a(t_ps *ps, int pivot)
{
	//int		flag;
	int		i;
	int		n;

	n = ps->a.length;
	i = n - 1;
	while (n > 0)
	{
		ps->a.pos = (ps->a.length + (i - 1)) % ps->a.length;
		if (ps->a.arr[i] < pivot)
		{
			//if (!flag)
			//if(check_if_put(ps->a.arr, ps->a.length, pivot, ps->a.arr[i]))
			put_in_b(ps, i);
		}
		i = ps->a.pos;
		n--;
	}
	//put_in_a_pivot(ps, pivot);
}


void	quick_sort3(t_ps *ps, int left, int right, int a)
{
	int	pivot;
	int	ipivot;
	int	i;

	if (left > right)
		return ;
	i = 0;
	while (i < ps->a.length && ps->a.arr[i] == ps->sorted[i])
		i++;
	if (i == ps->size)
		return ;

	ipivot = left + ((right - left) / 2);
	pivot = ps->sorted[ipivot];
	printf("\n[%d, %d] pivot = %d", left, right, pivot);
		
	if (a)
	{
		if (!check_if_pa(ps, left, right))
			return ;
		//printf(" partition A\n");
		partition_a(ps, pivot);
		print_stacks(&ps->a, &ps->b, "partition A");
		quick_sort3(ps, ipivot + 1, right, 0);
		quick_sort3(ps, left, ipivot - 1, 1);
	}
	else
	{
		//printf(" partition B\n");
		//partiton_b(ps, pivot);
		partiton_b2(ps, pivot);
		print_stacks(&ps->a, &ps->b, "partition B");
		quick_sort3(ps, left, ipivot - 1, 1);
		quick_sort3(ps, ipivot + 1, right, 0);
	}		
}

int	main(int argc, char **argv)
{
	int		res;
	t_ps	*ps;
	int		i;

	ps = check_args(argc, argv, &res);
	if (res)
	{
		print_stacks(&ps->a, &ps->b, "INIT");
		//quick_sort(ps, 0, ps->size - 1, 1);
		quick_sort3(ps, 0, ps->size - 1, 1);
		i = fval_index(ps->a.arr, ps->a.length, ps->sorted[ps->a.length - 1]);
		if (i != ps->a.length - 1)
			move_to_top(&ps->a, i);
		//printf("\n");
		print_stacks(&ps->a, &ps->b, "SORTED?");
	}
	remove_ps(ps);	
}