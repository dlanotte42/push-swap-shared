/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:49:17 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/05/08 17:52:41 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pars_arg2(char **arr, t_list **head, int j, t_list *tmp)
{
	tmp = ft_lstnew(ft_atoi(arr[j]));
	ft_lstadd_back(*head, tmp);
}

int	ft_pars_arg3(char **arr, int j)
{
	free(arr[j]);
	j++;
	return (j);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
