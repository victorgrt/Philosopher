/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:59:59 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/15 17:40:25 by victor           ###   ########.fr       */
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

void    init_philo(t_env *s, int i, int j)
{
    s->philos[i].pos = i + 1;
    s->philos[i].nb_meals = 0;
    s->philos[i].lfork = i;
    s->philos[i].rfork = j; 
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

void    printer_structure(t_env *s)
{
    printf("Env Values :\n \
    nb_philo : %d\n \
    time_die : %d\n \
    time_eat : %d\n \
    time_slp : %d\n \
    must_eat : %d\n", s->philo_nb, s->time_die, s->time_eat, s->time_slp, s->must_eat);

    int i = 0;
    while (i < s->philo_nb)
    {
        printf("Philo [%d] :\n \
        position : %d\n \
        nb_meals : %d\n \
        left fork : %d\n \
        right fork : %d\n", i, s->philos[i].pos, s->philos[i].nb_meals, s->philos[i].lfork, s->philos[i].rfork);
        i++;
    }
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
    printer_structure(s);
}

int main(int ac, char **av)
{
    t_env  s;
    ft_check_args(ac, av);
    init_struc(ac, av, &s);
    return (0);
}