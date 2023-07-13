/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:06:34 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/29 14:55:03 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_free_end(t_data *d, int i)
{
	while (++i < d->nb_philo)
		pthread_join(d->threads[i], NULL);
	i = -1;
	pthread_mutex_destroy(&d->print);
	while (++i < d->nb_philo)
		pthread_mutex_destroy(&d->philos[i].fork);
	if (d->threads)
		free(d->threads);
	if (d->philos)
		free(d->philos);
}

static int	init(t_data *d, t_philo *p, int i)
{
	p = (t_philo *)malloc(sizeof(t_philo) * d->nb_philo);
	if (!p)
		return (0);
	d->philos = p;
	d->threads = (pthread_t *)malloc(sizeof(pthread_t) * d->nb_philo);
	if (!d->threads)
		return (free(p), 0);
	pthread_mutex_init(&d->print, NULL);
	while (++i < d->nb_philo)
		pthread_mutex_init(&p[i].fork, NULL);
	ft_time();
	i = -1;
	while (++i < d->nb_philo)
	{
		p[i].id = i;
		p[i].time_lmeal = 0;
		p[i].meal_eaten = 0;
		p[i].g_status = 1;
		p[i].data = d;
		if (pthread_create(&d->threads[i], NULL,
				(void *) life, &p[i]))
			return (free(p), free(d->threads), 0);
	}
	return (1);
}

static int	check_status(t_data *d, t_philo *p)
{
	int	count;
	int	i;
	int	meal;

	count = 0;
	i = -1;
	meal = d->max_meal;
	while (++i < d->nb_philo)
	{
		if (meal > 0 && p[i].data->max_meal <= p[i].meal_eaten)
			count++;
		if (p[i].time_lmeal + d->td < ft_time()
			|| (meal > 0 && (count >= d->nb_philo)))
		{
			if (count < d->nb_philo)
				printf("%lld %d %s\n", ft_time(), i + 1, DIED);
			else if (meal >= 1)
				printf("%lld Everyone has eaten %d meal(s)\n",
					ft_time(), meal);
			d->g_status = 0;
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	d;
	t_philo	*p;
	int		g_status;

	d.argv = argv;
	d.argc = argc;
	if (!parse(&d, &p))
		return (1);
	g_status = d.g_status;
	if (!init(&d, p, -1))
		return (1);
	while (g_status)
	{
		pthread_mutex_lock(&d.print);
		g_status = check_status(&d, d.philos);
		pthread_mutex_unlock(&d.print);
		usleep(100);
	}
	ft_free_end(&d, -1);
	return (0);
}
