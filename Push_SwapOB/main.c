/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 01:09:17 by obadran           #+#    #+#             */
/*   Updated: 2024/09/20 13:57:26 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In main.c or push_swap.c
void push_swap(t_node **a, t_node **b)
{
    int len = stack_size(*a);

    if (len <= 3)
        tiny_sort(a);
    else
    {
        // For larger stacks, use your main sorting algorithm
        turk_sort(a, b);
    }
}

int main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if (1 == argc || (2 == argc && !argv[1][0]))
		return (0);
	else if(2 == argc)
		argv = split(argv[1], ' ');
	
	create_stack(&stack_a, argv + 1);
	if (!stack_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a, false);
		else if (stack_size(stack_a) == 3)
			tiny_sort(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
}

