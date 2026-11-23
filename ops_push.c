/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:44:36 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/23 18:16:03 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_node(t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (src->size == 0)
		return ;
	node = src->top;
	src->top = node->next;
	src->size--;
	if (src->size == 0)
		src->bottom = NULL;
	if (dst->size == 0)
		dst->bottom = node;
	node->next = dst->top;
	dst->top = node;
	dst->size++;
}

void	pa(t_ps *ps)
{
	if (ps->b.size == 0)
		return ;
	push_node(&ps->b, &ps->a);
	record_op(ps, OP_PA, "pa");
}

void	pb(t_ps *ps)
{
	if (ps->a.size == 0)
		return ;
	push_node(&ps->a, &ps->b);
	record_op(ps, OP_PB, "pb");
}