/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 17:33:20 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/24 18:26:33 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a.top->index;
	b = ps->a.top->next->index;
	c = ps->a.bottom->index;
	if (a > b && a > c)
		ra(ps);
	else if (b > a && b > c)
		rra(ps);
	if (ps->a.top->index > ps->a.top->next->index)
		sa(ps);
}

static int	find_min_pos(t_stack *a)
{
	t_node	*cur;
	int		min_idx;
	int		min_pos;
	int		pos;

	cur = a->top;
	min_idx = cur->index;
	min_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index < min_idx)
		{
			min_idx = cur->index;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}

static void	push_min_to_b(t_ps *ps)
{
	int	pos;
	int	rev;

	pos = find_min_pos(&ps->a);
	if (pos <= ps->a.size / 2)
	{
		while (pos-- > 0)
			ra(ps);
	}
	else
	{
		rev = ps->a.size - pos;
		while (rev-- > 0)
			rra(ps);
	}
	pb(ps);
}

void	sort_simple(t_ps *ps)
{
	if (ps->a.size < 2)
		return ;
	if (ps->a.size == 2)
	{
		if (ps->a.top->index > ps->a.top->next->index)
			sa(ps);
		return ;
	}
	while (ps->a.size > 3)
		push_min_to_b(ps);
	sort_three(ps);
	while (ps->b.size > 0)
		pa(ps);
}