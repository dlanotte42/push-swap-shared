/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:56:22 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:35:52 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;
	size_t	j;

	start = 0;
	j = start;
	while (start < ft_strlen(s1))
	{
		i = 0;
		while (i < ft_strlen(set))
		{
			while (s1[j] && s1[j] == set[i])
				j++;
			i++;
		}
		if (j == start)
			break ;
		start = j;
	}
	return (start);
}

static size_t	get_end(char const *s1, char const *set, size_t start)
{
	size_t	end;
	size_t	i;
	size_t	j;

	end = ft_strlen(s1) - 1;
	j = end;
	while (end > start)
	{
		i = 0;
		while (i < ft_strlen(set))
		{
			while (j > 0 && s1[j] == set[i])
				j--;
			i++;
		}
		if (j == end)
			break ;
		end = j;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set, start);
	return (ft_substr(s1, start, end - start + 1));
}
