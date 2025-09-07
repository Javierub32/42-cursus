/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:32:42 by jurbanej          #+#    #+#             */
/*   Updated: 2025/08/06 11:32:42 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	interpolate_color(int color1, int color2, float ratio);
static int	get_gradient(int height, int min_height, int max_height);

void	create_projections(t_vars *window, t_map *map)
{
	t_projection	*projections;
	t_point			*pts;
	int				i;
	int				min_height;
	int				max_height;

	pts = create_points(map);
	min_height = get_min(map);
	max_height = get_max(map);
	projections = (t_projection *)malloc(sizeof(t_projection) * (map->size));
	if (!projections)
		print_error("Memory allocation failed for points data");
	i = 0;
	while (i < map->size)
	{
		projections[i].px = (pts[i].x - pts[i].y) * cos(window->angle_x);
		projections[i].py = (pts[i].x + pts[i].y) * sin(window->angle_y)
			- pts[i].z;
		projections[i].color = get_gradient(pts[i].z, min_height, max_height);
		i++;
	}
	free(pts);
	window->projections = projections;
}

t_point	*create_points(t_map *map)
{
	int		i;
	int		j;
	int		index;
	t_point	*points;
	int		**data;

	points = (t_point *)malloc(sizeof(t_point) * (map->size));
	if (!points)
		print_error("Memory allocation failed for points data");
	data = map->data;
	i = 0;
	index = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			points[index] = (t_point){j, i, data[i][j], 0};
			index++;
			j++;
		}
		i++;
	}
	return (points);
}

static int	get_gradient(int height, int min_height, int max_height)
{
	float	ratio;
	int		color;

	if (max_height == min_height)
		return (0xFFFFFF);
	ratio = (float)(height - min_height) / (max_height - min_height);
	if (height <= 0)
		color = interpolate_color(0x000080, 0x4169E1, ratio);
	else if (height == 0)
		return (0xFFFFFF);
	else
	{
		if (ratio < 0.25)
			color = interpolate_color(0x90EE90, 0x228B22, ratio * 4);
		else if (ratio < 0.5)
			color = interpolate_color(0x228B22, 0xD2691E, (ratio - 0.25) * 4);
		else if (ratio < 0.75)
			color = interpolate_color(0xD2691E, 0x8B4513, (ratio - 0.5) * 4);
		else
			color = interpolate_color(0x8B4513, 0xFFFFFF, (ratio - 0.75) * 4);
	}
	return (color);
}

static int	interpolate_color(int color1, int color2, float ratio)
{
	t_color	rgb1;
	t_color	rgb2;
	t_color	result;

	if (ratio < 0)
		ratio = 0;
	if (ratio > 1)
		ratio = 1;
	rgb1.r = (color1 >> 16) & 0xFF;
	rgb1.g = (color1 >> 8) & 0xFF;
	rgb1.b = color1 & 0xFF;
	rgb2.r = (color2 >> 16) & 0xFF;
	rgb2.g = (color2 >> 8) & 0xFF;
	rgb2.b = color2 & 0xFF;
	result.r = (int)(rgb1.r + (rgb2.r - rgb1.r) * ratio);
	result.g = (int)(rgb1.g + (rgb2.g - rgb1.g) * ratio);
	result.b = (int)(rgb1.b + (rgb2.b - rgb1.b) * ratio);
	return ((result.r << 16) | (result.g << 8) | result.b);
}
