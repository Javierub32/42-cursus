/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:31:50 by jurbanej          #+#    #+#             */
/*   Updated: 2025/08/06 11:31:51 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	movement_hook(int keycode, t_vars *window);

void	redraw_image(t_vars *window)
{
	mlx_destroy_image(window->mlx, window->img);
	if (window->projections)
		free(window->projections);
	window->img = mlx_new_image(window->mlx, window->width, window->height);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel,
			&window->line_length, &window->endian);
	create_projections(window, window->map);
	draw_wireframe(window, window->map);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}

int	close_window(t_vars *window)
{
	if (window->projections)
		free(window->projections);
	if (window->map)
		clear_map(window->map);
	if (window->img)
		mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *window)
{
	if (keycode == 65307)
	{
		close_window(window);
		return (0);
	}
	else if (keycode == 114)
		window->angle_x += 0.1;
	else if (keycode == 116)
		window->angle_x -= 0.1;
	else if (keycode == 102)
		window->angle_y += 0.1;
	else if (keycode == 103)
		window->angle_y -= 0.1;
	else if (keycode == 112)
	{
		window->angle_x = 0.0;
		window->angle_y = 0.0;
		window->scale = 10.0;
	}
	else if (keycode == 113)
		reset_params(window);
	movement_hook(keycode, window);
	redraw_image(window);
	return (0);
}

static int	movement_hook(int keycode, t_vars *window)
{
	if (keycode == 119 || keycode == 65362)
	{
		if (window->offset_y > -window->height * 2)
			window->offset_y -= 100;
	}
	else if (keycode == 115 || keycode == 65364)
	{
		if (window->offset_y < window->height * 2)
			window->offset_y += 100;
	}
	else if (keycode == 97 || keycode == 65361)
	{
		if (window->offset_x > -window->width * 2)
			window->offset_x -= 100;
	}
	else if (keycode == 100 || keycode == 65363)
	{
		if (window->offset_x < window->width * 2)
			window->offset_x += 100;
	}
	redraw_image(window);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *window)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		if (window->scale < 150)
		{
			window->scale *= 1.1;
			redraw_image(window);
		}
	}
	else if (button == 5)
	{
		window->scale *= 0.9;
		if (window->scale < 1)
			window->scale = 1;
		redraw_image(window);
	}
	return (0);
}
