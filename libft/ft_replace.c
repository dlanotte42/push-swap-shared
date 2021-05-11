/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:18:00 by gcarbone          #+#    #+#             */
/*   Updated: 2021/04/21 15:29:59 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr2(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size_to_find;

	size_to_find = ft_strlen(needle);
	i = 0;
	if (!size_to_find)
		return (0);
	if (!len)
		return (-1);
	while (haystack[i] != '\0' && i <= (len - size_to_find))
	{
		if (ft_strncmp(haystack + i, needle, size_to_find) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_replace(const char *stack, const char *needle, char *replace)
{
	size_t	size_f;
	size_t	size_h;
	int		start;
	char	*result;

	result = NULL;
	size_f = ft_strlen(needle);
	size_h = ft_strlen(stack);
	start = ft_strnstr2(stack, needle, size_h);
	if (start >= 0)
	{
		result = ft_joinf(ft_substr(stack, 0, start), replace, 1);
		result = ft_joinf(result, \
			ft_substr(stack, start + size_f, size_h - start), 3);
	}
	return (result);
}
