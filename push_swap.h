/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:48:39 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/05/08 17:48:49 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "./minilibft/minilibft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}		t_list;

typedef struct s_stacks
{
	t_list	*head_a;
	t_list	*head_b;
}		t_stacks;

void	ft_check_args (int ac, char **av);
int		ft_one_arg(char **av, int j);
int		ft_more_args(char **av);
void	ft_pars_arg(int ac, char **av, t_list **head, int j);
int		ft_strcmp(char *s1, char *s2);
void	ft_pars_arg2(char **arr, t_list **head, int j, t_list *tmp);
int		ft_pars_arg3(char **arr, int j);

#endif
