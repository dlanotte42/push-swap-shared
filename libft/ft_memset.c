/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:35:41 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/19 11:35:42 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len > 0)
	{
		len--;
		str[len] = (unsigned char)c;
	}
	return (b);
}
