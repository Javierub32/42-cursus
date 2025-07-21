/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:14:35 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 14:14:37 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_stack_sorted(t_stack *current)
{
	while (current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	*stack_to_array(t_stack *a, int size)
{
	int	*arr;
	t_stack	*cur;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	cur = a;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	return (arr);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void normalize_stack(t_stack *a, int size)
{
    int      *arr;
    t_stack  *cur;
    int       i;

    arr = stack_to_array(a, size);
    if (!arr)
        return;
    ft_sort(arr, size);
    cur = a;
    while (cur)
    {
        i = 0;
        while (i < size)
        {
            if (arr[i] == cur->normalization)
            {
                cur->normalization = i;
                break;
            }
            i++;
        }
        cur = cur->next;
    }
    free(arr);
}
