/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:11:50 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/03 17:24:10 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "op2.h"

void ss(t_stack	*a, t_stack	*b)
{
	sx(a);
	sx(b);
}

void rr(t_stack	*a, t_stack	*b)
{
	rx(a);
	rx(b);
}

void rrr(t_stack *a, t_stack *b)
{
	rrx(a);
	rrx(b);
}