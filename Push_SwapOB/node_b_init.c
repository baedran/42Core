/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_b_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:48:22 by obadran           #+#    #+#             */
/*   Updated: 2024/10/08 10:49:00 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_b_target_node(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number
				&& current_a->number < best_match_index)
			{
				best_match_index = current_a->number;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	node_b_init(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_b_target_node(a, b);
}
