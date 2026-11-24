/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 18:31:16 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/24 19:00:39 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) <= n / (r + 1))
		r++;
	return (r);
}

static int	find_max_pos(t_stack *b)
{
	t_node	*cur;
	int		max_idx;
	int		max_pos;
	int		pos;

	cur = b->top;
	max_idx = cur->index;
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index > max_idx)
		{
			max_idx = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

static void	push_chunks_to_b(t_ps *ps, int range)
{
	int	i;

	i = 0;
	while (ps->a.size > 0)
	{
		if (ps->a.top->index <= i)
		{
			pb(ps);
			rb(ps);
			i++;
		}
		else if (ps->a.top->index <= i + range)
		{
			pb(ps);
			i++;
		}
		else
			ra(ps);
	}
}

static void	pull_max_to_a(t_ps *ps)
{
	int	pos;
	int	rev;

	while (ps->b.size > 0)
	{
		pos = find_max_pos(&ps->b);
		if (pos <= ps->b.size / 2)
		{
			while (pos-- > 0)
				rb(ps);
		}
		else
		{
			rev = ps->b.size - pos;
			while (rev-- > 0)
				rrb(ps);
		}
		pa(ps);
	}
}

void	sort_medium(t_ps *ps)
{
	int	range;

	if (ps->a.size < 2)
		return ;
	if (ps->a.size == 2)
	{
		if (ps->a.top->index > ps->a.top->next->index)
			sa(ps);
		return ;
	}
	range = ft_isqrt(ps->a.size) * 3 / 2;
	if (range < 1)
		range = 1;
	push_chunks_to_b(ps, range);
	pull_max_to_a(ps);
}
