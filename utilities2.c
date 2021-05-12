/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:12:42 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/12 18:07:35 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

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

void	print_stacks(t_stack *a, t_stack *b, char *str)
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
}

void	ft_swap_sequence(t_seq **tab, int i, int j)
{
	t_seq	*c;

	c = tab[i];
	tab[i] = tab[j];
	tab[j] = c;
}

void	ft_sort_sequences(t_seq **tab, int size)
{
	int	i;
	int	j;

	if (size <= 1)
		return ;
	ft_sort_sequences(tab, size - 1);
	i = size - 1;
	j = i - 1;
	while (j >= 0 && tab[i]->length > tab[j]->length)
	{
		ft_swap_sequence(tab, i, j);
		i--;
		j--;
	}
}