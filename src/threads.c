/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:26:29 by vgoret            #+#    #+#             */
/*   Updated: 2023/09/05 18:13:40 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"




// void	create_threads2(t_env *s)
// {
// 	int	i;
	
// 	i = 0;
// 	while (i < s->philo_nb)
// 	{
// 		if (pthread_create(s->philos[i].thread, NULL, &philosopher_behavior, &s->philos[i]) != 0)
// 		{
// 			perror("Erreur lors de phtread_create");
// 			exit(1);
// 		}
// 		i++;
// 	}	
// }