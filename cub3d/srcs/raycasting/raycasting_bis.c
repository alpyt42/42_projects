/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:44:56 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/17 11:45:29 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_data *d)
{
	raycasting(d);
	display_map(d);
	mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->img, 0, 0);
}

void	hit_point(t_data *d)
{
	float	magnitudevector;

	magnitudevector = sqrt(pow(d->ray->raydirx, 2) + pow(d->ray->raydiry, 2));
	if (d->ray->side == 0)
	{
		d->ray->wallx = d->player->x + ((fabs(d->ray->sidedistx)
					* d->ray->raydirx / magnitudevector));
		d->ray->wally = d->player->y + ((fabs(d->ray->sidedistx)
					* d->ray->raydiry / magnitudevector));
	}
	else
	{
		d->ray->wallx = d->player->x + ((fabs(d->ray->sidedisty)
					* d->ray->raydirx / magnitudevector));
		d->ray->wally = d->player->y + ((fabs(d->ray->sidedisty)
					* d->ray->raydiry / magnitudevector));
	}
	if (d->ray->wallx < 0)
		d->ray->wallx *= -1;
	if (d->ray->wally < 0)
		d->ray->wally *= -1;
}

int	handle_input_time(int keysym, t_data *d)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if ((current_time.tv_sec - d->last_time.tv_sec) * 1000
		+ (current_time.tv_usec - d->last_time.tv_usec) / 1000 >= DELAY_MS)
	{
		handle_input(keysym, d);
		d->last_time = current_time;
	}
	return (0);
}
