/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:30:48 by dlanotte          #+#    #+#             */
/*   Updated: 2021/05/18 16:40:01 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

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
		ft_putstr_fd("Error\n", 2);
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
