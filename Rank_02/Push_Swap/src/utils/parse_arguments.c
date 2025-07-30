/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:09:43 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 12:08:19 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	sign_without_number(char **nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		if (nbrs[i][0] && nbrs[i][1] && (nbrs[i][0] == '+' || nbrs[i][0] == '-')
			&& (!ft_isdigit(nbrs[i][1])))
			return (1);
		i++;
	}
	return (0);
}

static void	check_arguments(char **nbrs)
{
	int		i;
	int		j;
	long	nbr;
	size_t	lenght;

	i = 0;
	if (sign_without_number(nbrs))
		print_error();
	while (nbrs[i])
	{
		nbr = ft_atol(nbrs[i]);
		lenght = ft_strlen(nbrs[i]);
		if (lenght > 11)
			print_error();
		if (nbr > 2147483647 || nbr < -2147483648)
			print_error();
		j = i + 1;
		while (nbrs[j])
		{
			if (nbr == ft_atol(nbrs[j]))
				print_error();
			j++;
		}
		i++;
	}
}

char	**parse_arguments(int argc, char **argv)
{
	char	**nbrs;

	if (argc == 2)
	{
		if (!argv[1][0])
			print_error();
		nbrs = ft_split(argv[1], ' ');
	}
	else
		nbrs = argv + 1;
	check_arguments(nbrs);
	return (nbrs);
}
