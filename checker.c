/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:00:04 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/05/08 17:41:22 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_args (int ac, char **av)
{
	int	one_arg;
	int	more_args;
	int	j;

	one_arg = 0;
	more_args = 0;
	j = 0;
	if (ac == 2)
		one_arg = ft_one_arg(av, j);
	else if (ac > 2)
		more_args = ft_more_args(av);
	if ((one_arg == 1 || more_args == 1))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

void	ft_pars_arg(int ac, char **av, t_list **head, int j)
{
	int		i;
	t_list	*tmp;
	char	**arr;

	tmp = NULL;
	i = 1;
	j = 0;
	//if (ft_strncmp(av[1], "-v", 2) == 0)
	//	i = 2;
	while (i < ac)
	{
		arr = ft_split(av[i], ' ');
		while (arr[j])
		{
			/*if ((i == 1 || (i == 2 && ft_strncmp(av[1], "-v", 2) == 0))
				&& j == 0)
				*head = ft_lstnew(ft_atoi(arr[j]));
			else */
			ft_pars_arg2(arr, head, j, tmp);
			j = ft_pars_arg3(arr, j);
		}
		free(arr);
		i++;
		j = 0;
	}
}

void	ft_check_doubles(t_list *head)
{
	int		mem;
	t_list	*tmp1;
	t_list	*tmp2;

	if (head == NULL)
		return ;
	tmp1 = head;
	tmp2 = tmp1;
	mem = tmp1->content;
	while (tmp2->next)
	{
		while (tmp1->next)
		{
			if (tmp1->next->content == mem)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			tmp1 = tmp1->next;
		}
		tmp2 = tmp2->next;
		tmp1 = tmp2;
		mem = tmp1->content;
	}
}

int	main (int ac, char **av)
{
	char		*line;
	t_stacks	stacks;
	int			flag;

	if (ac == 1)
		exit(0);
	ft_check_args(ac, av);
	ft_pars_arg(ac, av, &stacks.head_a, 0);
}
