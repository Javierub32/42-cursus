/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurbanej <jurbanej@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:41:43 by jurbanej          #+#    #+#             */
/*   Updated: 2025/07/20 10:41:50 by jurbanej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int				id;
	int				num_eat;
	long			last_eat;
	int				fork_l;
	int				fork_r;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	i_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	print_mutex;
	pthread_t		*thread;
	t_philo			*philos;
	int				*fork_state;
	int				die;
	long			start_time;
	int				currect_philo;

}	t_data;

# define ERR_MALLOC			1
# define ERR_THREAD			2
# define ERR_MUTEX			3
# define ERR_INVALID_ARG	4
# define ERR_ATOL			5

void	check_initial_errors(int argc, char **argv);
void	print_error(int error);
long	ft_atol(char *str);
long	calc_time(void);
void	ft_usleep(int condition);
void	init_data(t_data *d, char **argv);
void	*routine(void *arg);
void	start_simulation(t_data *d);
int		philo_dead(t_data *d);
void	clean_data(t_data *d);
long	now(t_data *d);
int		get_die_value(t_data *d);
void	safe_usleep(t_data *d, long ms);

void	eat_and_sleep(t_data *d, int i);
int		take_forks(t_data *d, int i);

#endif
