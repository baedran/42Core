/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:01:53 by obadran           #+#    #+#             */
/*   Updated: 2024/09/20 11:56:22 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_node	*find_min(t_node *node)
{
	long		min;
	t_node		*min_node;

	if (!node)
		return (NULL);
	min = LONG_MAX;
	while (node)
	{
		if (node->number < min)
		{
			min = node->number;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}
bool	stack_sorted(t_node *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->number > node->next->number)
			return (false);
		node = node->next;
	}
	return (true);
}

t_node	*find_max(t_node *node)
{
	long	max;
	t_node	*max_node;

	if (!node)
		return (NULL);
	max = LONG_MIN;
	while (node)
	{
		if (node->number > max)
		{
			max = node->number;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

int	stack_size(t_node *stack)
{
    int	size;
    t_node *current;
	
	size = 0;
	current = stack;
    while (current != NULL)
	{
        size++;
        current = current->next;
    }

    return (size);
}

// In node_a_init.c or stack_operations.c
t_node *get_cheapest(t_node *stack)
{
    t_node *cheapest = NULL;
    long min_cost = LONG_MAX;

    while (stack)
    {
        if (stack->push_price < min_cost)
        {
            min_cost = stack->push_price;
            cheapest = stack;
        }
        stack = stack->next;
    }
    return cheapest;
}
