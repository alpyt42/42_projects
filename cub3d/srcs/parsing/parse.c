/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:20:20 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/17 18:45:10 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_pos_player(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	while (d->map[++i])
	{
		j = -1;
		while (d->map[i][++j])
		{
			if (ft_strchr("NSWE", d->map[i][j]))
			{
				d->player->x = i + 0.5;
				d->player->y = j + 0.5;
				d->player->orientation = d->map[i][j];
			}
			if (d->map[i][j] == ' ')
				d->map[i][j] = '1';
		}
	}
}

static uint32_t	rgb_to_hex(int r, int g, int b)
{
	uint32_t	hex;

	hex = 0;
	hex |= r << 16;
	hex |= g << 8;
	hex |= b;
	return (hex);
}

void	*parse(t_data *d)
{
	if (d->ac != 2 || !(d->av[1]) || !(d->av[1][0]))
		return (error(NB_ARG));
	if (!ft_strstr(d->av[1], ".cub")
		|| ft_strstr(d->av[1], ".cub")[4])
		return (error(MAP_EXT));
	d->fd_map = open(d->av[1], O_RDONLY);
	if (d->fd_map == -1)
		return (error(strerror(errno)));
	if (!get_keys(d))
		return (NULL);
	if (!check_keys(d))
		return (NULL);
	if (!get_map(d))
		return (NULL);
	if (!check_map(d, -1, -1, 0))
		return (NULL);
	return ("");
}

void	*set_all(t_data *d)
{
	if (!parse(d))
		return (NULL);
	get_size_map(d);
	d->floor = rgb_to_hex(d->col[F][0], d->col[F][1], d->col[F][2]);
	d->ceiling = rgb_to_hex(d->col[C][0], d->col[C][1], d->col[C][2]);
	d->imgback = create_img(d->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->imgwall = create_img(d->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->player = malloc(sizeof(t_player));
	if (!d->player)
		return (error(MALLOC_ERR));
	get_pos_player(d);
	start_player_orientation(d);
	start_plan_vector(d);
	if (!d->imgback || !d->imgwall)
		return (NULL);
	set_img_mlx(d);
	d->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!d->ray)
		return (error(MALLOC_ERR));
	return ("");
}
