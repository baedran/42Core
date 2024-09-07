/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:34:51 by obadran           #+#    #+#             */
/*   Updated: 2024/09/07 00:44:42 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_valid_integer(char *str)
{
	while (*str == ' ' || *str == '\t')
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_printf("Error\n");
			return (0);
		}
		str++;
	}
	return (1);
}

int	in_range(int num)
{
	int	int_max;
	int	int_min;

	int_max = 2147483647;
	int_min = -2147483648;
	return (num >= int_min && num <= int_max);
}

int is_duplicate(t_node *stack)
{
    t_node *current = stack;
    t_node *other;

    while (current)
	{
        other = current->next;
        while (other)
		{
            if (current->num == other->num)
                return 1;  // Duplicate found
            other = other->next;
        }
        current = current->next;
    }
    return 0;  // No duplicates
}


void free_stack(t_node **stack) {
    t_node *temp;

    while (*stack) {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
    *stack = NULL;
}