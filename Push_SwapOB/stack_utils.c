/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:01:53 by obadran           #+#    #+#             */
/*   Updated: 2024/09/07 00:31:54 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(t_node *node)
{
	long	max;
	t_node	*max_node;

	if (!node)
		return (NULL);
	max = LONG_MIN;
	while (node)
	{
		if (node->num > max)
		{
			max = node->num;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

int stack_size(t_node *stack)
{
    int size = 0;
    t_node *current = stack;

    // Traverse the stack and count each node
    while (current != NULL)
	{
        size++;
        current = current->next;
    }

    return size;
}
