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

#define WIN_W 850
#define WIN_H 400

typedef struct  s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map {
	int		width;
	int		height;
	int		**data;
}	t_map;

void	print_error(const char *message);
void	init_map(t_map *map, char **argv);

// Function prototypes for parsing utilities
int	open_file(char *file);
void	free_split(char **split);
int		count_words(char **split);
void	cleanup_parsing(char **split, char *line, int fd);
void print_map(int **map, int height, int width);

#endif
