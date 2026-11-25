/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 11:09:51 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/25 11:21:15 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_adaptive(t_ps *ps)
{
	if (ps->a.size <= 5 || ps->disorder < 0.2)
		sort_simple(ps);
	else if (ps->disorder < 0.5)
		sort_medium(ps);
	else
		sort_complex(ps);
}

static void	dispatch_sort(t_ps *ps)
{
	if (ps->strategy == STRAT_SIMPLE)
		sort_simple(ps);
	else if (ps->strategy == STRAT_MEDIUM)
		sort_medium(ps);
	else if (ps->strategy == STRAT_COMPLEX)
		sort_complex(ps);
	else
		run_adaptive(ps);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	ft_bzero(&ps, sizeof(t_ps));
	ps.strategy = STRAT_ADAPTIVE;
	ps.print_ops = true;
	parse_args(&ps, argc, argv);
	index_stack(&ps.a);
	ps.disorder = compute_disorder(&ps.a);
	if (ps.disorder > 0.0)
		dispatch_sort(&ps);
	if (ps.bench)
		print_bench(&ps);
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}
