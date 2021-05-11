/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:17:10 by gcarbone          #+#    #+#             */
/*   Updated: 2021/04/14 17:08:25 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strindex(char *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	if (s[count] != c)
		return (-1);
	return (count);
}
