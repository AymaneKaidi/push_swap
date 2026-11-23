/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:39:13 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/23 16:50:31 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	total_pairs;
	t_node	*i;
	t_node	*j;

	mistakes = 0;
	total_pairs = (long)a->size * (a->size - 1) / 2;
	i = a->top;
	if (a->size < 2)
		return (0.0);
	while (i)
	{
		j = i-> next;
		while (j)
		{
			if (i->index > j->index)
				mistakes++;
			j = j->next;
		}
		i = i-> next;
	}
	return ((double)mistakes / (double)total_pairs);
}
