/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:20:01 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/22 18:11:16 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_ps
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	bool		bench;
	bool		print_ops;
	double		disorder;
	long		op_counts[11];
	long		total_ops;
}	t_ps;

int		ft_strcmp(const char *s1, const char *s2);
bool	ft_atol_strict(const char *str, long *out);
void	free_stack(t_stack *stack);
void	exit_error(t_ps *ps);
bool	parse_flag(t_ps *ps, const char *arg, bool *strat_set);
void	parse_args(t_ps *ps, int argc, char **argv);
#endif
