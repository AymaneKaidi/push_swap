/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 16:08:52 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/22 16:40:18 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	set_strategy(t_ps *ps, t_strategy strat, bool *strat_set)
{
	if (*strat_set)
		exit_error(ps);
	*strat_set = true;
	ps->strategy = strat;
	return (true);
}

bool	parse_flag(t_ps *ps, const char *arg, bool *strat_set)
{
	if (ft_strcmp(arg, "--bench") == 0)
	{
		if (ps->bench)
			exit_error(ps);
		ps->bench = true;
		return (true);
	}
	if (ft_strcmp(arg, "--simple") == 0)
		return (set_strategy(ps, STRAT_SIMPLE, strat_set));
	if (ft_strcmp(arg, "--medium") == 0)
		return (set_strategy(ps, STRAT_MEDIUM, strat_set));
	if (ft_strcmp(arg, "--complex") == 0)
		return (set_strategy(ps, STRAT_COMPLEX, strat_set));
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (set_strategy(ps, STRAT_ADAPTIVE, strat_set));
	return (false);
}
