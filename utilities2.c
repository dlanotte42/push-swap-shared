/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:12:42 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/18 14:56:05 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

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

void	reverse(t_list	*node, t_list **first, t_list **last)
{
	t_list	*tmp;

	if (node->next != NULL && node->next->next != NULL)
		reverse(node->next, first, last);
	else if (node->next != NULL)
	{
		tmp = *first;
		*first = node->next;
		*last = tmp;		
	}
	node->next->next = node;
	node->next = NULL;
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

int	ft_table_len(char **table)
{
	int	i;

	if (!table)
		return (0);
	i = 0;
	while (table[i])
		i++;
	return (i);
}

/*void	print_stacks(t_stack *a, t_stack *b, char *str)
{
	t_list	*na;
	t_list	*nb;
	int		i;

	printf("\t[STACK A]\t\t[STACK B]\t\t%s\n", str);
	i = a->length;
	na = a->first;
	nb = b->first;
	while (na != NULL || nb != NULL)
	{
		printf("%d|", --i);
		if (na != NULL)
		{
			printf("\t%d",na->val);
			na = na->next;
		}
		else
			printf("\t ");
		printf("\t\t|");
		if (nb != NULL)
		{
			printf("\t%d",nb->val);
			nb = nb->next;
		}
		else
			printf("\t ");
		printf("\n-------------------------------------------------\n");		
	}
	printf("\n");
}*/

