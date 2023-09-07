/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:59:59 by vgoret            #+#    #+#             */
/*   Updated: 2023/09/07 17:17:18 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>


/*Initialiser mes structures
Parametres :
* number_of_philosophers : Le nombre de philosophes, mais aussi le nombre
de fourchettes.
◦ time_to_die (en millisecondes) : Si un philosophe n’a pas commencé à manger
time_to_die millisecondes après le début de son précédent repas ou depuis le
début de la simulation, il meurt.
◦ time_to_eat (en millisecondes) : Le temps qu’un philosophe prend à manger.
Pendant ce temps, un philosophe doit garder ses deux fourchettes.
◦ time_to_sleep (en millisecondes) : Le temps qu’un philosophe passe à dormir.
◦ number_of_times_each_philosopher_must_eat (argument optionnel) : Si tous
les philosophes ont mangé au moins number_of_times_each_philosopher_must_eat
fois, la simulation prend fin. Si cet argument n’est pas spécifié, alors la simu-
lation prend fin à la mort d’un philosophe.
*/

void	*routine(void *args)
{
	(void)args;
	printf("Help\n");
	return NULL;
}

int	create_forks(t_env *s)
{
	int		i;

	// s->forks = malloc(sizeof(pthread_mutex_t) * s->philo_nb + 1);
	// if (!(s->forks))
	{
		printf("Error malloc FORKS");
		return (FALSE);
	}
	i = 0;
	while (i < s->philo_nb)
	{
		// INITIALISER LES THREADS
		// if (pthread_mutex_init(&s->forks[i], NULL) != 0)
		// 	return (FALSE);
		// i++;
	}
	return (TRUE);
}

void	create_threads(t_env *s)
{
	int	i;

	i = 1;
	while (i <= s->philo_nb)
	{
		// s->philos->thread[i] = malloc(sizeof(pthread_t));
		s->i_mutex = i;
		printf("i_mutex : %d\n", s->i_mutex);
		// pthread_create(&s->threads[i], NULL, (void *)&routine, &s); //pas finito
		i++;
	}
	i = 1;
	while (i <= s->philo_nb)
	{
		// pthread_join(s->threads[i], NULL);
		i++;
	}
}

void    create_philos(t_env *s)
{
	int i;

	s->philos = malloc(sizeof(t_philo) * (s->philo_nb + 1));
	// s->philos->thread = malloc(sizeof(pthread_t) * s->philo_nb);
	// if (s->philos->thread == NULL)
	// {
	// 	printf("Malloc failed for threads tab !\n");
	// 	return ;
	// }
	if (!s->philos)
	{
		printf("Error Malloc s->philos\n");
		return ;
	}
	i = 1;
	while (i <= s->philo_nb)
	{
		// init_philo(s, i, i+1);
		i++;
	}
}



int main(int ac, char **av)
{
	t_env  s;
	
	ft_check_args(ac, av);
	if (maxi_init(ac, av, &s) == 0)
		return (0);
	if (init_mutex(&s) == 0)
		return (0);
	init_philosophers(&s);
	printer_philos(s.philos);
	if (init_thread(&s) == 0)
		return (0);
	return (0);
}