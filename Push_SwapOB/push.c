/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:27:31 by obadran           #+#    #+#             */
/*   Updated: 2024/09/07 16:13:45 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

// Function to add a new node with the value 'num' to the top of the stack
void push(t_node **stack, int num)
{
    // Step 1: Allocate memory for the new node
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
	{
        write(2, "Error\n", 6);  // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }

    // Step 2: Initialize the new node with the given value 'num'
    new_node->num = num;
    new_node->prev = NULL;  // Since it will be the new top, there is no previous node
    new_node->next = *stack;  // The current top node becomes the next node

    // Step 3: Update the current top node's 'prev' pointer if the stack is not empty
    if (*stack != NULL)
	{
        (*stack)->prev = new_node;
    }

    // Step 4: Set the new node as the top of the stack
    *stack = new_node;
}


void pa(t_node **stack_a, t_node ** stack_b, bool print)
{
	if(!(*stack_b))
	{
		return;
	}

	t_node	*temp;

	temp = *stack_b;
	*stack_b = (*stack_b) -> next;
	
	if(*stack_b)
	{
		(*stack_b) -> prev = NULL;
	} 
	
	temp -> next = *stack_a;
	if(*stack_a)
	{
		(*stack_a) -> prev = temp;
	}

	*stack_a = temp;
	temp -> prev = NULL;
	if(print)
		ft_printf("pa\n");
}

void pb(t_node **stack_a, t_node **stack_b, bool print)
{
	if(!(stack_a))
	{
		return;
	}
	t_node *temp = *stack_a;
	*stack_a = (*stack_a) -> next;
	
	if (*stack_a)
	{
		(*stack_a) -> prev = NULL;
	}

	temp -> next = *stack_b;
	
	if(*stack_b)
	{
		(*stack_b)->prev = temp;
	}
		
	*stack_b = temp; 	
	temp -> prev = NULL;
	if(print)
		ft_printf("pb\n");
}

