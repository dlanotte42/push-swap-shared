/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:25:49 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/05/08 17:32:23 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

ft_one_arg(char **av, int j)
{
    while (av[1][j])
	{
		if ((ft_isalpha(av[1][j]))
		|| (!(ft_isdigit(av[1][j])) && (av[1][j] != ' ')
		&& (av[1][j] != '-')) || ((ft_isdigit(av[1][j]))
		&& ((av[1][j + 1] != ' ') && (!(ft_isdigit(av[1][j])))))
		|| ((av[1][j] == '-') && ((av[1][j - 1])
		&& (av[1][j - 1] != ' '))) || ((av[1][j] == '-')
		&& (av[1][j + 1]) && (!ft_isdigit(av[1][j + 1]))))
			return (1);
		j++;
	}
	return (0);
}

ft_more_args(char **av)
{
    int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (((!ft_strcmp(av[i], "-v")) && i != 1) || (av[1][2] \
				&& !(ft_strncmp(av[1], "-v", 2))) || ((((av[i][1]) \
				&& av[i][0] == '-') && (!ft_isdigit(av[i][1]))) \
				&& ((av[i][1] != 'v'))) || (ft_isalpha(av[i][j]) && i != 1) \
				|| ft_isalpha(av[i][0]) || (ft_isdigit(av[i][j]) \
				&& av[i][j + 1] && av[i][j + 1] != ' ' \
				&& !ft_isdigit(av[i][j + 1])) || (ft_isdigit(av[i][j]) \
				&& av[i][j - 1] && av[i][j - 1] != ' ' \
				&& !ft_isdigit(av[i][j - 1]) && av[i][j - 1] != '-') \
				|| (!(ft_isdigit(av[i][0])) && (av[i][0] != '-')) \
				|| (av[i][0] == '-' && !av[i][1]))
				return (1);
			j++;
		}
	}
	return (0);
}