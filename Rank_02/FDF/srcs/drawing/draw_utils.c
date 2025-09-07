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

static void	put_pixel(t_vars *vars, int x, int y, int color);
static void	init_line_params(t_line *line, t_projection p1, t_projection p2);

void	scale_and_center_projections(t_vars *window, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		window->projections[i].px = window->projections[i].px * window->scale
			+ window->offset_x;
		window->projections[i].py = window->projections[i].py * window->scale
			+ window->offset_y;
		i++;
	}
}

void	draw_line(t_vars *vars, t_projection p1, t_projection p2)
{
	t_line	line;
	int		e2;

	if (check_bounds(vars, &p1, &p2))
		return ;
	init_line_params(&line, p1, p2);
	while (line.x != (int)p2.px || line.y != (int)p2.py)
	{
		put_pixel(vars, line.x, line.y, p1.color);
		if (line.x == (int)p2.px && line.y == (int)p2.py)
			break ;
		e2 = 2 * line.err;
		if (e2 > -line.dy)
		{
			line.err -= line.dy;
			line.x += line.sx;
		}
		if (e2 < line.dx)
		{
			line.err += line.dx;
			line.y += line.sy;
		}
	}
}

static void	init_line_params(t_line *line, t_projection p1, t_projection p2)
{
	line->x = (int)p1.px;
	line->y = (int)p1.py;
	line->end_x = (int)p2.px;
	line->end_y = (int)p2.py;
	line->dx = abs((int)p2.px - (int)p1.px);
	line->dy = abs((int)p2.py - (int)p1.py);
	if ((int)p1.px < (int)p2.px)
		line->sx = 1;
	else
		line->sx = -1;
	if ((int)p1.py < (int)p2.py)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
}

static void	put_pixel(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < vars->width && y >= 0 && y < vars->height)
	{
		dst = vars->addr + (y * vars->line_length
				+ x * (vars->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	reset_params(t_vars *window)
{
	window->angle_x = 0.523599;
	window->angle_y = 0.523599;
	window->scale = 10.0;
	if (window->map->width > 50 || window->map->height > 50)
		window->scale = 10.0;
	if (window->map->width > 100 || window->map->height > 100)
		window->scale = 5.0;
	window->offset_x = window->width / 2;
	window->offset_y = window->height / 2;
}
