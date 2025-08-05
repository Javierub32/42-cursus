#include "../../includes/fdf.h"

void	clear_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	map->data = NULL;
	map->width = 0;
	map->height = 0;
}
