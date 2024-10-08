/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:34:51 by obadran           #+#    #+#             */
/*   Updated: 2024/10/08 10:28:41 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *arg)
{
	if (!(*arg == '-'
			|| (*arg >= '0' && *arg <= '9')))
		return (1);
	if ((*arg == '-')
		&& !(arg[1] >= '0' && arg[1] <= '9'))
		return (1);
	while (*++arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_node *a, int nbr)
{
	t_node	*temp;

	temp = a;
	if (!temp)
		return (0);
	while (temp)
	{
		if (temp->number == nbr)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

void	error_free(t_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
