/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:09:23 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/14 16:21:56 by vgoret           ###   ########.fr       */
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

#endif