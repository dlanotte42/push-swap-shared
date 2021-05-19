/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:33:19 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/19 11:33:20 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace_(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' \
	 || c == '\f' || c == '\r' || c == ' ');
}

static int	check_result(unsigned long int result, int sign, int *error)
{
	if (sign == -1 && result > ((unsigned long)2147483648))
	{
		*error = 1;
		return (0);
	}
	else if (sign == 1 && result > 2147483647)
	{
		*error = 1;
		return (0);
	}
	return ((int)result * sign);
}

int	ft_atoi(const char *str, int *error)
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
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	*error = (str[i] != '\0');
	return (check_result(result, sign, error));
}
