/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:05:42 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/21 16:01:27 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	print_action()

void    printer_structure(t_env *s)
{
	printf("Env Values :\n \
	nb_philo : %d\n \
	time_die : %d\n \
	time_eat : %d\n \
	time_slp : %d\n \
	must_eat : %d\n", s->philo_nb, s->time_die, s->time_eat, s->time_slp, s->must_eat);

	// int i 0 0;
	// while (i < s->philo_nb)
	// {
		printf("Philo [%d] :\n \
		position : %d\n \
		time_to_die : %d\n \
		nb_meals : %d\n \
		left fork : %d\n \
		right fork : %d\n", 0, s->philos[0].pos, s->philos[0].time_to_die, s->philos[0].nb_meals, s->philos[0].lfork, s->philos[0].rfork);
		// i++;
	// }
}