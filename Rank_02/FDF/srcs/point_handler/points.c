#include "../../includes/fdf.h"

static int	get_color(int height);

void	create_projections(t_vars *vars, t_map *map)
{
	t_projection	*projections;
	t_point			*pts;
	int				i;

	(void) vars;
	pts = create_points(map);
	projections = (t_projection *)malloc(sizeof(t_projection) * (map->size));
	if (!projections)
		print_error("Memory allocation failed for points data");
	i = 0;
	while (i < map->size)
	{
		projections[i].px = (pts[i].x - pts[i].y) * cos(0.523599);
		projections[i].py = (pts[i].x + pts[i].y) * sin(0.523599) - pts[i].z;
		projections[i].color = pts[i].color;
		i++;
	}
	free(pts);
	vars->projections = projections;
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
			points[index] = (t_point){j, i, data[i][j], get_color(data[i][j])};
			index++;
			j++;
		}
		i++;
	}
	return (points);
}

static int	get_color(int height)
{
	if (height < 0)
		return (0xFFFFFF);
	else if (height == 0)
		return (0xFFFFFF);
	else
		return (0x007BFF);
}
