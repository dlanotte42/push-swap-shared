#include "includes/main.h"

void	push(t_stack *stack, int value)
{
	t_list	*new_;

	new_ = (t_list *)malloc(sizeof(t_list));
	new_->next = stack->first;
	new_->val = value;
	if (stack->last == NULL)
		stack->last = new_;
	stack->first = new_;
	stack->arr[stack->length] = value;
	stack->length++;
}

int	pop(t_stack *stack)
{
	t_list	*tmp;
	int		value;

	value = 0;
	if (stack->first != NULL)
	{
		tmp = stack->first;
		value = tmp->val;
		stack->first = (stack->first)->next;
		free(tmp);
		if (stack->first == NULL || (stack->first)->next == NULL)
			stack->last = stack->first;
		stack->length--;
	}
	return (value);
}

t_ps	*init_ps(int size)
{
	t_ps	*ps;

	ps = (t_ps *) malloc(sizeof(t_ps));
	if (ps != NULL)
	{
		ps->a.first = NULL;
		ps->a.last = NULL;
		ps->b.first = NULL;
		ps->b.last = NULL;
		ps->size = size;
		ps->a.length = 0;
		ps->a.sname = 0;
		ps->b.sname = 1;
		ps->b.length = 0;
		ps->a.pos = 0;
		ps->b.pos = 0;
		ps->a.arr = (int *) malloc(sizeof(int) * size);
		ps->b.arr = (int *) malloc(sizeof(int) * size);
		ps->sorted = (int *) malloc(sizeof(int) * size);
	}
	return (ps);
}

void	remove_ps(t_ps *ps)
{
	t_list *node;

	node = ps->a.first;
	while (node != NULL)
	{
		ps->a.first = node->next;
		free(node);
		node = ps->a.first;
	}
	node = ps->b.first;
	while (node != NULL)
	{
		ps->b.first = node->next;
		free(node);
		node = ps->b.first;
	}
	free(ps);
}

char	**get_args(int *argc, char **argv)
{
	char 	**args;
	int		i;

	if (*argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*argc = ft_table_len(args);
	}
	else
	{
		args = (char **) malloc((*argc) * sizeof(char *));
		args[*argc - 1] = NULL;
		*argc -= 1;
		i = -1;
		while (++i < *argc)
				args[i] = argv[i + 1];
	}
	return (args);
}

t_ps	*ft_error(int argc, char **argv, int *error)
{
	int		i;
	int		num;
	t_ps	*ps;
	char 	**args;

	*error = 1;
	ps = NULL;
	if (argc >= 2)
	{
		args = get_args(&argc, argv);
		i = -1;
		ps = init_ps(argc);
		*error = 0;
		while (!*error && ++i < argc)
		{
			num = ft_atoi(args[i], error);
			*error = (*error || fval_index(ps->a.arr, ps->a.length, num) != -1);
			if (!*error)
				push(&ps->a, num);
		}
	}
	return (ps);
}

t_ps	*check_args(int argc, char **argv, int *error)
{
	int		i;
	t_ps	*ps;
	t_list	*ptr;

	ps = ft_error(argc, argv, error);
	if (*error)
		ft_putstr_fd("Error\n", 2);
	else
	{
		if (ps->a.length > 1)
			reverse(ps->a.first, &ps->a.first, &ps->a.last);
		i = -1;
		ptr = ps->a.first;
		while (++i < ps->a.length)
		{
			ps->a.arr[ps->a.length - 1 - i] = ptr->val;
			ps->sorted[i] = ptr->val;
			ptr = ptr->next;
		}
		ft_sort_int_tab(ps->sorted, ps->a.length, 0);
	}
	return (ps);
}