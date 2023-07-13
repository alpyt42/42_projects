/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:15:29 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/17 12:52:30 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_wall_bis(t_data *d, int i[3], int img, int side)
{
	int		x2;
	int		y2;
	char	*color;

	if (side == 0)
		x2 = fmod(d->ray->wally, 1) * d->imgs[img].width;
	else
		x2 = fmod(d->ray->wallx, 1) * d->imgs[img].width;
	y2 = i[2] * d->imgs[img].height / d->ray->height;
	color = (d->imgs[img].add + (int)(y2 * d->imgs[img].len_line + x2
				* (d->imgs[img].bpp / 8)));
	my_mlx_pixel_put(d, i[0], i[1], *(int *)color);
}

void	draw_wall(t_data *d, int x)
{	
	int		i[3];

	i[0] = x;
	i[1] = d->ray->draw_end;
	i[2] = 0;
	while (i[2] < d->ray->height)
	{
		if (d->ray->side == 0 && d->ray->raydirx > 0)
			draw_wall_bis(d, i, S, 0);
		else if (d->ray->side == 0)
			draw_wall_bis(d, i, N, 0);
		else if (d->ray->raydiry > 0)
			draw_wall_bis(d, i, E, 1);
		else
			draw_wall_bis(d, i, W, 1);
		i[1]++;
		i[2]++;
	}
}
