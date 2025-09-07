/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                      :+:       :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:03:05 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 11:03:07 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	clean_data(t_data *d)
{
	int	i;

	i = 0;
	if (d->mutex)
	{
		while (i < d->num_philos)
		{
			pthread_mutex_destroy(&d->mutex[i]);
			i++;
		}
		free(d->mutex);
	}
	if (d->philos)
		free(d->philos);
	if (d->thread)
		free(d->thread);
	if (d->fork_state)
		free(d->fork_state);
	pthread_mutex_destroy(&d->fork_mutex);
	pthread_mutex_destroy(&d->meal_mutex);
	pthread_mutex_destroy(&d->i_mutex);
	pthread_mutex_destroy(&d->dead_mutex);
	pthread_mutex_destroy(&d->print_mutex);
}
