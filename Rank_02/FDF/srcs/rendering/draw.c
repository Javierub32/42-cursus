#include "../../includes/fdf.h"

static void	draw_line(t_vars *vars, t_projection p1, t_projection p2);
static void	put_pixel(t_vars *vars, int x, int y, int color);
static void	scale_and_center_projections(t_vars *vars, t_map *map);
static void	init_line_params(t_line *line, t_projection p1, t_projection p2);

void	draw_wireframe(t_vars *vars, t_map *map)
{
	int	i;
	int	j;
	int	index;

	scale_and_center_projections(vars, map);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width - 1)
		{
			index = i * map->width + j;
			draw_line(vars, vars->projections[index], vars->projections[index + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->height - 1)
	{
		j = 0;
		while (j < map->width)
		{
			index = i * map->width + j;
			draw_line(vars, vars->projections[index], vars->projections[index + map->width]);
			j++;
		}
		i++;
	}
}

static void	scale_and_center_projections(t_vars *vars, t_map *map)
{
	int		i;
	float	scale;
	float	offset_x;
	float	offset_y;

	scale = 40.0;
	if (map->width > 50 || map->height > 50)
		scale = 10.0;
	if (map->width > 100 || map->height > 100)
		scale = 5.0;
	offset_x = 1280.0;
	offset_y = 720.0;
	i = 0;
	while (i < map->size)
	{
		vars->projections[i].px = vars->projections[i].px * scale + offset_x;
		vars->projections[i].py = vars->projections[i].py * scale + offset_y;
		i++;
	}
}

static void	draw_line(t_vars *vars, t_projection p1, t_projection p2)
{
	t_line	line;
	int		e2;

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
	if (x >= 0 && x < 2560 && y >= 0 && y < 1440)
		mlx_pixel_put(vars->mlx, vars->win, x, y, color);
}
