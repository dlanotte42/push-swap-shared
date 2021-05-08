/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:54:31 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/05/08 17:04:37 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H
# include <stdlib.h>

int		ft_atoi(const char *str);
char	*ft_itoa(int num);
char	**ft_split(char const *s, char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);

#endif
