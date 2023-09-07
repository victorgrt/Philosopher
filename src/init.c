/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:06:15 by vgoret            #+#    #+#             */
/*   Updated: 2023/09/07 17:16:45 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_uno_philo(t_env *s)
{
	printf("0 1 has taken a fork\n");
	usleep(s->time_die * 1000);
	printf("%d 1 died\n", (s->time_die + 1));
}

int    maxi_init(int ac, char **av, t_env *s)
{
	s->philo_nb = ft_atol(av[1]);
	s->time_die = ft_atol(av[2]);
	s->time_eat = ft_atol(av[3]);
	s->time_slp = ft_atol(av[4]);
	if (s->philo_nb < 1 || s->time_die < 1 || s->time_eat< 1 || s->time_slp < 1)
		return (0);
	if (ac == 6)
	{
		s->must_eat = ft_atol(av[5]);
		if (s->must_eat < 1)
		{
			printf("Argument 0 inf a 1\n");
			return (0);
		}
	}
	else  
		s->must_eat = -1;
	if (s->philo_nb == 1)
	{
		ft_uno_philo(s);
		return (0);
	}
	return (1);
}

void	ft_link_mutex_philo(t_env *s)
{
	int	i;

	i = 0;
	while (i < s->philo_nb - 1)
	{
		s->philos[i].lf = &s->mutex[i];
		s->philos[i].rf = &s->mutex[i];
		i++;
	}
	s->philos[i].lf = &s->mutex[i];
	s->philos[i].rf = &s->mutex[0];
}

int	init_mutex(t_env *s)
{
	int	i = 0;

	s->philos = malloc(sizeof(t_philo) * s->philo_nb);
	if (!s->philos)
		return (0);
	s->mutex = malloc(sizeof(pthread_mutex_t) * s->philo_nb);
	if (!s->mutex)
		return (0);
	while (i < s->philo_nb)
	{
		if (pthread_mutex_init(&(s->mutex[i]), NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&(s->print), NULL))
			return (0);
	if (pthread_mutex_init(&(s->meal), NULL))
			return (0);
	if (pthread_mutex_init(&(s->dead), NULL))
			return (0);
	ft_link_mutex_philo(s);
	return (1);
}

void	init_philosophers(t_env *s)
{
	int	i;

	i = 0;
	while (i < s->philo_nb)
	{
		s->philos[i].rang_philo = i + 1;
		s->philos[i].last_meal = 0;
		s->philos[i].env = s;
		s->philos[i].meals_nb = 0;
		s->philos[i].philo_nb = s->philo_nb;
		s->philos[i].die_time = s->time_die;
		s->philos[i].eat_time = s->time_eat;
		s->philos[i].sleep_time = s->time_slp;
		s->philos[i].max_meal = s->max_meal;
		s->philos[i].start_time = s->start_time;
		i++;
	}
}

int	init_thread(t_env *s)
{
	int	i;

	i = 0;
	while (i < s->philo_nb)
	{
		if (pthread_create(&(s->philos[i].thread), NULL, routine, &(s->philos[i])))
		{
			exit(0); //free
			return (0);
		}
		i += 2;
	}
	i = 1;
	while (i < s->philo_nb)
	{
		if (pthread_create(&(s->philos[i].thread), NULL, routine, &(s->philos[i])))
		{
			exit(0); //rajouter free ici aussi
			return (0);
		}
		i += 2;
	}
	return (1); 
}

void	printer_philos(t_philo *p)
{
	int i = 0;
	while (i < p->philo_nb)
	{
		printf("Philo[%d] :\tlastmeal :%ld\tmeal number :%d\nnb philo :%d\tdie_time :%d\teat_time :%d\nsleep_time :%d\tmax_meal :%d\tstart_time :%lld\n\n", p[i].rang_philo, p[i].last_meal, p[i].meals_nb, p[i].philo_nb, p[i].die_time, p[i].eat_time, p[i].sleep_time, p[i].max_meal, p[i].start_time);	
		i++;
	}
}