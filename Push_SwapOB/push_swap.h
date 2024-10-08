/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obadran <obadran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:05:39 by obadran           #+#    #+#             */
/*   Updated: 2024/10/08 12:11:57 by obadran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				number;
	int				current_position;
	int				final_index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// Prototypes from error.c
int		is_number(char *arg);
int		error_duplicate(t_node *a, int nbr);
void	free_stack(t_node **stack);
void	error_free(t_node **a);

// Prototypes from stack.c
void	append_node(t_node **stack, int nbr);
void	create_stack(t_node **a, char **argv);

// Prototypes from node_a_init.c
void	set_current_position(t_node *stack);
void	set_price(t_node *a, t_node *b);
void	set_cheapest(t_node *stack);
void	node_a_init(t_node *a, t_node *b);

// Prototypes from split.c
void	free_args(char **args);
char	**split(char *s, char c);

// Prototypes from mini.c
void	mini_sort(t_node **a);

// Prototypes from node_b_init.c
void	node_b_init(t_node *a, t_node *b);

// Prototypes from rotate.c
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);

// Prototypes from rev_rotate.c
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);

// Prototypes from push.c
void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **b, t_node **a, bool print);

// Prototypes from stack_utils.c
bool	stack_sorted(t_node *node);
int		stack_size(t_node *stack);
t_node	*find_last_node(t_node *node);
t_node	*find_max(t_node *node);
t_node	*find_min(t_node *node);

// Prototypes from swap.c
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);

// Prototypes from turk.c
void	turk_sort(t_node **a, t_node **b);

// Additional functions that were missing
t_node	*get_cheapest(t_node *stack);
void	finish_rotation(t_node **stack, t_node *top_node, char stack_name);
void	tiny_sort(t_node **a);
void	push_swap(t_node **a, t_node **b);

#endif
