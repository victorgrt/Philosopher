/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:05:42 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/22 13:13:24 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	print_action()

void    printer_structure(t_env *s)
{
	int	i;

	i = 0;

	while (i < s->philo_nb)
	{
		pthread_mutex_lock(&s->philos[i].printer);
		if (i == 0)
		printf("Env Values :\n \
			nb_philo : %d\n \
			time_die : %d\n \
			time_eat : %d\n \
			time_slp : %d\n \
			must_eat : %d\n", s->philo_nb, s->time_die, s->time_eat, s->time_slp, s->must_eat);
		printf("Philo [%d] :\n \
			position : %d\n \
			time_to_die : %d\n \
			nb_meals : %d\n \
			left fork : %d\n \
			right fork : %d\n", i, s->philos[i].pos, s->philos[i].time_to_die, s->philos[i].nb_meals, s->philos[i].lfork, s->philos[i].rfork);
		i++;
		pthread_mutex_unlock(&s->philos[i].printer);
	}

	pthread_mutex_destroy(&s->philos[i].printer);
}