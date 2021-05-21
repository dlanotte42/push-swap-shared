/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:45:59 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:35:36 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;

	mem = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(const char));
	if (mem)
		ft_memmove(mem, s1, ft_strlen(s1));
	return (mem);
}
