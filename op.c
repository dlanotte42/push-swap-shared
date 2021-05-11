/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:41:54 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/10 12:16:58 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "op.h"

void	sx(t_stack	*stack)
{
	t_list	*first;
	t_list	*second;
	int tmp;

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
			stack->pos = stack->length - 1  - (1 - tmp);
	}
	printf("\nswap");
}

void	px(t_stack	*a, t_stack	*b)
{
	int	value;

	if (b->first == NULL)
		return ;
	value = pop(b);
	push(a, value);
	printf("\npush");
}

void	rx(t_stack	*stack)
{
	t_list	*tmp;
	int 	i;
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
	printf("\nrotate");
}

void	rrx(t_stack	*stack)
{
	t_list *last;
	int 	i;
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
	printf("\nreverse rotate");
}