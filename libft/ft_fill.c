/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:13:26 by gcarbone          #+#    #+#             */
/*   Updated: 2021/04/14 16:56:49 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill(int n, char c)
{
	char	*str;
	int		i;

	if (n <= 0)
		return (ft_strdup(""));
	i = 0;
	str = (char *)ft_calloc(n + 1, sizeof(char));
	if (str != NULL)
	{
		while (i < n)
		{
			str[i] = c;
			i++;
		}
		return (str);
	}
	return (NULL);
}
