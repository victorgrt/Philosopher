/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:09:23 by vgoret            #+#    #+#             */
/*   Updated: 2023/09/07 17:20:32 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

# define TRUE 1
# define FALSE 0

typedef	struct s_philo
{
	int				philo_nb;
	int				rang_philo;
	int				meals_nb;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_meal;
	unsigned long	last_meal;
	int				lfork;
	int				rfork;

	long long		start_time;
	
	struct s_env	*env;
	pthread_mutex_t	*lf;
	pthread_mutex_t *rf;
	pthread_t		thread;
}	t_philo;

typedef struct s_env
{
	int	philo_nb;
	int	time_die;
	int	time_eat;
	int	time_slp;
	int	time_think;
	int	max_meal;
	int	must_eat;

	unsigned long	start_time;
	long			current_time;
	int		stop_condition;
	int		max_ate;

	t_philo	*philos;
	
	pthread_mutex_t dead;
	pthread_mutex_t	meal;
	pthread_mutex_t	print;
	pthread_mutex_t *mutex;
	int	i_mutex;

}	t_env;


/* INIT */
int		init_thread(t_env *s);
int		init_mutex(t_env *s);
void	init_philosophers(t_env *s);
int		init_mutex(t_env *s);
void	ft_link_mutex_philo(t_env *s);
int		maxi_init(int ac, char **av, t_env *env);

/* ThREADS */
void	create_threads(t_env *s);

/* STRUCTURE */
void	init_struc(int ac, char **av, t_env *s);
void	create_philos(t_env *s);

/* FORKS */


/* PARSING */
int		ft_is_num(char *str);
void 	ft_check_args(int ac, char **av);

/* UTILS */

long	ft_atol(char *str);

/* ERROR MANAGEMENT */
void	ft_error(char *str);

/* PRINTER */
void	printer_structure(t_env *s);
void	printer_philos(t_philo *p);

#endif