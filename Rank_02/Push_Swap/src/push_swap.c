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
/*
static void	ft_print_stack_normalized(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		ft_printf("Nodo %i -> %i \t", i, a->normalization);
		a = a->next;
		i++;
	}
	ft_printf("\n");
}
	*/

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
	ft_printf("Pila inicial:\n");
	ft_print_stack(a);

	if (!is_stack_sorted(a))
		ft_printf("Ordenado \n");
	else
		ft_printf("Desordenado \n");
	normalize_stack(a, stack_size(a));
	apply_radix(&a, &b);
		if (!is_stack_sorted(a))
		ft_printf("¡Pila ORDENADA correctamente! \n");
	else
		ft_printf("La pila NO está ordenada \n");
	/*
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
	*/
	/*
	normalize_stack(a, stack_size(a));
	ft_printf("\nPila normalizada:\n");
	ft_print_stack_normalized(a);

	ft_printf("\n----- APLICANDO RADIX SORT -------\n");
	apply_radix(&a, &b);

	ft_printf("\nPila después del radix sort:\n");
	ft_print_stack(a);
	ft_print_stack_normalized(a);

	if (!is_stack_sorted(a))
		ft_printf("¡Pila ORDENADA correctamente! \n");
	else
		ft_printf("La pila NO está ordenada \n");
	*/
	return (0);
}
