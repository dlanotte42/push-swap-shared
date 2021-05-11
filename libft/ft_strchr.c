/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:46:40 by gcarbone          #+#    #+#             */
/*   Updated: 2021/01/12 18:46:43 by gcarbone         ###   ########.fr       */
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
