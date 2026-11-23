/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:55:29 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/23 17:44:24 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	record_op(t_ps *ps, t_op op, const char *name)
{
	ps->op_counts[op]++;
	ps->total_ops++;
	if (ps->print_ops)
		ft_putendl_fd((char *)name, 1);
}

static void	swap_nodes(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	s->top = second;
	if (s->size == 2)
		s->bottom = first;
}

void	sa(t_ps *ps)
{
	if (ps->a.size < 2)
		return ;
	swap_nodes(&ps->a);
	record_op(ps, OP_SA, "sa");
}

void	sb(t_ps *ps)
{
	if (ps->b.size < 2)
		return ;
	swap_nodes(&ps->b);
	record_op(ps, OP_SB, "sb");
}

void	ss(t_ps *ps)
{
	if (ps->a.size < 2 && ps->b.size < 2)
		return ;
	swap_nodes(&ps->a);
	swap_nodes(&ps->b);
	record_op(ps, OP_SS, "ss");
}