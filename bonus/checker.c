/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:31:27 by gcarbone          #+#    #+#             */
/*   Updated: 2021/05/21 16:53:26 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main_bonus.h"

static void	ft_is_sorted(t_ps *ps)
{
	int	index;

	index = 0;
	if (ps->a.length != ps->size)
		return (ft_putstr_fd("KO\n", 1));
	while (index < ps->size && ps->a.arr[index] == ps->sorted[index])
		index++;
	if (index < ps->size)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
}

static void	ft_functions(int index_op, t_ps *ps)
{
	if (index_op == 0)
		sx(&ps->a, 0);
	else if (index_op == 1)
		sx(&ps->b, 0);
	else if (index_op == 2)
		ss(&ps->a, &ps->b, 0);
	else if (index_op == 3)
		px(&ps->a, &ps->b, 0);
	else if (index_op == 4)
		px(&ps->b, &ps->a, 0);
	else if (index_op == 5)
		rx(&ps->a, 0);
	else if (index_op == 6)
		rx(&ps->b, 0);
	else if (index_op == 7)
		rr(&ps->a, &ps->b, 0);
	else if (index_op == 8)
		rrx(&ps->a, 0);
	else if (index_op == 9)
		rrx(&ps->b, 0);
	else if (index_op == 10)
		rrr(&ps->a, &ps->b, 0);
}

static int	ft_check_operations(char **operations, int index, char *line)
{
	char	*op;

	op = operations[index];
	if (op == NULL)
		return (-1);
	if ((ft_strlen(line) == ft_strlen(op)) \
		&& !ft_strncmp(line, op, ft_strlen(op)))
		return (index);
	return (ft_check_operations(operations, index + 1, line));
}

static int	ft_parse_input(t_ps *ps)
{
	char	**line;
	int		flag;
	char	**operations;
	int		index_op;

	operations = ft_split("sa,sb,ss,pa,pb,ra,rb,rr,rra,rrb,rrr", ',');
	line = malloc(sizeof(char *));
	flag = 1;
	while (flag > 0)
	{
		flag = get_next_line(0, line);
		if (flag > 0)
		{
			index_op = ft_check_operations(operations, 0, *line);
			if (index_op > -1)
				ft_functions(index_op, ps);
			else
				flag = -2;
		}
		free(*line);
	}
	free_table(operations);
	free(line);
	return (flag);
}

int	main(int argc, char **argv)
{
	int		error;
	t_ps	*ps;
	int		flag;

	if (argc == 2 && !argv[1][0])
		return (0);
	ps = check_args(argc, argv, &error);
	if (error)
		return (0);
	flag = ft_parse_input(ps);
	if (flag < 0)
		ft_putstr_fd("Error\n", 2);
	else
		ft_is_sorted(ps);
	remove_ps(ps);
	return (0);
}
