/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:00:55 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:35:46 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = ft_strlen(src);
	if (dstsize <= 1)
	{
		if (dstsize)
			dst[0] = '\0';
		return (i);
	}
	if (i < dstsize - 1)
		dstsize = i + 1;
	ft_memcpy(dst, src, dstsize - 1);
	dst[dstsize - 1] = '\0';
	return (i);
}
