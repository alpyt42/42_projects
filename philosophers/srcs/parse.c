/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:19:47 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/30 12:59:28 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (!str)
		return (-1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (dprintf(2, "A non alphanum has been found\n"), -1);
		nb = nb * 10 + str[i++] - 48;
	}
	if (nb == 0 && str[0] != '0' && str[1] == '\0')
		return (-1);
	return (sign * nb);
}

static int	valid_data(t_data *d)
{
	if (d->nb_philo < 1)
		return (dprintf(2, "Error 'parsing' (Nb Philos must be above 1)\n"));
	if (d->td < 1)
		return (dprintf(2, "Error 'parsing' (Time to Death must be above 1)\n"));
	if (d->te < 1)
		return (dprintf(2, "Error 'parsing' (Time to Eat must be above 1)\n"));
	if (d->ts < 1)
		return (dprintf(2, "Error 'parsing' (Time to Sleep must be above 1)\n"));
	if (d->max_meal < 1 && d->argc == 6)
		return (dprintf(2, "Error 'parsing' (Nb Max_Meal must be above 1)\n"));
	return (0);
}

int	parse(t_data *d, t_philo **p)
{
	if (d->argc == 5 || d->argc == 6)
	{
		d->g_status = 1;
		d->nb_philo = ft_atoi(d->argv[1]);
		d->td = ft_atoi(d->argv[2]);
		d->te = ft_atoi(d->argv[3]);
		d->ts = ft_atoi(d->argv[4]);
		if (d->argc == 6)
			d->max_meal = ft_atoi(d->argv[5]);
		else
			d->max_meal = -1;
		if (valid_data(d))
			return (0);
		d->threads = NULL;
		*p = NULL;
		return (1);
	}
	else
	{
		dprintf(2, "Error Parsing : Number of Arguments\n");
		dprintf(2, "./philo nb_philos time_die time_eat time_sleep [nb_meal]\n");
	}
	return (0);
}
