/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:42:44 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:35:41 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	dstsize;

	if (!s1 || !s2)
		return (NULL);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(dstsize * sizeof(char));
	if (dst)
	{
		ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
		ft_strlcat(dst, s2, dstsize);
	}
	return (dst);
}
