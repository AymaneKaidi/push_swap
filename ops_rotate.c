/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:17:08 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/24 16:05:29 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *s)
{
	t_node	*first;

	if (s->size < 2)
		return ;
	first = s->top;
	s->top = first->next;
	first->next = NULL;
	s->bottom->next = first;
	s->bottom = first;
}

void	ra(t_ps *ps)
{
	if (ps->a.size < 2)
		return ;
	rotate_stack(&ps->a);
	record_op(ps, OP_RA, "ra");
}

void	rb(t_ps *ps)
{
	if (ps->b.size < 2)
		return ;
	rotate_stack(&ps->b);
	record_op(ps, OP_RB, "rb");
}

void	rr(t_ps *ps)
{
	if (ps->a.size < 2 && ps->b.size < 2)
		return ;
	rotate_stack(&ps->a);
	rotate_stack(&ps->b);
	record_op(ps, OP_RR, "rr");
}
