/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 09:57:29 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/25 10:10:35 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_long_fd(long n, int fd)
{
	if (n >= 10)
		put_long_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

static void	print_disorder_fd(double disorder, int fd)
{
	long	hundredths;

	hundredths = (long)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder: ", fd);
	put_long_fd(hundredths / 100, fd);
	ft_putchar_fd('.', fd);
	if (hundredths % 100 < 10)
		ft_putchar_fd('0', fd);
	put_long_fd(hundredths % 100, fd);
	ft_putstr_fd("%\n", fd);
}

static void	print_strategy_fd(t_ps *ps, int fd)
{
	ft_putstr_fd("[bench] strategy: ", fd);
	if (ps->strategy == STRAT_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", fd);
	else if (ps->strategy == STRAT_MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", fd);
	else if (ps->strategy == STRAT_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", fd);
	else if (ps->strategy == STRAT_ADAPTIVE)
	{
		if (ps->a.size <= 5 || ps->disorder < 0.2)
			ft_putstr_fd("Adaptive / O(n^2)\n", fd);
		else if (ps->disorder < 0.5)
			ft_putstr_fd("Adaptive / O(n√n)\n", fd);
		else
			ft_putstr_fd("Adaptive / O(n log n)\n", fd);
	}
}

static void	print_op_counts_fd(t_ps *ps, int fd)
{
	ft_putstr_fd("[bench] sa: ", fd);
	put_long_fd(ps->op_counts[OP_SA], fd);
	ft_putstr_fd("  sb: ", fd);
	put_long_fd(ps->op_counts[OP_SB], fd);
	ft_putstr_fd("  ss: ", fd);
	put_long_fd(ps->op_counts[OP_SS], fd);
	ft_putstr_fd("  pa: ", fd);
	put_long_fd(ps->op_counts[OP_PA], fd);
	ft_putstr_fd("  pb: ", fd);
	put_long_fd(ps->op_counts[OP_PB], fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("[bench] ra: ", fd);
	put_long_fd(ps->op_counts[OP_RA], fd);
	ft_putstr_fd("  rb: ", fd);
	put_long_fd(ps->op_counts[OP_RB], fd);
	ft_putstr_fd("  rr: ", fd);
	put_long_fd(ps->op_counts[OP_RR], fd);
	ft_putstr_fd("  rra: ", fd);
	put_long_fd(ps->op_counts[OP_RRA], fd);
	ft_putstr_fd("  rrb: ", fd);
	put_long_fd(ps->op_counts[OP_RRB], fd);
	ft_putstr_fd("  rrr: ", fd);
	put_long_fd(ps->op_counts[OP_RRR], fd);
	ft_putchar_fd('\n', fd);
}

void	print_bench(t_ps *ps)
{
	print_disorder_fd(ps->disorder, 2);
	print_strategy_fd(ps, 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	put_long_fd(ps->total_ops, 2);
	ft_putchar_fd('\n', 2);
	print_op_counts_fd(ps, 2);
}
