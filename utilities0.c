/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:39:05 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/19 12:29:13 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

int	ft_is_yet_sorted(t_ps *ps)
{
	int	istack;
	int	j;

	if (ps->a.length != ps->size)
		return (0);
	istack = find_min(&ps->a);
	j = 0;
	while (j < ps->size && ps->a.arr[istack] == ps->sorted[ps->size - 1 - j])
	{
		istack = (ps->a.length + istack - 1) % ps->a.length;
		j++;
	}
	if (j < ps->size)
		return (0);
	istack = find_min(&ps->a);
	move_to_top(&ps->a, istack);
	return (1);
}

t_ps	*ft_error(int argc, char **argv, int *error)
{
	int		i;
	int		num;
	t_ps	*ps;
	char	**args;

	*error = 1;
	ps = NULL;
	if (argc >= 2)
	{
		args = get_args(&argc, argv);
		i = -1;
		ps = init_ps(argc);
		*error = 0;
		while (!*error && ++i < argc)
		{
			num = ft_atoi(args[i], error);
			*error = (*error || fval_index(ps->a.arr, ps->a.length, num) != -1);
			if (!*error)
				push(&ps->a, num);
		}
		free_table(args);
	}
	return (ps);
}

t_ps	*check_args(int argc, char **argv, int *error)
{
	int		i;
	t_ps	*ps;
	t_list	*ptr;

	ps = ft_error(argc, argv, error);
	if (*error)
	{
		if (argc > 1)
			ft_putstr_fd("Error\n", 2);
	}
	else
	{
		if (ps->a.length > 1)
			reverse(ps->a.first, &ps->a.first, &ps->a.last);
		i = -1;
		ptr = ps->a.first;
		while (++i < ps->a.length)
		{
			ps->a.arr[ps->a.length - 1 - i] = ptr->val;
			ps->sorted[i] = ptr->val;
			ptr = ptr->next;
		}
		ft_sort_int_tab(ps->sorted, ps->a.length, 0);
	}
	return (ps);
}
