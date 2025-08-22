/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/19 11:04:18 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/**********************************************************************
 * t_data: Stores the value and index of a stack element.
 *
 * Members:
 * - value: The original integer from the input.
 * - index: The rank of the number in the sorted order (0-based).
 *
 * Notes:
 * - The index is used by radix sort to normalize values for bitwise operations.
 * - Keeps the original value intact for reference or printing.
 **********************************************************************/
typedef struct s_data
{
	int	value;
	int	index;
}	t_data;

// Parsing
void	free_split(char **arr);
void	parse_args(int argc, char **argv, t_list **a);

// Operations
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

// Sorting algo (sort_small)
// void	sort_three(t_list **a);
// void	sort_five(t_list **a, t_list **b);

// Sorting algo (gl_sort)
// void	index_stack(t_list *stack);
// void	radix_sort(t_list **a, t_list **b);
// void	gl_sort(t_list **a, t_list **b);

// Sorting utils
void	sort_three(t_list **a);
t_list	*ft_lstget(t_list *lst, int index);
int		find_min_value_pos(t_list *stack);
int		ft_max(int a, int b);

// Sorting algo
void	gl_sort2(t_list **a, t_list **b);
void	push_back_to_a(t_list **a, t_list **b);
void	push_back_to_a_sorted(t_list **a, t_list **b);
void	push_to_b_sorted(t_list **a, t_list **b);
void	execute_rotations(t_list **a, t_list **b, int cost_a, int cost_b);

// Utils
int		is_sorted(t_list *a);
int		is_valid_number(char *str);
int		is_duplicate(t_list *a, int num);
void	error_exit(t_list **stack, char **str);
void	free_stack(t_list **stack);

#endif
