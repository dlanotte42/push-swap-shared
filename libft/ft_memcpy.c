/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:36:13 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/19 11:36:14 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*ps;
	unsigned char	*pd;

	if (!dst && !src)
		return (0);
	ps = (unsigned char *)src;
	pd = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dst);
}
