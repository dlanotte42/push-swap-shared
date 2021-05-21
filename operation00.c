/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:38:05 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:36:12 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

void	sx(t_stack	*stack, int flag)
{
	t_list	*first;
	t_list	*second;
	int		tmp;

	first = stack->first;
	if (first != NULL && first->next != NULL)
	{
		second = first->next;
		first->next = second->next;
		second->next = first;
		if (first->next == NULL)
			stack->last = first;
		stack->first = second;
		tmp = stack->arr[stack->length - 1];
		stack->arr[stack->length - 1] = stack->arr[stack->length - 2];
		stack->arr[stack->length - 2] = tmp;
		tmp = stack->length - 1 - stack->pos;
		if (tmp == 0 || tmp == 1)
			stack->pos = stack->length - 1 - (1 - tmp);
	}
	if (flag && stack->sname)
		ft_putstr_fd("sb\n", 1);
	else if (flag)
		ft_putstr_fd("sa\n", 1);
}

void	px(t_stack *one, t_stack *two, int flag)
{
	int	value;

	if (two->first == NULL)
		return ;
	value = pop(two);
	push(one, value);
	if (flag && one->sname)
		ft_putstr_fd("pb\n", 1);
	else if (flag)
		ft_putstr_fd("pa\n", 1);
}

void	rx(t_stack	*stack, int flag)
{
	t_list	*tmp;
	int		i;
	int		top;

	if (stack->first == NULL || stack->first->next == NULL)
		return ;
	tmp = stack->first;
	stack->last->next = stack->first;
	stack->first = stack->first->next;
	stack->last = tmp;
	stack->last->next = NULL;
	top = stack->arr[stack->length - 1];
	i = stack->length;
	while (--i > 0)
		stack->arr[i] = stack->arr[i - 1];
	stack->arr[0] = top;
	stack->pos = (stack->pos + 1) % stack->length;
	if (flag && stack->sname)
		ft_putstr_fd("rb\n", 1);
	else if (flag && !stack->sname)
		ft_putstr_fd("ra\n", 1);
}

void	rrx(t_stack	*stack, int flag)
{
	t_list	*last;
	int		i;
	int		bottom;

	if (stack->first == NULL || stack->first->next == NULL)
		return ;
	last = stack->first;
	while (last->next->next != NULL)
		last = last->next;
	stack->last->next = stack->first;
	stack->first = stack->last;
	stack->last = last;
	last->next = NULL;
	bottom = stack->arr[0];
	i = -1;
	while (++i < stack->length - 1)
		stack->arr[i] = stack->arr[i + 1];
	stack->arr[stack->length - 1] = bottom;
	stack->pos = (stack->length + stack->pos - 1) % stack->length;
	if (flag && stack->sname)
		ft_putstr_fd("rrb\n", 1);
	else if (flag && !stack->sname)
		ft_putstr_fd("rra\n", 1);
}
