/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:11:50 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/12 18:09:24 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

void	ss(t_stack	*a, t_stack	*b)
{
	sx(a);
	sx(b);
}

void	rr(t_stack	*a, t_stack	*b)
{
	rx(a);
	rx(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rrx(a);
	rrx(b);
}
