/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:11:17 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:35:29 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_(unsigned int number, int fd)
{
	int		mod;
	int		quotient;
	char	c;

	quotient = number / 10;
	mod = number % 10;
	if (quotient > 0)
		print_(number / 10, fd);
	c = '0' + mod;
	ft_putchar_fd(c, fd);
}

static void	ft_putnbr(int nb, int fd)
{
	unsigned int	number;
	int				flag;

	flag = (nb < 0);
	number = (unsigned int)nb;
	if (flag)
	{
		number = ~(number - 1);
		ft_putchar_fd('-', fd);
	}
	print_(number, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
