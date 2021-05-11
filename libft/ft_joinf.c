/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:05:23 by gcarbone          #+#    #+#             */
/*   Updated: 2021/04/14 16:58:33 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinf(char *s1, char *s2, int freem)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (freem == 1)
		free(s1);
	else if (freem == 2)
		free(s2);
	else if (freem > 2)
	{
		free(s1);
		free(s2);
	}
	return (result);
}
