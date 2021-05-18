/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:58:53 by dlanotte          #+#    #+#             */
/*   Updated: 2021/05/18 17:01:24 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_MAIN_FUNCTIONS_H
# define PUSH_MAIN_FUNCTIONS_H
# include "main.h"

int	where_put_in_stack(t_stack *stack, int value, int asc);
int	get_min_move(t_ps *ps, int *type, int from, int flag);

#endif