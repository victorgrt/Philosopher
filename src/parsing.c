/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:23:35 by vgoret            #+#    #+#             */
/*   Updated: 2023/06/15 15:22:13 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	if (*str == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int ft_check_args(int ac, char **av)
{
	
	if (ac != 5)
		ft_error("Error : Please Check Arguments (4 needed)");
	while (ac-- > 1)
	{
		if (ft_is_num(av[ac]) == 1)
			ft_error("Error : Invalid Character");
		if (ft_atol(av[ac]) > 2147483647 || ft_atol(av[ac]) < 0)
			ft_error("Error : Argument out of range");
	}
	return (0);
}

// int	main(int ac, char **av)
// {
// 	printf("%d\n", ft_check_args(ac, av));
// 	return (0);
// }