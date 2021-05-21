/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:39:12 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:36:23 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

void	push(t_stack *stack, int value)
{
	t_list	*new_;

	new_ = (t_list *)malloc(sizeof(t_list));
	new_->next = stack->first;
	new_->val = value;
	if (stack->last == NULL)
		stack->last = new_;
	stack->first = new_;
	stack->arr[stack->length] = value;
	stack->length++;
}

int	pop(t_stack *stack)
{
	t_list	*tmp;
	int		value;

	value = 0;
	if (stack->first != NULL)
	{
		tmp = stack->first;
		value = tmp->val;
		stack->first = (stack->first)->next;
		free(tmp);
		if (stack->first == NULL || (stack->first)->next == NULL)
			stack->last = stack->first;
		stack->length--;
	}
	return (value);
}

t_ps	*init_ps(int size)
{
	t_ps	*ps;

	ps = (t_ps *) malloc(sizeof(t_ps));
	if (ps != NULL)
	{
		ps->a.first = NULL;
		ps->a.last = NULL;
		ps->b.first = NULL;
		ps->b.last = NULL;
		ps->size = size;
		ps->a.length = 0;
		ps->a.sname = 0;
		ps->b.sname = 1;
		ps->b.length = 0;
		ps->a.pos = 0;
		ps->b.pos = 0;
		ps->a.arr = (int *) malloc(sizeof(int) * size);
		ps->b.arr = (int *) malloc(sizeof(int) * size);
		ps->sorted = (int *) malloc(sizeof(int) * size);
	}
	return (ps);
}

void	remove_ps(t_ps *ps)
{
	t_list	*node;

	if (ps == NULL)
		return ;
	node = ps->a.first;
	while (node != NULL)
	{
		ps->a.first = node->next;
		free(node);
		node = ps->a.first;
	}
	node = ps->b.first;
	while (node != NULL)
	{
		ps->b.first = node->next;
		free(node);
		node = ps->b.first;
	}
	free(ps->a.arr);
	free(ps->b.arr);
	free(ps->sorted);
	free(ps);
}

char	**get_args(int *argc, char **argv)
{
	char	**args;
	int		i;

	if (*argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*argc = ft_table_len(args);
	}
	else
	{
		args = (char **) malloc((*argc) * sizeof(char *));
		args[*argc - 1] = NULL;
		*argc -= 1;
		i = -1;
		while (++i < *argc)
			args[i] = ft_strdup(argv[i + 1]);
	}
	return (args);
}
