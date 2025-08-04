#include "../includes/fdf.h"

static void	clear_map(t_map *map);

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		print_error("Usage: ./fdf <filename>");
	init_map(&map, argv);
	clear_map(&map);
}

static void	clear_map(t_map *map)
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
