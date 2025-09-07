/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:06:27 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 16:06:29 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->prev = NULL;
	current->next = (*stack);
	current->next->prev = current;
	(*stack) = current;
}

void	rra(t_stack **a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
