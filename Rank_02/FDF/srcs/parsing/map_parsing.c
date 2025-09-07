/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:32:02 by jurbanej          #+#    #+#             */
/*   Updated: 2025/08/06 11:32:03 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	read_width(char *file);
static int	read_height(char *file);
static int	*fill_line(char *line, int width);
static void	fill_map(t_map *map, char *file, int width);

void	init_map(t_map *map, char **argv)
{
	int	width;
	int	height;

	width = read_width(argv[1]);
	height = read_height(argv[1]);
	map->width = width;
	map->height = height;
	map->size = width * height;
	if (map->width <= 0 || map->height <= 0)
		print_error("Invalid map dimensions");
	fill_map(map, argv[1], width);
}

static int	read_width(char *file)
{
	int		fd;
	int		width;
	char	*line;
	char	**numbers;

	fd = open_file(file);
	line = get_next_line(fd);
	if (!line)
		print_error("Empty file or read error");
	numbers = ft_split(line, ' ');
	width = count_words(numbers);
	free_split(numbers);
	while (line != NULL)
	{
		numbers = ft_split(line, ' ');
		if (count_words(numbers) != width)
		{
			cleanup_parsing(numbers, line, fd);
			print_error("The matrix is not rectangular");
		}
		cleanup_parsing(numbers, line, -1);
		line = get_next_line(fd);
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
	line = get_next_line(fd);
	if (!line)
		print_error("Empty file or read error");
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static void	fill_map(t_map *map, char *file, int width)
{
	int		fd;
	char	*line;
	int		i;

	fd = open_file(file);
	map->data = malloc(sizeof(int *) * map->height);
	if (!map->data)
		print_error("Memory allocation failed for map data");
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->data[i] = fill_line(line, width);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

static int	*fill_line(char *line, int width)
{
	char	**numbers;
	int		*result;
	int		i;

	numbers = ft_split(line, ' ');
	result = malloc(sizeof(int) * width);
	if (!result)
	{
		free_split(numbers);
		print_error("Memory allocation failed for row.");
	}
	i = 0;
	while (numbers[i])
	{
		result[i] = ft_atoi(numbers[i]);
		i++;
	}
	free_split(numbers);
	return (result);
}
