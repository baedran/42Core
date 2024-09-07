/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:51:37 by obadran           #+#    #+#             */
/*   Updated: 2024/09/07 16:11:07 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node **stack_a, bool print)
{
	if (!(*stack_a) || !((*stack_a)->next))
	{
		return;
	}
	
	t_node *first = *stack_a;
	t_node *second = (*stack_a)->next;

	first->next = second->next;
	if (second->next)
	{
		second->next->prev = first;
	}

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack_a = second;
	if(print)
		ft_printf("sa\n");
}

void sb(t_node **stack_b, bool print)
{
	if (!(*stack_b) || !((*stack_b)->next))
	{
		return;
	}
	
	t_node *first = *stack_b;
	t_node *second = (*stack_b)->next;

	first->next = second->next;
	if (second->next)
	{
		second->next->prev = first;
	}

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack_b = second;
	if(print)
		ft_printf("sb\n");
}

void ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a, false);
	sb(stack_b, false);
	
}
