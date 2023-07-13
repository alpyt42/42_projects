/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:30:51 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/04 17:17:24 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_user_position(t_data *var)
{
	int	row;
	int	col;

	row = -1;
	while (++row < var->row_map)
	{
		col = -1;
		while (++col < var->col_map)
		{
			if (var->map[row][col] == 'P')
			{
				var->row_user = row;
				var->col_user = col;
			}
		}
	}
}

static void	get_exit_position(t_data *var)
{
	int	row;
	int	col;

	row = -1;
	while (++row < var->row_map)
	{
		col = -1;
		while (++col < var->col_map)
		{
			if (var->map[row][col] == 'E')
			{
				var->row_ex = row;
				var->col_ex = col;
			}
		}
	}
}

void	get_position(t_data *var)
{
	get_user_position(var);
	get_exit_position(var);
}
