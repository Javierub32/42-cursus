/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:03:05 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 11:03:07 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_initial_errors(int argc, char **argv)
{
	int		i;
	long	num;

	if (argc < 5 || argc > 6)
		print_error(ERR_INVALID_ARG);
	i = 1;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (i == 1 && (num < 1 || num > 200))
			print_error(ERR_INVALID_ARG);
		else if ((i > 1 && i < 5) && (num < 60 || num > 2147483647))
			print_error(ERR_INVALID_ARG);
		else if (i == 5 && (num < 1 || num > 2147483647))
			print_error(ERR_INVALID_ARG);
		i++;
	}
}
