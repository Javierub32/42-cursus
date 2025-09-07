/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:33:14 by jurbanej          #+#    #+#             */
/*   Updated: 2025/08/06 11:33:15 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_main_window_params(t_vars *window, t_map *map)
{
	window->height = 720;
	window->width = 1280;
	window->angle_x = 0.523599;
	window->angle_y = 0.523599;
	window->scale = 10.0;
	if (map->width > 50 || map->height > 50)
		window->scale = 10.0;
	if (map->width > 100 || map->height > 100)
		window->scale = 5.0;
	window->offset_x = window->width / 2;
	window->offset_y = window->height / 2;
}
