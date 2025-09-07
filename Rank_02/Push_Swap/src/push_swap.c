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

int	main(int argc, char **argv)
{
	char	**nbrs;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	nbrs = NULL;
	if (argc < 2)
		return (1);
	nbrs = parse_arguments(argc, argv);
	stack_init(&a, nbrs);
	if (argc == 2)
		free_array(nbrs);
	if (!is_stack_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
