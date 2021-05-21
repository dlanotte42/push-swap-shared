/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:38:23 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:36:16 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

static void	make_it_ss(t_ps *ps, int type, int *istack_a)
{
	if (type <= 1)
	{
		rx(&ps->a, 1);
		(*istack_a)++;
	}
	else
	{
		rrx(&ps->a, 1);
		*istack_a = (ps->a.length + (*istack_a - 1)) % ps->a.length;
	}
}

static void	make_it_support(t_ps *ps, int type, int *istack_a, int *istack_b)
{
	if (ps->a.length > 0 && *istack_a != ps->a.length - 1)
		make_it_ss(ps, type, istack_a);
	if (ps->b.length > 0 && *istack_b != ps->b.length - 1)
	{
		if (type == 0 || type == 2)
		{
			rx(&ps->b, 1);
			(*istack_b)++;
		}
		else
		{
			rrx(&ps->b, 1);
			*istack_b = (ps->b.length + (*istack_b - 1)) % ps->b.length;
		}
	}
}

void	make_it_easy(t_ps *ps, int type, int istack_a, int istack_b)
{
	while ((ps->a.length > 0 && istack_a != ps->a.length - 1) \
		|| (ps->b.length > 0 && istack_b != ps->b.length - 1))
	{
		if (type == 0 && istack_a != ps->a.length - 1 \
			&& istack_b != ps->b.length - 1)
		{
			rr(&ps->a, &ps->b, 1);
			istack_a++;
			istack_b++;
		}
		else if (type == 3 && istack_a != ps->a.length - 1 \
			&& istack_b != ps->b.length - 1)
		{
			rrr(&ps->a, &ps->b, 1);
			istack_a = (ps->a.length + (istack_a - 1)) % ps->a.length;
			istack_b = (ps->b.length + (istack_b - 1)) % ps->b.length;
		}
		else
		{
			make_it_support(ps, type, &istack_a, &istack_b);
		}
	}
}

void	put_in_a(t_ps *ps, int istack_b, int type)
{
	int	istack_a;

	istack_a = where_put_in_stack(&ps->a, ps->b.arr[istack_b], 1);
	make_it_easy(ps, type, istack_a, istack_b);
	px(&ps->a, &ps->b, 1);
}

void	put_in_b(t_ps *ps, int istack_a, int type)
{
	int	istack_b;

	istack_b = where_put_in_stack(&ps->b, ps->a.arr[istack_a], 0);
	make_it_easy(ps, type, istack_a, istack_b);
	px(&ps->b, &ps->a, 1);
}
