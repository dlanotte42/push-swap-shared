/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:43:34 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/07 17:06:00 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H
# include "libft/libft.h"
# include "utilities2.h"

t_ps	*check_args(int argc, char **argv, int *res);
void	remove_ps(t_ps *ps);
int		pop(t_stack *stack);
void	push(t_stack *stack, int value);
#endif