/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:03:05 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 11:03:07 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	check_only_one_philo(t_data *d);
static void	print_state(t_data *d, int i, const char *msg);
static void	drop_forks(t_data *d, int i);

int	take_forks(t_data *d, int i)
{
	int	l;
	int	r;

	l = d->philos[i].fork_l;
	r = d->philos[i].fork_r;
	check_only_one_philo(d);
	while (!get_die_value(d))
	{
		pthread_mutex_lock(&d->fork_mutex);
		if (d->fork_state[l] == 0 && d->fork_state[r] == 0)
		{
			d->fork_state[l] = 1;
			d->fork_state[r] = 1;
			pthread_mutex_lock(&d->mutex[l]);
			pthread_mutex_lock(&d->mutex[r]);
			pthread_mutex_unlock(&d->fork_mutex);
			print_state(d, i, "has taken a fork 🍴");
			print_state(d, i, "has taken a fork 🍴");
			return (1);
		}
		pthread_mutex_unlock(&d->fork_mutex);
	}
	return (0);
}

void	eat_and_sleep(t_data *d, int i)
{
	pthread_mutex_lock(&d->meal_mutex);
	d->philos[i].last_eat = now(d);
	pthread_mutex_unlock(&d->meal_mutex);
	print_state(d, i, "is eating 🍝");
	safe_usleep(d, d->time_eat);
	pthread_mutex_lock(&d->meal_mutex);
	d->philos[i].last_eat = now(d);
	pthread_mutex_unlock(&d->meal_mutex);
	drop_forks(d, i);
	print_state(d, i, "is sleeping 😴");
	safe_usleep(d, d->time_sleep);
	print_state(d, i, "is thinking 🤔");
	safe_usleep(d, 1);
}

static void	drop_forks(t_data *d, int i)
{
	int	l;
	int	r;

	l = d->philos[i].fork_l;
	r = d->philos[i].fork_r;
	pthread_mutex_unlock(&d->mutex[r]);
	pthread_mutex_unlock(&d->mutex[l]);
	pthread_mutex_lock(&d->fork_mutex);
	d->fork_state[l] = 0;
	d->fork_state[r] = 0;
	pthread_mutex_unlock(&d->fork_mutex);
}

static void	check_only_one_philo(t_data *d)
{
	if (d->num_philos == 1)
	{
		print_state(d, 0, "has taken a fork 🍴");
		safe_usleep(d, d->time_die + 10);
		return ;
	}
}

static void	print_state(t_data *d, int i, const char *msg)
{
	long	actual_time;

	if (get_die_value(d))
		return ;
	pthread_mutex_lock(&d->print_mutex);
	actual_time = now(d);
	if (!d->die)
		printf("[%ld]\t[%d] %s\n", actual_time, d->philos[i].id, msg);
	pthread_mutex_unlock(&d->print_mutex);
}
