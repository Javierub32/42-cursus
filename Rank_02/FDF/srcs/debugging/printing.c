#include "../../includes/fdf.h"

void	print_points(t_point *points, int size)
{
	int		i;
	t_point	point;

	i = 0;
	while (i < size)
	{
		point = points[i];
		ft_putstr_fd("X: ", 1);
		ft_putnbr_fd(point.x, 1);
		ft_putstr_fd(", ", 1);
		ft_putstr_fd("  ", 1);
		ft_putstr_fd("Y: ", 1);
		ft_putnbr_fd(point.y, 1);
		ft_putstr_fd("  ", 1);
		ft_putstr_fd("\t", 1);
		ft_putstr_fd("Altura: ", 1);
		ft_putnbr_fd(point.z, 1);
		ft_putstr_fd("  ", 1);
		ft_putstr_fd("Color: ", 1);
		ft_putnbr_fd(point.color, 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	print_projections(t_projection *proj, int size)
{
	int				i;
	t_projection	pt;

	i = 0;
	while (i < size)
	{
		pt = proj[i];
		ft_putstr_fd("X: ", 1);
		ft_putnbr_fd(pt.px, 1);
		ft_putstr_fd(", ", 1);
		ft_putstr_fd("  ", 1);
		ft_putstr_fd("Y: ", 1);
		ft_putnbr_fd(pt.py, 1);
		ft_putstr_fd("  ", 1);
		ft_putstr_fd("Color: ", 1);
		ft_putnbr_fd(pt.color, 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
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
