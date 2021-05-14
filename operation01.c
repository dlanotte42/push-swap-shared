/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:11:50 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/14 11:27:21 by gcarbone         ###   ########.fr       */
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
	rx(a, 0);
	rx(b, 0);
	printf("\ndouble rotate");
}

void	rrr(t_stack *a, t_stack *b)
{
	rrx(a, 0);
	rrx(b, 0);
	printf("\ndouble reverse rotate");
}
