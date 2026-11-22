#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_ps	ps;
	t_node	*cur;

	if (argc < 2)
		return (0);
	ft_bzero(&ps, sizeof(t_ps));
	ps.strategy = STRAT_ADAPTIVE;
	ps.print_ops = true;
	parse_args(&ps, argc, argv);
	printf("Strategy: %d | Bench: %d | Size: %d\n",
		ps.strategy, ps.bench, ps.a.size);
	cur = ps.a.top;
	while (cur)
	{
		printf("  node value = %d (index = %d)\n", cur->value, cur->index);
		cur = cur->next;
	}
	free_stack(&ps.a);
	return (0);
}
