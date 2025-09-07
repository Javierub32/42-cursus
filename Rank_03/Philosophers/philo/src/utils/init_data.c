/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:03:05 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 11:03:07 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	create_philos(t_data *d);
static void	create_mutex(t_data *d);

void	init_data(t_data *d, char **argv)
{
	d->num_philos = ft_atol(argv[1]);
	d->time_die = ft_atol(argv[2]);
	d->time_eat = ft_atol(argv[3]);
	d->time_sleep = ft_atol(argv[4]);
	d->currect_philo = 0;
	if (argv[5])
		d->must_eat = ft_atol(argv[5]);
	else
		d->must_eat = -1;
	d->die = 0;
	d->start_time = calc_time();
	create_philos(d);
	create_mutex(d);
	d->thread = malloc(sizeof(pthread_t) * (d->num_philos));
	if (!d->thread)
		print_error(ERR_MALLOC);
	d->fork_state = malloc(sizeof(int) * d->num_philos);
	if (!d->fork_state)
		print_error(ERR_MALLOC);
	memset(d->fork_state, 0, sizeof(int) * d->num_philos);
}

static void	create_philos(t_data *d)
{
	int		i;

	d->philos = malloc(sizeof(t_philo) * d->num_philos);
	if (!d->philos)
		print_error(ERR_MALLOC);
	i = 0;
	while (i < d->num_philos)
	{
		d->philos[i].id = i + 1;
		d->philos[i].num_eat = 0;
		d->philos[i].last_eat = 0;
		d->philos[i].fork_l = i;
		d->philos[i].fork_r = (i + 1) % d->num_philos;
		i++;
	}
	if (!d->philos)
		print_error(ERR_MALLOC);
}

static void	create_mutex(t_data *d)
{
	int	i;

	d->mutex = malloc(sizeof(pthread_mutex_t) * d->num_philos);
	if (!d->mutex)
		print_error(ERR_MALLOC);
	i = 0;
	while (i < d->num_philos)
	{
		if (pthread_mutex_init(&d->mutex[i], NULL) != 0)
			print_error(ERR_MUTEX);
		i++;
	}
	if (pthread_mutex_init(&d->fork_mutex, NULL) != 0)
		print_error(ERR_MUTEX);
	if (pthread_mutex_init(&d->meal_mutex, NULL) != 0)
		print_error(ERR_MUTEX);
	if (pthread_mutex_init(&d->i_mutex, NULL) != 0)
		print_error(ERR_MUTEX);
	if (pthread_mutex_init(&d->dead_mutex, NULL) != 0)
		print_error(ERR_MUTEX);
	if (pthread_mutex_init(&d->print_mutex, NULL) != 0)
		print_error(ERR_MUTEX);
}
