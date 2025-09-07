/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:14:35 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 14:14:37 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort(int *tab, unsigned int size)
{
	int				tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	normalize_stack(t_stack *a, int size)
{
	int		*arr;
	t_stack	*cur;
	int		i;

	arr = stack_to_array(a, size);
	if (!arr)
		return ;
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
				break ;
			}
			i++;
		}
		cur = cur->next;
	}
	free(arr);
}

static void	ini_var(int *size, int *max_norm, int *max_bits, t_stack **a)
{
	*size = stack_size(*a);
	*max_norm = *size - 1;
	*max_bits = 0;
}

void	apply_radix(t_stack **a, t_stack **b)
{
	int	size;
	int	max_norm;
	int	max_bits;
	int	bit;
	int	count;

	ini_var(&size, &max_norm, &max_bits, a);
	while ((max_norm >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		count = 0;
		while (count < size)
		{
			if (((*a)->normalization >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			count++;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	normalize_stack(*a, stack_size(*a));
	apply_radix(a, b);
}
