/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:31:32 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/18 17:20:07 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

static int	get_min_support(int *type, int nmoves[4])
{
	*type = 0;
	if (nmoves[1] < nmoves[0])
	{
		*type = 1;
		nmoves[0] = nmoves[1];
	}
	if (nmoves[2] < nmoves[0])
	{
		*type = 2;
		nmoves[0] = nmoves[2];
	}
	if (nmoves[3] < nmoves[0])
	{
		*type = 3;
		nmoves[0] = nmoves[3];
	}
	return (nmoves[0]);
}

//0 - ra-rb, 1 - ra-rrb, 2 - rra-rb, 3 - rra-rrb
//ra-rb, ra-rrb, rra-rb, rra-rrb
int	get_min_move(t_ps *ps, int *type, int from, int flag)
{
	int		move;
	int		to;
	t_stack	*first;
	t_stack	*second;
	int		nmoves[4];

	first = &ps->a;
	second = &ps->b;
	if (flag)
	{
		first = &ps->b;
		second = &ps->a;
	}
	to = where_put_in_stack(second, first->arr[from], flag);
	nmoves[0] = nmove_totop(first, from, 1);
	move = nmove_totop(second, to, 1);
	if (move > nmoves[0])
		nmoves[0] = move;
	nmoves[3] = nmove_totop(first, from, 0);
	move = nmove_totop(second, to, 0);
	if (move > nmoves[3])
		nmoves[3] = move;
	nmoves[1] = nmove_totop(first, from, 1) + nmove_totop(second, to, 0);
	nmoves[2] = nmove_totop(first, from, 0) + nmove_totop(second, to, 1);
	return (get_min_support(type, nmoves));
}
