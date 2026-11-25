/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 09:47:39 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/25 11:20:42 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_idx;
	int	bits;

	max_idx = size - 1;
	bits = 0;
	while ((max_idx >> bits) != 0)
		bits++;
	return (bits);
}

static void	sort_bit(t_ps *ps, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((ps->a.top->index >> bit) & 1) == 0)
			pb(ps);
		else
			ra(ps);
		i++;
	}
	while (ps->b.size > 0)
		pa(ps);
}

void	sort_complex(t_ps *ps)
{
	int	max_bits;
	int	bit;

	if (ps->a.size < 2)
		return ;
	max_bits = get_max_bits(ps->a.size);
	bit = 0;
	while (bit < max_bits)
	{
		sort_bit(ps, bit, ps->a.size);
		bit++;
	}
}
