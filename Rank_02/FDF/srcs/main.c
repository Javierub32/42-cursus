#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_vars	window;

	if (argc != 2)
		print_error("Usage: ./fdf <filename>");
	init_map(&map, argv);

	// Inicializar MiniLibX
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 2560, 1440, "FDF");

	create_projections(&window, &map);

	// Dibujar el wireframe
	draw_wireframe(&window, &map);

	// Configurar eventos
	mlx_hook(window.win, 17, 1L<<17, close_window, &window);
	mlx_key_hook(window.win, key_hook, &window);

	// Loop principal
	mlx_loop(window.mlx);

	// Limpiar memoria
	if (window.projections)
		free(window.projections);
	clear_map(&map);
	return (0);
}
