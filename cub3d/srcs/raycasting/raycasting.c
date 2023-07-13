/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:33:40 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/17 20:17:51 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_step(t_data *d)
{
	if (d->ray->raydirx < 0)
	{
		d->ray->stepx = -1;
		d->ray->sidedistx = ((d->player->x - d->ray->mapx)
				* d->ray->deltadistx);
	}
	else
	{
		d->ray->stepx = 1;
		d->ray->sidedistx = ((1 + d->ray->mapx - d->player->x)
				* d->ray->deltadistx);
	}
	if (d->ray->raydiry < 0)
	{
		d->ray->stepy = -1;
		d->ray->sidedisty = ((d->player->y - d->ray->mapy)
				* d->ray->deltadisty);
	}
	else
	{
		d->ray->stepy = 1;
		d->ray->sidedisty = ((1 + d->ray->mapy - d->player->y)
				* d->ray->deltadisty);
	}
}

static void	ray_to_wall(t_data *d)
{
	while (d->ray->hit == 0)
	{
		if (d->ray->sidedistx < d->ray->sidedisty)
		{
			d->ray->sidedistx += d->ray->deltadistx;
			d->ray->mapx += d->ray->stepx;
			d->ray->side = 0;
		}
		else
		{
			d->ray->sidedisty += d->ray->deltadisty;
			d->ray->mapy += d->ray->stepy;
			d->ray->side = 1;
		}
		if (d->map[d->ray->mapx][d->ray->mapy] == '1')
			d->ray->hit = 1;
	}
	if (d->ray->side == 0)
		d->ray->p_to_wall_dist = (d->ray->mapx - d->player->x
				+ (1 - d->ray->stepx) / 2) / d->ray->raydirx;
	else
		d->ray->p_to_wall_dist = (d->ray->mapy - d->player->y
				+ (1 - d->ray->stepy) / 2) / d->ray->raydiry;
}

static void	size_wall(t_data *d)
{
	d->ray->height = (int)(WIN_HEIGHT / (d->ray->p_to_wall_dist));
	d->ray->draw_start = fmax((d->ray->height / 2) + (WIN_HEIGHT / 2), 0);
	d->ray->draw_end = fmin(-(d->ray->height / 2) + (WIN_HEIGHT / 2),
			WIN_HEIGHT - 1);
}

static int	init_ray(t_data *d, float i)
{
	d->ray->hit = 0;
	d->ray->mapx = (int)d->player->x;
	d->ray->mapy = (int)d->player->y;
	d->ray->camerax = 2 * i / WIN_WIDTH - 1.0;
	d->ray->raydirx = d->player->dirx + d->player->planx * d->ray->camerax;
	d->ray->raydiry = d->player->diry + d->player->plany * d->ray->camerax;
	d->ray->deltadistx = sqrt(1 + (d->ray->raydiry * d->ray->raydiry)
			/ (d->ray->raydirx * d->ray->raydirx));
	d->ray->deltadisty = sqrt(1 + (d->ray->raydirx * d->ray->raydirx)
			/ (d->ray->raydiry * d->ray->raydiry));
	return (1);
}

int	raycasting(t_data *d)
{
	int	x;

	x = 0;
	floor_ceiling(d);
	while (x < WIN_WIDTH)
	{
		init_ray(d, x);
		init_step(d);
		ray_to_wall(d);
		size_wall(d);
		hit_point(d);
		draw_wall(d, x);
		x++;
	}
	return (0);
}
