#include "../../includes/fdf.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	count_words(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

void	cleanup_parsing(char **split, char *line, int fd)
{
	if (split)
		free_split(split);
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
}

void	print_map(int **map, int height, int width)
{
	int	i;
	int	j;

	write(1, "Map initialized with width: ", 28);
	ft_putnbr_fd(width, 1);
	write(1, "\n", 1);
	write(1, "Map initialized with height: ", 29);
	ft_putnbr_fd(height, 1);
	write(1, "\n", 1);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_putnbr_fd(map[i][j], 1);
			ft_putstr_fd("\t", 1);
			j++;
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}
