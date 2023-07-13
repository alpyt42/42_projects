/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:56:24 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/17 18:34:46 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*start_mlx(t_data *d, t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	if (!mlx->win)
		return (error(MLX_WIN_FAIL));
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->size_line, &mlx->endian);
	raycasting(d);
	display_map(d);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return ("");
}

t_img	*create_img(t_mlx *mlx, int width, int height)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (error(MALLOC_ERR));
	img->ptr = mlx_new_image(mlx->mlx, width, height);
	if (!img->ptr)
		return (error(MLX_IMG_FAIL));
	img->add = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->len_line, &img->endian);
	return (img);
}

void	set_img_mlx(t_data *d)
{
	d->imgs[N].add = mlx_get_data_addr(d->imgs[N].ptr,
			&(d->imgs[N].bpp), &(d->imgs[N].len_line), &(d->imgs[N].endian));
	d->imgs[S].add = mlx_get_data_addr(d->imgs[S].ptr,
			&(d->imgs[S].bpp), &(d->imgs[S].len_line), &(d->imgs[S].endian));
	d->imgs[W].add = mlx_get_data_addr(d->imgs[W].ptr,
			&(d->imgs[W].bpp), &(d->imgs[W].len_line), &(d->imgs[W].endian));
	d->imgs[E].add = mlx_get_data_addr(d->imgs[E].ptr,
			&(d->imgs[E].bpp), &(d->imgs[E].len_line), &(d->imgs[E].endian));
}
