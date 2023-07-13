/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:26:03 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/18 13:21:53 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*set_color_img(t_data *d)
{
	int	i;

	i = -1;
	d->col = (int **)malloc(sizeof(int *) * 2);
	if (!d->col)
		return (error(MALLOC_ERR));
	d->col[C] = NULL;
	d->col[F] = NULL;
	d->col[C] = (int *)malloc(sizeof(int) * 3);
	if (!d->col[C])
		return (free(d->col), error(MALLOC_ERR));
	d->col[F] = (int *)malloc(sizeof(int) * 3);
	if (!d->col[F])
		return (free(d->col[C]), free(d->col), error(MALLOC_ERR));
	d->imgs = malloc(sizeof(t_img) * 4);
	if (!d->imgs)
		return (free(d->col[C]), free(d->col[F]), free(d->col),
			error(MALLOC_ERR));
	while (++i < 4)
		d->imgs[i].ptr = NULL;
	return ("");
}

void	*start_set(t_data *d, t_mlx *mlx)
{
	d->player = NULL;
	gettimeofday(&d->last_time, NULL);
	d->ac = 0;
	d->av = NULL;
	d->fd_map = -1;
	d->col = NULL;
	d->map = NULL;
	d->sizex = -1;
	d->sizey = -1;
	d->imgback = NULL;
	d->imgwall = NULL;
	d->h_dico = NULL;
	d->imgs = NULL;
	d->mlx = NULL;
	d->ray = NULL;
	mlx->mlx = NULL;
	mlx->img = NULL;
	mlx->win = NULL;
	return (NULL);
}

void	start_player_orientation(t_data *d)
{
	if (d->player->orientation == 'W')
	{
		d->player->diry = -1;
		d->player->dirx = 0;
	}
	if (d->player->orientation == 'E')
	{
		d->player->diry = 1;
		d->player->dirx = 0;
	}
	if (d->player->orientation == 'N')
	{
		d->player->dirx = -1;
		d->player->diry = 0;
	}
	if (d->player->orientation == 'S')
	{
		d->player->dirx = 1;
		d->player->diry = 0;
	}
}

void	start_plan_vector(t_data *d)
{
	if (d->player->orientation == 'W')
	{
		d->player->planx = -0.70;
		d->player->plany = 0;
	}
	if (d->player->orientation == 'E')
	{
		d->player->planx = 0.70;
		d->player->plany = 0;
	}
	if (d->player->orientation == 'N')
	{
		d->player->planx = 0;
		d->player->plany = 0.70;
	}
	if (d->player->orientation == 'S')
	{
		d->player->planx = 0;
		d->player->plany = -0.70;
	}
}
