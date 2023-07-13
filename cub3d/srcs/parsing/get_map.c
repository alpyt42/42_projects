/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:52:30 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/18 12:53:32 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*check_map(t_data *d, int i, int j, int p)
{
	while (d->map[++i])
	{
		j = -1;
		while (d->map[i][++j])
		{
			if (!ft_strchr("NSWE 01", d->map[i][j]))
				return (error(INVALID_CHARS));
			if (ft_strchr("NSWE", d->map[i][j]))
				p++;
			if (ft_strchr("NSWE0", d->map[i][j])
				&& ((i == 0 || i == ft_arrlen(d->map) - 1)
				|| (j == 0 || j == (int)ft_strlen(d->map[i]) - 1)
				|| ((int)ft_strlen(d->map[i - 1]) <= j)
				|| ((int)ft_strlen(d->map[i + 1]) <= j)
				|| (d->map[i - 1][j] == ' ' || d->map[i][j - 1] == ' ')
				|| (d->map[i + 1][j] == ' ' || d->map[i][j + 1] == ' ')))
				return (error(MAP_WALL_ERR));
		}
	}
	if (p != 1)
		return (error(COUNT_P));
	return ("");
}

void	*get_map(t_data *d)
{
	char	*gnl;
	char	*tmp;
	char	*map;

	gnl = NULL;
	gnl = rm_ret_gnl(d->fd_map, gnl);
	if (!gnl)
		return (error(MAP_MISSING));
	map = NULL;
	while (gnl && gnl[0] && gnl[0] != '\n')
	{
		tmp = map;
		map = ft_strjoin(map, gnl);
		free(tmp);
		free(gnl);
		gnl = get_next_line(d->fd_map);
	}
	gnl = rm_ret_gnl(d->fd_map, gnl);
	if (gnl)
		return (free(map), free(gnl), error(MAP_ERR));
	d->map = ft_split(map, '\n');
	free(map);
	if (!d->map)
		return (error(MALLOC_ERR));
	return ("");
}
