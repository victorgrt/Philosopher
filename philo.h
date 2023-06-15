/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:09:23 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/15 17:50:25 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

# define TRUE 1
# define FALSE 0

typedef	struct s_philo
{
	int				nb_meals;
	int				time_to_die;
	int				pos;
	unsigned long	last_meal;
	int				meals_counter;
	int				lfork;
	int				rfork;
	struct s_env	*env;
	pthread_t		thread_id;
}	t_philo;

typedef struct s_env
{
	int	philo_nb;
	int	time_die;
	int	time_eat;
	int	time_slp;
	int	time_think;
	int	must_eat;

	unsigned long	start_time;
	int		stop_condition;
	int		max_ate;

	t_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	writing;
}	t_env;


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

#endif