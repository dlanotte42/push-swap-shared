#include "utilities.h"
# include "op2.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int		res;
	t_ps	*ps;
	int 	i;
	t_list *node;

	ps = check_args(argc, argv, &res);
	if (res)
	{
		i = -1;
		node = ps->a.first;
		print_stacks(&ps->a, &ps->b, "");
		sx(&ps->a);
		print_stacks(&ps->a, &ps->b, "swap a");
		px(&ps->b, &ps->a);
		print_stacks(&ps->a, &ps->b, "push b");
		rx(&ps->a);
		print_stacks(&ps->a, &ps->b, "rotate a");
		rx(&ps->b);
		print_stacks(&ps->a, &ps->b, "rotate b");
		px(&ps->b, &ps->a);
		print_stacks(&ps->a, &ps->b, "push b");
		rrx(&ps->a);
		print_stacks(&ps->a, &ps->b, "reverse rotate a");
		rrx(&ps->b);
		print_stacks(&ps->a, &ps->b, "reverse rotate b");
	}
	remove_ps(ps);
}