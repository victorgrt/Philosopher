/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:09:23 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/14 16:32:48 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_data
{
	int	philo_nb;
	int	time_die;
	int	time_eat;
	int	time_slp;
	int	time_think;
	int	must_eat;
	int	done;
	int	died;
}	t_data;


typedef	struct s_philo
{
	int	id;
	unsigned long	last_meal;
	int				meals_counter;
	int				lfork;
	int				rfork;
	t_data			*data;
}	t_philo;


/* */

/* PARSING */
int		ft_is_num(char *str);

/* UTILS */
long	ft_atol(char *str);

/* ERROR MANAGEMENT */
void	ft_error(char *str);

#endif