/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:44:38 by obadran           #+#    #+#             */
/*   Updated: 2024/10/08 11:08:28 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

void	append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->number = nbr;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	create_stack(t_node **a, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (*argv)
	{	
		if (is_number(argv[i]))
			error_free(a);
		num = ft_atol(*argv);
		if (num < INT_MIN || num > INT_MAX)
			error_free(a);
		if (error_duplicate(*a, (int)num))
			error_free(a);
		append_node(a, (int)num);
		argv++;
	}
}
