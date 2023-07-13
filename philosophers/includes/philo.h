/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:06:41 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/30 10:36:31 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"
# define LEFT 0
# define RIGHT 1

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_data
{
	char				**argv;
	int					argc;
	int					nb_philo;
	long long			td;
	long long			te;
	long long			ts;
	int					max_meal;
	int					g_status;
	pthread_mutex_t		print;
	pthread_t			*threads;
	t_philo				*philos;
};

struct s_philo
{
	int				id;
	int				g_status;
	long long		time_lmeal;
	int				meal_eaten;
	pthread_mutex_t	fork;
	t_data			*data;
};

int			parse(t_data *d, t_philo **p);
long long	ft_time(void);
void		life(t_philo *p);
int			ft_print(t_philo *p, char *action, int i);
void		ft_sleep(long long time);

#endif