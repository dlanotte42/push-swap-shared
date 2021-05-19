/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:32:00 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/19 11:32:02 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H
# include "main.h"

void	sx(t_stack	*stack, int flag);
void	rx(t_stack	*stack, int flag);
void	rrx(t_stack	*stack, int flag);
void	px(t_stack	*a, t_stack	*b, int flag);
void	ss(t_stack	*a, t_stack	*b, int flag);
void	rr(t_stack	*a, t_stack	*b, int flag);
void	rrr(t_stack *a, t_stack *b, int flag);

#endif