/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:31:32 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:41:41 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

int	main(int argc, char **argv)
{
	int		error;
	t_ps	*ps;
	int		nchunk;
	int		chunk_size;

	if (argc == 2 && !argv[1][0])
		return (0);
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
