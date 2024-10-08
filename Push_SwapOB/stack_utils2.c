/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:43:43 by obadran           #+#    #+#             */
/*   Updated: 2024/10/08 12:32:02 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_cheapest(t_node *stack)
{
	t_node	*cheapest;
	long	min_cost;

	cheapest = NULL;
	min_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < min_cost)
		{
			min_cost = stack->push_price;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}
