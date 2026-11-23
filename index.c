/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:00:06 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/23 15:26:45 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_next_min(t_stack *a)
{
	t_node	*cur;
	t_node	*min;

	cur = a->top;
	min = NULL;
	while (cur)
	{
		if (cur->index == -1 && (!min || cur->value < min->value))
			min = cur;
		cur = cur->next;
	}
	return (min);
}

void	index_stack(t_stack *a)
{
	int		idx;
	t_node	*min;

	idx = 0;
	min = get_next_min(a);
	while (min)
	{
		min->index = idx;
		idx++;
		min = get_next_min(a);
	}
}