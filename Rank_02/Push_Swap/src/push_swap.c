/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:03:05 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 11:03:07 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_print_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		ft_printf("Nodo %i -> %i \t", i, a->value);
		a = a->next;
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	char	**nbrs;
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	a = NULL;
	b = NULL;
	nbrs = NULL;
	if (argc < 2)
		return (ft_printf("Usage: %s <arguments>\n", argv[0]), 1);
	parse_arguments(argc, argv, nbrs, &a);
	ft_print_stack(a);

	if (!is_stack_sorted(a))
		ft_printf("Ordenado \n");
	else
		ft_printf("Desordenado \n");

	push(&a, &b);
	ft_printf("\n----- HAGO UN PUSHHHHH -------\n");
	ft_print_stack(a);
	ft_print_stack(b);

	swap(&a);
	ft_printf("\n----- HAGO UN FUAPPP -------\n");
	ft_print_stack(a);

	rotate(&a);
	ft_printf("\n----- HAGO UN ROTATE -------\n");
	ft_print_stack(a);

	reverse_rotate(&a);
	ft_printf("\n----- HAGO UN REVERSE-ROTATE -------\n");
	ft_print_stack(a);
	return (0);
}
