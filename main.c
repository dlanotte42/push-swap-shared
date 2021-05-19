/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:31:32 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/19 10:59:07 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

int	main(int argc, char **argv)
{
	int		error;
	t_ps	*ps;
	int		nchunk;
	int		chunk_size;

	ps = check_args(argc, argv, &error);
	if (!error)
	{
		if (!ft_is_yet_sorted(ps))
		{
			if (ps->size <= 10)
				sort10loop(&ps->a, &ps->b, ps->size);
			else
			{
				set_limits(ps, &nchunk, &chunk_size);
				chunk_sort(ps, nchunk - 1, chunk_size);
			}
		}
	}
	remove_ps(ps);
}
