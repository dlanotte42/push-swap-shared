/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:50:18 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/01/19 17:41:36 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int num)
{
	int		size;

	size = 0;
	while (num > 9)
	{
		num = num / 10;
		size++;
	}
	size++;
	return (size);
}

static char	*ft_fill(char *numb_converted, int size, int num, int is_negative)
{
	numb_converted[size] = '\0';
	while (size)
	{
		if (is_negative > 1)
		{
			numb_converted[size - 1] = (((num % 10) + 1) + 48);
			is_negative = 1;
		}
		else
			numb_converted[size - 1] = (num % 10) + 48;
		num = num / 10;
		size--;
	}
	return (numb_converted);
}

char		*ft_itoa(int num)
{
	int			size;
	int			is_negative;
	char		*numb_converted;

	is_negative = 0;
	if (num == -2147483648)
	{
		is_negative = 2;
		num++;
		num = num * -1;
	}
	else if (num < 0)
	{
		is_negative++;
		num = num * -1;
	}
	size = ft_numlen(num);
	if (is_negative)
		size++;
	if (!(numb_converted = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_fill(numb_converted, size, num, is_negative);
	if (is_negative)
		numb_converted[0] = '-';
	return (numb_converted);
}
