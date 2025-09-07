/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:41:43 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 10:41:50 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#define WIN_W 850
#define WIN_H 400

typedef struct s_map {
	int		width;
	int		height;
	int		size;
	int		**data;
}	t_map;

typedef struct s_point {
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_projection {
	float	px;
	float	py;
	int		color;
}	t_projection;

typedef struct  s_vars {
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_projection	*projections;
	t_map			*map;
	float		width;
	float		height;
	float		scale;
	float		angle_x;
	float		angle_y;
	float		angle_z;
	float		offset_x;
	float		offset_y;
	float		color;
	int		projection;
}	t_vars;

typedef struct s_line
{
    int	x;
    int	y;
    int	end_x;
    int	end_y;
    int	dx;
    int	dy;
    int	sx;
    int	sy;
    int	err;
}	t_line;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;



void	print_error(const char *message);
int		check_bounds(t_vars *window, t_projection *p1, t_projection *p2);
void	init_map(t_map *map, char **argv);
void	init_main_window_params(t_vars *window, t_map *map);

// Function prototypes for parsing utilities
int		open_file(char *file);
void	free_split(char **split);
int		count_words(char **split);
void	cleanup_parsing(char **split, char *line, int fd);

void	print_map(int **map, int height, int width);
void	print_points(t_point *points, int wsize);
void	print_projections(t_projection *proj, int size);

t_point	*create_points(t_map *map);
void	create_projections(t_vars *vars, t_map *map);

// Rendering functions
void	draw_wireframe(t_vars *vars, t_map *map);
void	scale_and_center_projections(t_vars *vars, t_map *map);
void	draw_line(t_vars *vars, t_projection p1, t_projection p2);

// Event handling functions
int		close_window(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
void	redraw_image(t_vars *vars);
void 	reset_params(t_vars *window);

int get_min(t_map *map);
int get_max(t_map *map);

void	clear_map(t_map *map);



#endif
