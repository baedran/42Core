/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:44:10 by obadran           #+#    #+#             */
/*   Updated: 2024/09/07 16:05:37 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int					num;
	int					index;
	int					push_cost; // total number of commands
	bool				above_median; // to calculate push cost
	bool				cheaptest; // the node that is cheapest to do the commands
	struct s_node		*target_node;
	struct s_node		*next;
	struct s_node		*prev;
}	t_node;

// Function Prototypes

// Input and Error Handling
int		is_valid_integer(char *str);
int		in_range(int num);
int is_duplicate(t_node *stack);
void free_stack(t_node **stack);

// Stack Operations
void	pa(t_node **stack_a, t_node **stack_b, bool print);
void	pb(t_node **stack_a, t_node **stack_b, bool print);
void	ra(t_node **stack_a, bool print);
void	rb(t_node **stack_b, bool print);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a, bool print);
void	rrb(t_node **stack_b, bool print);
void	rrr(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a, bool print);
void	sb(t_node **stack_b, bool print);
void	ss(t_node **stack_a, t_node **stack_b);
void	free_stack(t_node **stack);

// Sorting
void	sort_stack(t_node **stack_a, t_node **stack_b);
void	tiny_sort(t_node **a);

// Turk Algorithm
void	calculate_push_cost(t_node *stack_a, t_node *stack_b);
int		calculate_position_cost(t_node *stack_b, int num);
t_node	*find_cheapest_node(t_node *stack);
void	move_cheapest_node(t_node **stack_a, t_node **stack_b);
void	turk_sort(t_node **stack_a, t_node **stack_b);

// Utility Functions
char	**split(char *str, char c);
int		stack_size(t_node *stack);
t_node	*find_max(t_node *stack);
void push(t_node **stack, int num);
void free_args(char **args);

#endif