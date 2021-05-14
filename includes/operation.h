/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:40:35 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/14 11:27:45 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H
# include "main.h"

void	sx(t_stack	*stack);
void	px(t_stack	*a, t_stack	*b);
void	rx(t_stack	*stack, int flag);
void	rrx(t_stack	*stack, int flag);
void	ss(t_stack	*a, t_stack	*b);
void	rr(t_stack	*a, t_stack	*b);
void	rrr(t_stack *a, t_stack *b);

#endif