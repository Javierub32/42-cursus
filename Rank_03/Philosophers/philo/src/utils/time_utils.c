/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                      :+:       :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:03:05 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 11:03:07 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	calc_time(void)
{
	struct timeval	time;
	long			result;

	gettimeofday(&time, NULL);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

void	ft_usleep(int condition)
{
	long	start;

	start = calc_time();
	while (calc_time() - start < condition)
	{
		usleep(condition / 2);
	}
}

long	now(t_data *d)
{
	return (calc_time() - d->start_time);
}

int	get_die_value(t_data *d)
{
	int	val;

	pthread_mutex_lock(&d->dead_mutex);
	val = d->die;
	pthread_mutex_unlock(&d->dead_mutex);
	return (val);
}

void	safe_usleep(t_data *d, long ms)
{
	long	start;

	start = calc_time();
	while (calc_time() - start < ms)
	{
		if (get_die_value(d))
			break ;
		usleep(20);
	}
}
