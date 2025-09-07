/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:32:42 by jurbanej          #+#    #+#             */
/*   Updated: 2025/08/06 11:32:42 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	get_min(t_map *map)
{
	int	min;
	int	i;
	int	j;

	if (map->height <= 0 || map->width <= 0)
		return (0);
	min = map->data[0][0];
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] < min)
				min = map->data[i][j];
			j++;
		}
		i++;
	}
	return (min);
}

int	get_max(t_map *map)
{
	int	max;
	int	i;
	int	j;

	if (map->height <= 0 || map->width <= 0)
		return (0);
	max = map->data[0][0];
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] > max)
				max = map->data[i][j];
			j++;
		}
		i++;
	}
	return (max);
}
