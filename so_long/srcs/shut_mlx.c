/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shut_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:29:23 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/04 17:07:30 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_all(t_data *var, char *msg)
{
	int	row;

	if (!msg || ft_strstr("closeNotification:", msg))
		ft_putstr_fd("Game closed", 1);
	else
		ft_putstr_fd(msg, 1);
	mlx_destroy_window(var->mlx, var->mlx_win);
	row = -1;
	if (var->map)
		ft_free_arr(var->map);
	free(var->mlx);
	ft_putstr_fd("\n", 1);
	exit(EXIT_FAILURE);
	return (0);
}
