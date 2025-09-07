/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:31:17 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 14:31:19 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **stack_origin, t_stack **stack_destination)
{
	t_stack	*node;

	if (!(*stack_origin))
		return ;
	node = *stack_origin;
	*stack_origin = (*stack_origin)->next;
	if (*stack_origin)
		(*stack_origin)->prev = NULL;
	node->next = *stack_destination;
	if (*stack_destination)
		(*stack_destination)->prev = node;
	*stack_destination = node;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_printf("pa\n");
	push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_printf("pb\n");
	push(a, b);
}
