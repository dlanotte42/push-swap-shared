/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:40:57 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:35:53 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		size = 0;
	else
		size = size - start;
	if (size > len)
		size = len;
	mem = (char *)ft_calloc(size + 1, sizeof(char));
	if (mem)
		ft_memmove(mem, s + start, size);
	return (mem);
}
