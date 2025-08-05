#include "../../includes/fdf.h"

int	close_window(t_vars *vars)
{
	if (vars->projections)
		free(vars->projections);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	return (0);
}
