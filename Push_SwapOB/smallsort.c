/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:53:42 by obadran           #+#    #+#             */
/*   Updated: 2024/09/07 16:11:44 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	tiny_sort(t_node **a)
{
	t_node	*max_node;

	max_node = find_max(*a);
	if (max_node == *a)
		ra(a, true);
	else if ((*a)->next == max_node)
		rra(a, true);
	if ((*a)->num > (*a)->next->num)
		sa(a, true);
}

void sort_stack(t_node **stack_a, t_node **stack_b) {
    int size = stack_size(*stack_a);  // Assume stack_size is a function that returns the number of elements in the stack

    if (size == 3) {
        tiny_sort(stack_a);  // Sort 3 elements
    } else if (size > 3) {
        // Use the more complex sorting algorithm for 4 or 5 elements
        turk_sort(stack_a, stack_b);  // Turk algorithm will handle larger stacks
    }
}
