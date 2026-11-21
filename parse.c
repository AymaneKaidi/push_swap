/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaidi <akaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 23:14:32 by akaidi            #+#    #+#             */
/*   Updated: 2026/11/20 23:20:46 by akaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool append_node(t_stack *a, int value)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (false);
    node->value = value;
    node->index = -1;
    node->next = NULL;
    
        
}
