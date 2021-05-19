/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:36:26 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/19 11:36:27 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ts;
	unsigned char	*td;

	ts = (unsigned char *)src;
	td = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		td[i] = ts[i];
		if (ts[i] == (unsigned char)c)
			return (td + i + 1);
		i++;
	}
	return (NULL);
}
