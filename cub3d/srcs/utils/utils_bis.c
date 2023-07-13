/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:50:44 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/18 12:52:45 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*rm_ret_gnl(int fd, char *gnl)
{
	if (!gnl)
		gnl = get_next_line(fd);
	while (gnl && gnl[0] && gnl[0] == '\n')
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (gnl);
}

void	get_size_map(t_data *d)
{
	int	len;

	len = 0;
	while (d->map[++d->sizey])
	{
		len = (int)ft_strlen(d->map[d->sizey]);
		if (len > d->sizex)
			d->sizex = len;
	}
}
