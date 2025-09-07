/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:33:09 by jurbanej          #+#    #+#             */
/*   Updated: 2025/08/06 11:33:10 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	draw_vertical_lines(t_vars *vars, t_map *map);
static void	draw_horizontal_lines(t_vars *vars, t_map *map);

void	draw_wireframe(t_vars *vars, t_map *map)
{
	scale_and_center_projections(vars, map);
	draw_horizontal_lines(vars, map);
	draw_vertical_lines(vars, map);
}

static void	draw_horizontal_lines(t_vars *vars, t_map *map)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width - 1)
		{
			index = i * map->width + j;
			draw_line(vars, vars->projections[index],
				vars->projections[index + 1]);
			j++;
		}
		i++;
	}
}

static void	draw_vertical_lines(t_vars *vars, t_map *map)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	while (i < map->height - 1)
	{
		j = 0;
		while (j < map->width)
		{
			index = i * map->width + j;
			draw_line(vars, vars->projections[index],
				vars->projections[index + map->width]);
			j++;
		}
		i++;
	}
}
