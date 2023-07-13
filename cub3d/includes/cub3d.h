/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:57:31 by ale-cont          #+#    #+#             */
/*   Updated: 2023/02/07 12:56:09 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*---------------------------------------*/

# include "../libs/libft/libft.h"
# include "../libs/mlx_linux/mlx.h"
# include <sys/time.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

/*-----------KEY----------------------*/

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define ESCAPE 65307

/*------------------------------------*/

# define FALSE 0
# define TRUE 1

# define LEFT 0
# define RIGHT 1

# define C 0
# define F 1

# define N 0
# define S 1
# define W 2
# define E 3

# define NW 0
# define NE 1
# define SW 2
# define SE 3

/*------error-messages----------------------------*/

# define MLX_INIT_FAIL	"MLX init failed"
# define MLX_WIN_FAIL	"MLX couldn't create a window"
# define MLX_IMG_FAIL	"MLX couldn't create an image"
# define PLAYER_SPAWN	"NSEW"
# define FREE_SPACES	"NSEW0"
# define MALLOC_ERR		"Malloc Error"
# define NB_IDS			"The ids must have key + value (PARSING ERROR)"
# define TOO_MANY_IDS	"Duplicates ids (PARSING ERROR)"
# define TOO_LOW_IDS	"Not enough identifiers"
# define PARSING		"PARSING ERROR"
# define COL_ERROR		"Invalid color input"
# define MLX_IMG_ERR	"The path to the img is not working"
# define MAP_MISSING	"Map not found"
# define INVALID_CHARS	"Map content contains invalid characters"
# define COUNT_P		"Map must have (only) one spawn"
# define MAP_WALL_ERR	"The map has to be surrounded by walls (1)"
# define MAP_ERR		"The error in map (it needs to be in one block)"
# define NB_ARG			"The number of arguments is wrong : one map (*.cub)"
# define MAP_EXT		"The map must have the .cub extension"
# define DELAY_MS		50
# define WIN_WIDTH		1600
# define WIN_HEIGHT		1000

/*-------COLORS---------------------------*/

# define DEFAULT "\001\033[0;39m\002"
# define GRAY "\001\033[1;90m\002"
# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define YELLOW "\001\033[1;93m\002"
# define BLUE "\001\033[1;94m\002"
# define MAGENTA "\001\033[1;95m\002"
# define CYAN "\001\033[1;96m\002"
# define WHITE "\001\033[0;97m\002"

/*-------STRUCT---------------------------*/

typedef struct s_data	t_data;
typedef struct s_ray	t_ray;
typedef struct s_dico	t_dico;
typedef struct s_player	t_player;
typedef struct s_mlx	t_mlx;
typedef struct s_img	t_img;
typedef struct s_map	t_map;

struct s_img
{
	void	*ptr;
	int		bpp;
	int		width;
	int		height;
	char	*add;
	int		len_line;
	int		endian;
};

struct s_data
{
	int				ac;
	char			**av;
	char			**map;
	int				fd_map;
	int				**col;
	int				sizex;
	int				sizey;
	struct timeval	last_time;
	uint32_t		ceiling;
	uint32_t		floor;
	t_img			*imgback;
	t_img			*imgwall;
	t_list			*h_dico;
	t_img			*imgs;
	t_mlx			*mlx;
	t_player		*player;
	t_ray			*ray;
};

struct s_dico
{
	char	*key;
	char	*val;
};

struct s_ray
{
	float	camerax;
	float	raydirx;
	float	raydiry;
	float	sidedistx;
	float	sidedisty;
	float	deltadistx;
	float	deltadisty;
	float	p_to_wall_dist;
	float	wallx;
	float	wally;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		height;
	int		draw_start;
	int		draw_end;
	int		orientation_wall;
	int		side;
	int		hit;
};

struct s_player
{
	float	x;
	float	y;
	float	dirx;
	float	diry;	
	int		mapx;
	int		mapy;
	float	planx;
	float	plany;
	int		orientation;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	int		*img;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		bpp;
};

/*--parsing-----------------------------*/

void		*parse(t_data *d);
void		*get_keys(t_data *d);
void		*check_keys(t_data *d);
void		*get_map(t_data *d);
void		*check_map(t_data *d, int i, int j, int p);
void		*start_set(t_data *d, t_mlx *mlx);
char		*search_dico(char *search, t_data *d);
t_dico		*init_dico(void);
void		*add_dico(t_list **h_dico, char *key, char *val);
void		*check_keys(t_data *d);
void		start_player_orientation(t_data *d);
void		*set_color_img(t_data *d);
void		*set_all(t_data *d);
void		start_plan_vector(t_data *d);
void		start_player_orientation(t_data *d);

/*--raycasting---------------------------*/

void		move(t_data *d);
void		draw_wall(t_data *d, int x);
int			floor_ceiling(t_data *d);
int			raycasting(t_data *d);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		*start_mlx(t_data *d, t_mlx *mlx);
void		set_img_mlx(t_data *d);
int			handle_input(int keysym, t_data *d);
t_img		*create_img(t_mlx *mlx, int width, int height);
void		display_map(t_data *d);
void		hit_point(t_data *d);
int			handle_input_time(int keysym, t_data *d);

/*--utils------------------------------*/

void		*error(char *str);
int			ft_free_data(t_data *d);
void		*check_arr_type(char **str);
int			count_char(char *val, char c);
char		*rm_ret_gnl(int fd, char *gnl);
void		get_size_map(t_data *d);

#endif