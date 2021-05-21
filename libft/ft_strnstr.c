/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:20:21 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:35:49 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size_to_find;

	size_to_find = ft_strlen(needle);
	i = 0;
	if (!size_to_find)
		return ((char *)(haystack));
	if (!len)
		return (0);
	while (haystack[i] != '\0' && i <= (len - size_to_find))
	{
		if (ft_strncmp(haystack + i, needle, size_to_find) == 0)
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
