/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/14 12:05:50 by giblee           ###   ########.fr       */
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
void	sort_three(t_list **a);
void	sort_five(t_list **a, t_list **b);

// Sorting algo (gl_sort)
void	index_stack(t_list *stack);
void	radix_sort(t_list **a, t_list **b);
void	gl_sort(t_list **a, t_list **b);

// Utils
int		is_sorted(t_list *a);
int		is_valid_number(char *str);
int		is_duplicate(t_list *a, int num);
// int     *create_int(int num);
void	error_exit(void);

#endif
