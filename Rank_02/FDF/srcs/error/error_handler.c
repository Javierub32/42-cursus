/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:31:39 by jurbanej          #+#    #+#             */
/*   Updated: 2025/08/06 11:31:42 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	print_error(const char *message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int	check_bounds(t_vars *window, t_projection *p1, t_projection *p2)
{
	if ((p1->px < 0 && p2->px < 0)
		|| (p1->px >= window->width && p2->px >= window->width)
		|| (p1->py < 0 && p2->py < 0)
		|| (p1->py >= window->height && p2->py >= window->height))
		return (1);
	return (0);
}
