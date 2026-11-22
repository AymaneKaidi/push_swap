/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 17:23:30 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/22 15:23:25 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char)*s2);
}

bool	ft_atol_strict(const char *str, long *out)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (!str || !*str)
		return (false);
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
		if (!*str)
			return (false);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		res = res * 10 + (*str++ - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && (-res) < INT_MIN))
			return (false);
	}
	*out = res * sign;
	return (true);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*cur;

	if (!stack)
		return ;
	cur = stack->top;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	exit_error(t_ps *ps)
{
	if (ps)
	{
		free_stack(&ps->a);
		free_stack(&ps->b);
	}
	ft_putendl_fd("Error", 2);
	exit(1);
}
