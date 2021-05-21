/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:40:34 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:35:35 by fd-agnes         ###   ########.fr       */
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
