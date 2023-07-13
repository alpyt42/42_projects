/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:19:35 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/17 11:37:12 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	d;
	t_mlx	mlx;

	start_set(&d, &mlx);
	d.mlx = &mlx;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		error(MLX_INIT_FAIL);
		return (ft_free_data(&d), 1);
	}
	d.ac = ac;
	d.av = av;
	if (!set_all(&d))
		return (ft_free_data(&d), 1);
	if (!start_mlx(&d, &mlx))
		return (ft_free_data(&d), 1);
	mlx_hook(d.mlx->win, 2, 1L << 0, handle_input_time, &d);
	mlx_hook(d.mlx->win, 17, 1L << 0, ft_free_data, &d);
	mlx_loop(mlx.mlx);
	return (0);
}
