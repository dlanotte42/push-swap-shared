/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:45:44 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:35:16 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_string(unsigned int number, size_t *size, size_t sign)
{
	char	*str;

	*size = 2 + sign;
	while (number / 10 > 0)
	{
		(*size)++;
		number /= 10;
	}
	str = (char *)malloc((*size) * sizeof(char *));
	if (str)
	{
		if (sign)
			str[0] = '-';
		str[*size - 1] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	size_t			sign;
	size_t			lenght;
	char			*result;

	lenght = 0;
	sign = (n < 0);
	number = (unsigned int)n;
	if (sign)
	{
		number = ~(number - 1);
	}
	result = get_string(number, &lenght, sign);
	if (result != NULL)
	{
		while (--lenght > sign)
		{
			result[lenght - 1] = '0' + (number % 10);
			number /= 10;
		}
	}
	return (result);
}
