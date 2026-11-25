/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:05:46 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/25 11:20:49 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_stack *s)
{
	t_node	*prev;
	t_node	*last;

	if (s->size < 2)
		return ;
	prev = s->top;
	while (prev->next != s->bottom)
		prev = prev->next;
	last = s->bottom;
	prev->next = NULL;
	last->next = s->top;
	s->top = last;
	s->bottom = prev;
}

void	rra(t_ps *ps)
{
	if (ps->a.size < 2)
		return ;
	rev_rotate_stack(&ps->a);
	record_op(ps, OP_RRA, "rra");
}

void	rrb(t_ps *ps)
{
	if (ps->b.size < 2)
		return ;
	rev_rotate_stack(&ps->b);
	record_op(ps, OP_RRB, "rrb");
}

void	rrr(t_ps *ps)
{
	if (ps->a.size < 2 && ps->b.size < 2)
		return ;
	rev_rotate_stack(&ps->a);
	rev_rotate_stack(&ps->b);
	record_op(ps, OP_RRR, "rrr");
}
