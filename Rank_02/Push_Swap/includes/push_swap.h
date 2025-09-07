/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:41:43 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 10:41:50 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				normalization;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

char	**parse_arguments(int argc, char **argv);
void	print_error(void);
long	ft_atol(char *str);
void	add_node(t_stack **a, int value);
void	stack_init(t_stack **a, char **nbrs);
void	free_array(char **array);
int		is_stack_sorted(t_stack *current);

void	push(t_stack **stack_origin, t_stack **stack_destination);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		*stack_to_array(t_stack *a, int size);
int		stack_size(t_stack *stack);
void	ft_sort(int *tab, unsigned int size);
void	normalize_stack(t_stack *a, int size);
void	apply_radix(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);

#endif
