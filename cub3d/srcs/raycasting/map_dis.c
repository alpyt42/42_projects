/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:16:51 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/17 20:41:43 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_arrow_player(t_data *d, int x, int y, int color)
{
	int	dx;
	int	dy;
	int	pixel_x;
	int	pixel_y;

	dy = 1;
	while (++dy < 8)
	{
		dx = 1;
		while (++dx < 8)
		{
			pixel_x = x * 10 + dx + 22;
			pixel_y = y * 10 + dy + 22;
			if (d->player->orientation == 'W' && dx >= 5)
				my_mlx_pixel_put(d, pixel_x, pixel_y, color);
			else if (d->player->orientation == 'E' && dx <= 5)
				my_mlx_pixel_put(d, pixel_x, pixel_y, color);
			else if (d->player->orientation == 'N' && dy >= 5)
				my_mlx_pixel_put(d, pixel_x, pixel_y, color);
			else if (d->player->orientation == 'S' && dy <= 5)
				my_mlx_pixel_put(d, pixel_x, pixel_y, color);
			else
				my_mlx_pixel_put(d, pixel_x, pixel_y, 0x00FF00);
		}
	}
}

static void	printmap(t_data *d, int x, int y, int color)
{
	int	dx;
	int	dy;
	int	pixel_x;
	int	pixel_y;

	dy = -1;
	while (++dy < 10)
	{
		dx = -1;
		while (++dx < 10)
		{
			pixel_x = x * 10 + dx;
			pixel_y = y * 10 + dy;
			my_mlx_pixel_put(d, pixel_x + 22, pixel_y + 22, color);
		}
	}
	if (color == 0xFF0000)
		draw_arrow_player(d, x, y, color);
}

static void	dis_map(t_data *d, int zoomed[2], int pos[2], int size)
{
	int	tile_x;
	int	tile_y;
	int	x;
	int	y;
	int	color;

	y = -1;
	color = 0;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			tile_x = zoomed[0] + x;
			tile_y = zoomed[1] + y;
			if (!d->map[tile_y][tile_x] || d->map[tile_y][tile_x] == '1')
				color = 0x000000;
			else if (tile_x == pos[0] && tile_y == pos[1])
				color = 0xFF0000;
			else if (ft_strchr("NSWE ", d->map[tile_y][tile_x])
				|| d->map[tile_y][tile_x] == '0')
				color = 0x888888;
			printmap(d, x, y, color);
		}
	}
}

static void	zoom_init(t_data *d, int *zoomed, int *pos, int size)
{
	zoomed[0] = pos[0] - size / 2;
	zoomed[1] = pos[1] - size / 2;
	if (zoomed[0] < 0)
		zoomed[0] = 0;
	if (zoomed[1] < 0)
		zoomed[1] = 0;
	if (zoomed[0] > d->sizex - size)
		zoomed[0] = d->sizex - size;
	if (zoomed[1] > d->sizey - size)
		zoomed[1] = d->sizey - size;
}

void	display_map(t_data *d)
{
	int	zoomed[2];
	int	pos[2];
	int	size;

	pos[0] = d->player->y;
	pos[1] = d->player->x;
	size = 0;
	if (d->sizex > 40 && d->sizey > 40)
		size = 26;
	else if (d->sizex <= 5 || d->sizey <= 5)
		return ;
	else if (d->sizex <= d->sizey)
		size = d->sizex;
	else if (d->sizey < d->sizex)
		size = d->sizey;
	zoom_init(d, zoomed, pos, size);
	dis_map(d, zoomed, pos, size);
}
