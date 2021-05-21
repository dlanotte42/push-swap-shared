/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:17:10 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:35:40 by fd-agnes         ###   ########.fr       */
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
