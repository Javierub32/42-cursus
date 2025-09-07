/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:03:05 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 11:03:07 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	check_someone_dead(t_data *d);

void	*routine(void *arg)
{
	t_data	*d;
	int		i;

	d = (t_data *)arg;
	pthread_mutex_lock(&d->i_mutex);
	i = d->currect_philo++;
	pthread_mutex_unlock(&d->i_mutex);
	if (d->philos[i].id % 2 == 0)
		usleep(500);
	while (!philo_dead(d))
	{
		if (!take_forks(d, i))
			break ;
		eat_and_sleep(d, i);
		if (d->must_eat > 0)
		{
			pthread_mutex_lock(&d->meal_mutex);
			d->philos[i].num_eat++;
			pthread_mutex_unlock(&d->meal_mutex);
		}
	}
	return (NULL);
}

int	philo_dead(t_data *d)
{
	pthread_mutex_lock(&d->dead_mutex);
	if (d->die)
	{
		pthread_mutex_unlock(&d->dead_mutex);
		return (d->die);
	}
	check_someone_dead(d);
	pthread_mutex_unlock(&d->dead_mutex);
	return (d->die);
}

static void	check_someone_dead(t_data *d)
{
	int		i;
	long	time_passed;
	long	last_eat_time;

	i = 0;
	while (i < d->num_philos)
	{
		time_passed = calc_time() - d->start_time;
		pthread_mutex_lock(&d->meal_mutex);
		last_eat_time = d->philos[i].last_eat;
		pthread_mutex_unlock(&d->meal_mutex);
		if (time_passed - last_eat_time >= d->time_die)
		{
			d->die = 1;
			pthread_mutex_lock(&d->print_mutex);
			printf("[%ld]\t[%d] \033[1;91mdied ☠️\033[0;39m\n",
				time_passed, d->philos[i].id);
			pthread_mutex_unlock(&d->print_mutex);
			return ;
		}
		i++;
	}
}
