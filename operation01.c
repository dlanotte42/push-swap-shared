/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:38:14 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:36:13 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

void	ss(t_stack	*a, t_stack	*b, int flag)
{
	sx(a, 0);
	sx(b, 0);
	if (flag)
		ft_putstr_fd("ss\n", 1);
}

void	rr(t_stack	*a, t_stack	*b, int flag)
{
	rx(a, 0);
	rx(b, 0);
	if (flag)
		ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack *a, t_stack *b, int flag)
{
	rrx(a, 0);
	rrx(b, 0);
	if (flag)
		ft_putstr_fd("rrr\n", 1);
}
