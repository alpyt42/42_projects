/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:32:45 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/05 09:44:55 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_data *var)
{
	var->steps = 0;
	var->arg.en = 0;
	var->arg.ex = 0;
	var->arg.obj = 0;
	var->arg.start = 0;
	var->arg.win = 0;
}

void	check_args(t_data *var, int argc, char **argv)
{
	if (argc < 2)
		display_error(var, "\033[1;31mPlease provide a map\033[0m\n\
Ex: ./so_long maps/map.ber");
	if (argc > 2)
		display_error(var, "\033[1;31mToo many arguments.\n\033[0m\
Ex: ./so_long maps/map.ber");
	if (ft_strstr(argv[1], ".ber") == NULL)
		display_error(var, "Use .ber for maps");
}

int	main(int argc, char **argv)
{
	t_data	var;

	var.bt_map = NULL;
	var.map = NULL;
	check_args(&var, argc, argv);
	map_size(&var, argv);
	init_map(&var);
	load_map(&var, argv);
	check_map(&var);
	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx, var.col_map * SPRITE_W,
			var.row_map * SPRITE_H, "So long");
	ft_putstr_fd("Steps : ", 1);
	ft_putnbr_fd(var.steps, 1);
	ft_putstr_fd("\n", 1);
	mlx_hook(var.mlx_win, 2, 1L << 0, key, &var);
	mlx_hook(var.mlx_win, 17, 1L << 0, free_all, &var);
	print_map(&var);
	mlx_loop(var.mlx);
}
