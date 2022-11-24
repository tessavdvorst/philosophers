/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:54:03 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/24 17:47:55 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <stdbool.h>
# include "utils.h"
# include <pthread.h>

enum e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

enum e_err_msg
{
	ARGS,
	MUTEX_ARR,
	MUTEX,
	VAL,
};

typedef struct s_data
{
	int				min_meals;
	int				num_of_philos;
	int				finished_philos;
	bool			anyone_dead;
	long long		start_time;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_check;
	pthread_mutex_t	meal_check;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				num_of_meals;
	int				left_fork;
	int				right_fork;
	long long		time_last_meal;
	pthread_mutex_t	m_philo;
	struct s_data	*shared_data;
}				t_philo;

//data initialization
int			shared_data_init(t_data *data, int argc, char *argv[]);
int			philo_init(t_data *data, t_philo *philo);

//threads
int			create_philo_threads(t_philo *philo, pthread_t *thread,
				t_data *data);
int			join_philo_threads(pthread_t *thread, t_data *data);
void		destroy_all_mutex(t_data *data, t_philo *philo);
void		free_all(t_data *data, pthread_t *thread, t_philo *philo);

//routine 
int			start_diner(t_data *data);
void		*routine(void *arg);

//print
void		print_state(int state, t_philo *philo);
void		print_lock(int state, t_philo *philo);

//death & meal checks
bool		check_anyone_dead(t_philo *philo);
int			check_num_meals(t_philo *philo);
bool		check_satisfied(t_philo *philo);
bool		death_check_all(t_philo *philo);
int			check_all_philos_finished(t_philo *philo);

//time
long long	get_timestamp(void);
long long	time_since_start(long long start_time);
long long	check_time_to_die(struct timeval start);
bool		safe_sleep(t_philo *philo, long miliseconds);

//error message
int			error_msg_invalid_input(int err);

#endif
