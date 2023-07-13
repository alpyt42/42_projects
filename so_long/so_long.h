/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:37:11 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/09 09:59:43 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# define SPRITE_H				64
# define SPRITE_W				64

typedef struct s_map {
	int	obj;
	int	start;
	int	ex;
	int	en;
	int	win;
}	t_map;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		col_img;
	int		row_img;
	int		col_map;
	int		row_map;
	char	**map;
	char	**bt_map;
	int		steps;
	int		col_user;
	int		row_user;
	int		col_ex;
	int		row_ex;
	t_map	arg;
}	t_data;

void	display_error(t_data *var, char *error);
void	map_size(t_data *var, char **argv);
void	load_map(t_data *var, char **argv);
void	print_map(t_data *var);
void	check_map(t_data *var);
void	get_position(t_data *var);
int		key(int key, t_data *var);
void	check_move(t_data *var, int key);
int		free_all(t_data *var, char *msg);
int		ft_find_char(char **str, char c);
void	winner(t_data *var, char c);
void	check_args(t_data *var, int argc, char **argv);

#endif