/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:05:42 by vgoret            #+#    #+#             */
/*   Updated: 2023/09/05 18:44:05 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	print_action()

void    printer_structure(t_env *s)
{
	int	i;

	// pthread_mutex_lock(&s->philos[s->i_mutex].printer);	
	i = 1;
	while (i <= s->philo_nb)
	{
		if (i == 1)
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
	}
	// pthread_mutex_unlock(&s->philos[s->i_mutex].printer);
	// pthread_mutex_destroy(&s->philos[s->i_mutex].printer);
}