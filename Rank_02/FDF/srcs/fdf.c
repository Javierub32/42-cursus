/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:33:33 by jurbanej          #+#    #+#             */
/*   Updated: 2025/08/06 11:33:34 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_vars	window;

	if (argc != 2)
		print_error("Usage: ./fdf <filename>");
	init_map(&map, argv);
	window.map = &map;
	init_main_window_params(&window, &map);
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.height, "FDF");
	window.img = mlx_new_image(window.mlx, window.width, window.height);
	window.addr = mlx_get_data_addr(window.img, &window.bits_per_pixel,
			&window.line_length, &window.endian);
	create_projections(&window, &map);
	draw_wireframe(&window, &map);
	mlx_put_image_to_window(window.mlx, window.win, window.img, 0, 0);
	mlx_hook(window.win, 17, 1L << 17, close_window, &window);
	mlx_key_hook(window.win, key_hook, &window);
	mlx_mouse_hook(window.win, mouse_hook, &window);
	mlx_loop(window.mlx);
	return (0);
}
