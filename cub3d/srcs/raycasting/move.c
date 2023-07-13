/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:26:52 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/17 11:30:47 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_left(t_data *d)
{
	if (d->player->orientation == 'N')
		d->player->orientation = 'W';
	else if (d->player->orientation == 'W')
		d->player->orientation = 'S';
	else if (d->player->orientation == 'S')
		d->player->orientation = 'E';
	else if (d->player->orientation == 'E')
		d->player->orientation = 'N';
	start_player_orientation(d);
	start_plan_vector(d);
	move (d);
}

void	look_right(t_data *d)
{
	if (d->player->orientation == 'N')
		d->player->orientation = 'E';
	else if (d->player->orientation == 'E')
		d->player->orientation = 'S';
	else if (d->player->orientation == 'S')
		d->player->orientation = 'W';
	else if (d->player->orientation == 'W')
		d->player->orientation = 'N';
	start_player_orientation(d);
	start_plan_vector(d);
	move (d);
}

void	move_right(t_data *d)
{
	if (d->player->orientation == 'E'
		&& d->map[(int)(d->player->x + 1)][(int)(d->player->y)] != '1')
	{
		d->player->x += 1;
		move(d);
	}
	else if (d->player->orientation == 'S'
		&& d->map[(int)(d->player->x)][(int)(d->player->y - 1)] != '1')
	{
		d->player->y -= 1;
		move(d);
	}
	else if (d->player->orientation == 'W'
		&& d->map[(int)(d->player->x - 1)][(int)(d->player->y)] != '1')
	{
		d->player->x -= 1;
		move(d);
	}
	else if (d->player->orientation == 'N'
		&& d->map[(int)(d->player->x)][(int)(d->player->y + 1)] != '1')
	{
		d->player->y += 1;
		move(d);
	}
}

void	move_left(t_data *d)
{
	if (d->player->orientation == 'E'
		&& d->map[(int)(d->player->x - 1)][(int)(d->player->y)] != '1')
	{
		d->player->x -= 1;
		move(d);
	}
	else if (d->player->orientation == 'S'
		&& d->map[(int)(d->player->x)][(int)(d->player->y + 1)] != '1')
	{
		d->player->y += 1;
		move(d);
	}
	else if (d->player->orientation == 'W'
		&& d->map[(int)(d->player->x + 1)][(int)(d->player->y)] != '1')
	{
		d->player->x += 1;
		move(d);
	}
	else if (d->player->orientation == 'N'
		&& d->map[(int)(d->player->x)][(int)(d->player->y - 1)] != '1')
	{
		d->player->y -= 1;
		move(d);
	}
}

int	handle_input(int keysym, t_data *d)
{
	if (keysym == 65307)
		exit(ft_free_data(d));
	if (keysym == KEY_W && d->map[(int)(d->player->x + d->player->dirx)]
		[(int)(d->player->y + d->player->diry)] != '1')
	{
		d->player->x += d->player->dirx;
		d->player->y += d->player->diry;
		move (d);
	}
	if (keysym == KEY_S && d->map[(int)(d->player->x - d->player->dirx)]
		[(int)(d->player->y - d->player->diry)] != '1')
	{
		d->player->x -= d->player->dirx;
		d->player->y -= d->player->diry;
		move (d);
	}
	if (keysym == 65363)
		look_right(d);
	if (keysym == 65361)
		look_left(d);
	if (keysym == KEY_A)
		move_left(d);
	if (keysym == KEY_D)
		move_right(d);
	return (0);
}
