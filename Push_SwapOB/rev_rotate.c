/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:25:05 by obadran           #+#    #+#             */
/*   Updated: 2024/09/20 11:56:39 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node		*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_node **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_node **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}

void finish_rotation(t_node **stack, t_node *top_node, char stack_name)
{
    while (*stack != top_node)
    {
        if (top_node->above_median)
        {
            if (stack_name == 'a')
                ra(stack, false);
            else
                rb(stack, false);
        }
        else
        {
            if (stack_name == 'a')
                rra(stack, false);
            else
                rrb(stack, false);
        }
    }
}