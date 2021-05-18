/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:45:09 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/17 18:18:18 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "main.h"

typedef struct s_list
{
	int				val;
	struct s_list	*next;
}				t_list;

typedef struct s_stack
{
	t_list			*first;
	t_list			*last;
	int				*arr;
	int				length;
	int				pos;
	int				sname;
}				t_stack;

typedef struct s_ps
{
	int				size;
	t_stack			a;
	t_stack			b;
	int				rest;
	int				*sorted;
}				t_ps;

#endif