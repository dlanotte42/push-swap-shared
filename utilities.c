# include "utilities.h"

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
	t_ps *ps;

	ps = (t_ps *) malloc(sizeof(t_ps));
	if (ps != NULL)
	{
		ps->a.first = NULL;
		ps->a.last = NULL;
		ps->b.first = NULL;
		ps->b.last = NULL;
		ps->size = size;
		ps->a.length = 0;
		ps->b.length = 0;
		ps->a.pos = 0;
		ps->b.pos = 0;
		ps->a.left = 0;
		ps->a.right = size - 1;
		ps->a.n_ok = 0;
		ps->a.pivot = 0;
		ps->b.ipivot = 0;
		ps->b.left = 0;
		ps->b.right = 0;
		ps->b.n_ok = 0;
		ps->b.pivot = 0;
		ps->a.arr = (int *) malloc(sizeof(int) * size);
		ps->a.arr2 = (int *) malloc(sizeof(int) * size);
		ps->b.arr = (int *) malloc(sizeof(int) * size);
		ps->sorted = (int *) malloc(sizeof(int) * size);
		ps->a.sorted = (int *) malloc(sizeof(int) * size);
		ps->b.sorted = (int *) malloc(sizeof(int) * size);
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

t_ps	*check_args(int argc, char **argv, int *res)
{
	int		i;
	int		num;
	int		flag;
	t_ps	*ps;
	t_list	*ptr;

	ps = init_ps(argc - 1);
	i = 0;
	flag = (argc > 1);
	*res = 1;
	while (flag && ++i < argc)
	{
		num = ft_atoi(argv[i]);
		flag = (num >= 0);
		if (flag)
			push(&ps->a, num);
	}
	if (!flag)
	{
		write(1, "Error\n", 6);
		*res = 0;
	}
	else
	{
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
		i = -1;
		/*while (++i < ps->a.length)
		{
			printf("%d, ",ps->sorted[i]);
		}*/
	}
		
	return (ps);
}