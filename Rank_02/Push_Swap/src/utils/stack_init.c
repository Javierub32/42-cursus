/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:37:40 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 12:37:41 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	add_node(t_stack **a, int value)
{
	t_stack	*current;
	t_stack	*new_node;

	current = *a;
	while (current->next)
	{
		current = current->next;
	}
	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->value = value;
	new_node->normalization = value;
	new_node->prev = current;
	new_node->next = NULL;
	current->next = new_node;
}

void	stack_init(t_stack **a, char **nbrs)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = (t_stack *)malloc(sizeof(t_stack));
	while (nbrs[i])
	{
		if (i == 0)
		{
			head->prev = NULL;
			head->next = NULL;
			head->value = (int)ft_atol(nbrs[i]);
			head->normalization = (int)ft_atol(nbrs[i]);
			*a = head;
		}
		else
			add_node(a, (int)ft_atol(nbrs[i]));
		i++;
	}
}
