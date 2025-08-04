#include "../includes/fdf.h"

int main(int argc, char **argv)
{
	t_map map;

	if (argc != 2)
		print_error("Usage: ./fdf <filename>");
	init_map(&map, argv);
}
