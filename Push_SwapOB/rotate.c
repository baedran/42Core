/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:12:19 by obadran           #+#    #+#             */
/*   Updated: 2024/09/07 16:14:29 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_node **stack_a, bool print)
{
	if(!(*stack_a) || ((*stack_a)->next))
	{
		return;	
	}

	t_node *first = *stack_a;
	t_node *last = *stack_a;

	*stack_a = (*stack_a)->next;
	(*stack_a) ->prev = NULL;

	//traverse to the last node;
	
	while(last->next)
	{
		last = last->next;
	}
	
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if(print)
		ft_printf("ra\n");
}

void rb(t_node **stack_b, bool print)
{
	if(!(*stack_b) || ((*stack_b)->next))
	{
		return;	
	}

	t_node *first = *stack_b;
	t_node *last = *stack_b;

	*stack_b = (*stack_b)->next;
	(*stack_b) ->prev = NULL;

	//traverse to the last node;
	
	while(last->next)
	{
		last = last->next;
	}
	
	last->next = first;
	first->prev = last;
	first->next = NULL;
	
	if(print)
		ft_printf("rb\n");
}

void rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a, false);
	rb(stack_b, false);
}
