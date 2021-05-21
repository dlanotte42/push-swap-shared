/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:38:58 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:36:20 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

void	pchunk(t_ps *ps, int nchunk, int chunk_size)
{
	int		stack_i;
	int		type;

	stack_i = ps->a.length - 1;
	while (ps->a.length > 0)
	{
		best_choice(ps, nchunk, chunk_size, &stack_i);
		if (stack_i == -1)
			break ;
		get_min_move(ps, &type, stack_i, 0);
		put_in_b(ps, stack_i, type);
		stack_i = ps->a.length - 1;
	}
}

void	chunk_sort(t_ps *ps, int nchunk, int chunk_size)
{
	int	index;
	int	r;

	if (nchunk == 0 && chunk_size > 11 && chunk_size <= 20)
	{
		r = chunk_size / (chunk_size - 10);
		ps->rest = chunk_size % (chunk_size - 10);
		pchunk(ps, r - 1, chunk_size - 10);
		sort10loop(&ps->a, &ps->b, ps->a.length);
		nchunk = -1;
	}
	if (nchunk < 0)
	{
		index = find_max(&ps->b);
		move_to_top(&ps->b, index);
		while (ps->b.length > 0)
			px(&ps->a, &ps->b, 1);
		return ;
	}
	pchunk(ps, nchunk, chunk_size);
	chunk_sort(ps, nchunk - 1, chunk_size);
}
