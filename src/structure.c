/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:59:59 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/22 13:07:55 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

int	create_forks(t_env *s)
{
	int		i;

	s->forks = malloc(sizeof(pthread_mutex_t) * s->philo_nb + 1);
	if (!(s->forks))
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

	i = 0;
	while (i < s->philo_nb)
	{
		// s->philos->thread[i] = malloc(sizeof(pthread_t));
		pthread_create(&s->philos->thread[i], NULL, (void *)&printer_structure, &s); //pas finito
		i++;
	}
	i = 0;
	while (i < s->philo_nb)
	{
		pthread_join(s->philos->thread[i], NULL);
		i++;
	}
}

void    init_philo(t_env *s, int i, int j)
{
	s->philos[i].pos = i + 1;
	s->philos[i].nb_meals = 0;
	s->philos[i].lfork = i;
	s->philos[i].rfork = j;
	s->philos[i].time_to_die = 0;
	s->philos[i].env = s;
	s->philos[i].thread = malloc(sizeof(pthread_t));
	if (!s->philos[i].thread)
		ft_error("Malloc echoue pour s->philos.threads");
	pthread_mutex_init(&s->philos[i].printer, NULL);
}

void    create_philos(t_env *s)
{
	int i;
	int j;

	s->philos = malloc(sizeof(t_philo) * (s->philo_nb + 1));
	if (!s->philos)
	{
		printf("Error Malloc s->philos");
		return ;
	}
	i = 0;
	j = 1;
	while (j < s->philo_nb)
	{
		init_philo(s, i, j);
		i++;
		j++;
	}
	j = 0;
	init_philo(s, i, j);
}

void    init_struc(int ac, char **av, t_env *s)
{
	s->philo_nb = ft_atol(av[1]);
	s->time_die = ft_atol(av[2]);
	s->time_eat = ft_atol(av[3]);
	s->time_slp = ft_atol(av[4]);
	if (ac == 6)
		s->must_eat = ft_atol(av[5]);
	else  
		s->must_eat = 0;
	create_philos(s);
	// printer_structure(s);
}

int main(int ac, char **av)
{
	t_env  s;
	ft_check_args(ac, av);
	init_struc(ac, av, &s);
	printer_structure(&s);
	printf("\n Bordel : \n");
	create_threads(&s);
	return (0);
}