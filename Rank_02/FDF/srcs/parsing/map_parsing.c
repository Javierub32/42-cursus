#include "../../includes/fdf.h"

static int	read_width(char* file);
static int	read_height(char *file);

void	init_map(t_map *map, char **argv)
{
	int width;
	int height;
	int **data;

	(void)data; // To avoid unused variable warning
	width = read_width(argv[1]);
	height = read_height(argv[1]);
	map->width = width;
	map->height = height;

	write(1, "Map initialized with width: ", 28);
	ft_putnbr_fd(map->width, 1);
	write(1, "\n", 1);
	write(1, "Map initialized with height: ", 29);
	ft_putnbr_fd(map->height, 1);
	write(1, "\n", 1);

	if (map->width <= 0 || map->height <= 0)
		print_error("Invalid map dimensions");
	fill_map(map, argv[1]);
}

static int	read_width(char* file)
{
	int		fd;
	int		width;
	char	*line;
	char	**numbers;

	fd = open_file(file);
	width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		numbers = ft_split(line, ' ');
		if (width == 0)
			width = count_words(numbers);
		else
		{
			if (count_words(numbers) != width)
			{
				cleanup_parsing(numbers, line, fd);
				print_error("Error: The matrix is not rectangular");
				exit(EXIT_FAILURE);
			}
		}
		cleanup_parsing(numbers, line, -1);
	}
	close(fd);
	return (width);
}

static int	read_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open_file(file);
	height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	fill_map(t_map *map, char *file)
{
	int		fd;
	char	*line;
	char	**numbers;
	int		i;
	int		j;

	fd = open_file(file);
	map->data = malloc(sizeof(int *) * map->height);
	if (!map->data)
		print_error("Memory allocation failed for map data");
	i = 0;
	j = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		numbers = ft_split(line, ' ');
		map->data[i] = malloc(sizeof(int) * map->width);
		if (!map->data[i])
			print_error("Memory allocation failed for map row");
		fill_line(map->data[i], numbers, map->width);
		cleanup_parsing(numbers, line, -1);
		i++;
	}
	close(fd);
}

void	fill_line(int *line, char **numbers, int width)
{
	int j;

	j = 0;
	while (j < width)
	{
		line[j] = ft_atoi(numbers[j]);
		j++;
	}
	if (j != width)
		print_error("Error: The number of elements in the line does not match the width");
	return (line);
}

