/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:25:05 by obadran           #+#    #+#             */
/*   Updated: 2024/09/07 16:13:08 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_node **stack_a, bool print)
{
	if(!(*stack_a) || (!(*stack_a)->next))
	{
		return;
	}

	t_node *second_last = *stack_a;
	t_node *last = *stack_a; 
	
	while(last->next)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = *stack_a;
	(*stack_a)-> prev = last;
	*stack_a = last;
	last->prev = NULL;
	if(print)
		ft_printf("rra\n");
}

void rrb(t_node **stack_b, bool print)
{
	if(!(*stack_b) || (!(*stack_b)->next))
	{
		return;
	}

	t_node *second_last = *stack_b;
	t_node *last = *stack_b; 
	
	while(last->next)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = *stack_b;
	(*stack_b)-> prev = last;
	*stack_b = last;
	last->prev = NULL;
	if(print)
		ft_printf("rrb\n");
}

void rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	ft_printf("rrr");
}
