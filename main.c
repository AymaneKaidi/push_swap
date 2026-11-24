#include "push_swap.h"
#include <stdio.h>

static void	print_state(t_ps *ps, const char *label)
{
	t_node	*cur;

	printf("=== %s (total_ops=%ld) ===\nA (%d): ",
		label, ps->total_ops, ps->a.size);
	cur = ps->a.top;
	while (cur)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("| B (%d): ", ps->b.size);
	cur = ps->b.top;
	while (cur)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	ft_bzero(&ps, sizeof(t_ps));
	ps.print_ops = true;
	parse_args(&ps, argc, argv);
	print_state(&ps, "Start");
	sa(&ps);
	pb(&ps);
	pb(&ps);
	rr(&ps);
	rrr(&ps);
	pa(&ps);
	pa(&ps);
	print_state(&ps, "End");
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}