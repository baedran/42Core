/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:22:06 by obadran           #+#    #+#             */
/*   Updated: 2024/09/07 13:55:02 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"  // Include your header files
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

// Assume your is_valid_integer and other utility functions are in error.c


void parse_input(int argc, char **argv, t_node **stack_a)
{
    int i = 0;
    char **numbers;
    
    // Handle the case where the input is a single string (e.g., "./push_swap '4 67 3 87 23'")
    if (argc == 2) {
        numbers = split(argv[1], ' ');  // Assuming split is in your split.c
        while (numbers[i]) {
            if (!is_valid_integer(numbers[i])) {  // Use your existing is_valid_integer
                write(2, "Error\n", 6);
                free_args(numbers);  // Free memory from split
                exit(EXIT_FAILURE);
            }
            push(stack_a, atoi(numbers[i]));  // Push each argument to stack_a
            i++;
        }
        free_args(numbers);  // Free the split array after use
    }
    // Handle the case where input is passed as separate arguments (e.g., "./push_swap 4 67 3 87 23")
    else {
        i = 1;
        while (i < argc) {
            if (!is_valid_integer(argv[i])) {
                write(2, "Error\n", 6);
                exit(EXIT_FAILURE);
            }
            push(stack_a, atoi(argv[i]));  // Push each argument to stack_a
            i++;
        }
    }

    // Check for duplicates using your existing is_duplicate function
    if (is_duplicate(*stack_a)) {
        write(2, "Error\n", 6);
        free_stack(stack_a);  // Free the stack to avoid memory leaks
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char **argv)
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;

    if (argc < 2)
	{
        return 0;  // No arguments, nothing to do
    }

    // Parse and validate input
    parse_input(argc, argv, &stack_a);

    // From here, you can call your sorting function or operations


	   // Sort the stack
    sort_stack(&stack_a, &stack_b);
	
    // Free memory (to avoid memory leaks)
    free_stack(&stack_a);  // Use your free_stack function
    free_stack(&stack_b);  // If stack_b is used, free it as well

    return 0;
}

