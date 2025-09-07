/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:03:05 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 11:03:07 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	check_eating(t_data *d);

int	main(int argc, char **argv)
{
	t_data	d;
	int		i;

	check_initial_errors(argc, argv);
	init_data(&d, argv);
	start_simulation(&d);
	while (philo_dead(&d) == 0)
	{
		check_eating(&d);
		ft_usleep(10);
	}
	i = 0;
	while (i < d.num_philos)
		pthread_join(d.thread[i++], NULL);
	clean_data(&d);
	return (0);
}

static void	check_eating(t_data *d)
{
	int	i;
	int	all_ate;

	if (d->must_eat == -1)
		return ;
	all_ate = 1;
	i = 0;
	while (i < d->num_philos)
	{
		pthread_mutex_lock(&d->meal_mutex);
		if (d->philos[i].num_eat < d->must_eat)
			all_ate = 0;
		pthread_mutex_unlock(&d->meal_mutex);
		i++;
	}
	if (all_ate)
	{
		pthread_mutex_lock(&d->dead_mutex);
		d->die = 1;
		pthread_mutex_unlock(&d->dead_mutex);
	}
}
