/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:40:34 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/19 11:40:36 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*pt;

	i = 0;
	pt = (char *)s;
	while (pt[i] != '\0' && pt[i] != (unsigned char)c)
	{
		i++;
	}
	if (pt[i] == (unsigned char)c)
		return (pt + i);
	return (0);
}
