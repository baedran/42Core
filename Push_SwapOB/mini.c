/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:14:12 by obadran           #+#    #+#             */
/*   Updated: 2024/09/20 11:57:08 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	mini_sort(t_node **a)
{
	t_node	*max_node;

	max_node = find_max(*a);
	if (max_node == *a)
		ra(a, false);
	else if ((*a)->next == max_node)
		rra(a, false);
	if ((*a)->number > (*a)->next->number)
		sa(a, false);
}

// In mini.c
void tiny_sort(t_node **a)
{
    t_node *biggest = find_max(*a);

    if (biggest == *a)
        ra(a, false);
    else if (biggest == (*a)->next)
        rra(a, false);
    
    if ((*a)->number > (*a)->next->number)
        sa(a, false);
}