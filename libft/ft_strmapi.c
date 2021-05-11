/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:37:13 by gcarbone          #+#    #+#             */
/*   Updated: 2021/04/14 17:07:58 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	result = ft_calloc(len + 1, sizeof(char));
	if (result != NULL)
	{
		i = 0;
		while (i < len)
		{
			result[i] = f(i, s[i]);
			i++;
		}
	}
	return (result);
}
