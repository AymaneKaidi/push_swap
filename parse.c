/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 23:14:32 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/22 18:10:54 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	append_node(t_stack *a, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (false);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	if (a->size == 0)
	{
		a->top = node;
		a->bottom = node;
	}
	else
	{
		a->bottom->next = node;
		a->bottom = node;
	}
	a->size++;
	return (true);
}

static bool	has_duplicate(t_stack *a, int value)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->value == value)
			return (true);
		cur = cur->next;
	}
	return (false);
}

static void	free_split(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

static void	parse_numbers(t_ps *ps, const char *arg)
{
	char	**tokens;
	int		i;
	long	val;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		free_split(tokens);
		exit_error(ps);
	}
	i = 0;
	while (tokens[i])
	{
		if (!ft_atol_strict(tokens[i], &val)
			|| has_duplicate(&ps->a, (int)val)
			|| !append_node(&ps->a, (int)val))
		{
			free_split(tokens);
			exit_error(ps);
		}
		i++;
	}
	free_split(tokens);
}

void	parse_args(t_ps *ps, int argc, char **argv)
{
	int		i;
	bool	strat_set;

	i = 1;
	strat_set = false;
	while (i < argc)
	{
		if (parse_flag(ps, argv[i], &strat_set))
		{
			if (ps->a.size > 0)
				exit_error(ps);
		}
		else
			parse_numbers(ps, argv[i]);
		i++;
	}
	if (ps->a.size == 0)
		exit_error(ps);
}
