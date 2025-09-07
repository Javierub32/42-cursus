/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:32:08 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 15:32:10 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	second = head->next;
	if (second->next)
		second->next->prev = head;
	head->next = second->next;
	head->prev = second;
	second->prev = NULL;
	second->next = head;
	*stack = second;
}

void	sa(t_stack **a)
{
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_stack **b)
{
	ft_printf("sb\n");
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
