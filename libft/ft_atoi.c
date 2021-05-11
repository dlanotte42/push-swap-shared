/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:55:45 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/04 11:24:41 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace_(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' \
	 || c == '\f' || c == '\r' || c == ' ');
}

static int	check_result(unsigned long int result, int sign)
{
	if (sign == -1 && result >= ((unsigned long)LONG_MAX + 1))
		return (-1);
	else if (result > LONG_MAX)
		return (-1);
	return ((int)result * sign);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && isspace_(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 + ((str[i] == '-') * -2);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (check_result(result, sign));
}
