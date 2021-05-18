/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:58:53 by dlanotte          #+#    #+#             */
/*   Updated: 2021/05/18 17:58:17 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_MAIN_FUNCTIONS_H
# define PUSH_MAIN_FUNCTIONS_H
# include "main.h"

int		where_put_in_stack(t_stack *stack, int value, int asc);
int		get_min_move(t_ps *ps, int *type, int from, int flag);
int		best_choice(t_ps *ps, int nchunk, int chunk_size, int *index);
void	put_in_a(t_ps *ps, int istack_b, int type);
void	put_in_b(t_ps *ps, int istack_a, int type);
void	chunk_sort(t_ps *ps, int nchunk, int chunk_size);
void	sort10loop(t_stack *first, t_stack *second, int size);

#endif