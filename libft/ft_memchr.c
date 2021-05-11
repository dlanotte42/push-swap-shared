/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:04:05 by gcarbone          #+#    #+#             */
/*   Updated: 2021/04/14 17:02:59 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	ps = (unsigned char *)s;
	i = 0;
	while (i < n && ps[i] != (unsigned char)c)
	{
		i++;
	}
	if (i < n)
		return ((void *)(ps + i));
	return (NULL);
}
