/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 00:01:50 by obadran           #+#    #+#             */
/*   Updated: 2024/09/07 16:11:26 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void calculate_push_cost(t_node *stack_a, t_node *stack_b)
{
    t_node *current = stack_a;
    int stack_a_size = stack_size(stack_a);
    //int stack_b_size = stack_size(stack_b);

    while (current)
	{
        int index = current->index;

        // Calculate the cost to bring this node to the top of stack_a
        if (index <= stack_a_size / 2)
		{
            current->push_cost = index;  // Rotate (cost is index steps)
        } else
		{
            current->push_cost = stack_a_size - index;  // Reverse rotate (cost is the remaining steps)
        }

        // Add the cost to place it in the correct position in stack_b
        // This logic depends on how you determine the correct position in stack_b
        current->push_cost += calculate_position_cost(stack_b, current->num);

        current = current->next;
    }
}

// Calculate the cost to place the number in the correct position in stack_b
int calculate_position_cost(t_node *stack_b, int num)
{
    t_node *current = stack_b;
    int cost = 0;

    while (current && current->num < num)
	{
        cost++;
        current = current->next;
    }

    // Calculate cost to rotate or reverse rotate to this position
    int stack_b_size = stack_size(stack_b);
    if (cost <= stack_b_size / 2)
	{
        return cost;  // Rotate
    } else
	{
        return stack_b_size - cost;  // Reverse rotate
    }
}
t_node *find_cheapest_node(t_node *stack)
{
    t_node *cheapest = stack;
    t_node *current = stack->next;

    while (current)
	{
        if (current->push_cost < cheapest->push_cost)
		{
            cheapest = current;
        }
        current = current->next;
    }

    return cheapest;
}
void move_cheapest_node(t_node **stack_a, t_node **stack_b)
{
    t_node *cheapest = find_cheapest_node(*stack_a);

    // Rotate or reverse rotate stack_a to bring the cheapest node to the top
    if (cheapest->push_cost <= stack_size(*stack_a) / 2)
	{
        while (*stack_a != cheapest)
		{
            ra(stack_a, true);  // Rotate until cheapest is at the top
        }
    } else
	{
        while (*stack_a != cheapest)
		{
            rra(stack_a, true);  // Reverse rotate until cheapest is at the top
        }
    }

    // Push the cheapest node to stack_b
    pb(stack_a, stack_b, true);
}
void turk_sort(t_node **stack_a, t_node **stack_b)
{
    while (*stack_a)
	{
        // Step 1: Calculate the cost of each move
        calculate_push_cost(*stack_a, *stack_b);

        // Step 2: Move the node with the cheapest move
        move_cheapest_node(stack_a, stack_b);
    }

    // After stack_a is empty, push everything back from stack_b to stack_a in sorted order
    while (*stack_b)
	{
        pa(stack_a, stack_b, true);
    }
}
