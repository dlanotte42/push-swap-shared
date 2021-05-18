/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:59:25 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/18 16:30:07 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size, int order)
{
	int	i;
	int	j;
	int	flag;

	if (size == 1)
		return ;
	order = (order > 0);
	ft_sort_int_tab(tab, size - 1, order);
	i = size - 1;
	j = i - 1;
	flag = (order * (tab[i] < tab[j])) + (!order * (tab[i] > tab[j]));
	while (j >= 0 && flag)
	{
		ft_swap(tab + i, tab + j);
		i--;
		j--;
		flag = (order * (tab[i] < tab[j])) + (!order * (tab[i] > tab[j]));
	}
}
