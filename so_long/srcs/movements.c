/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:49:17 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/05 11:40:21 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	up(t_data *var)
{
	if (var->map[var->row_user + 1][var->col_user] == 'C')
		var->arg.obj--;
	if (var->map[var->row_user + 1][var->col_user] == 'U')
	{
		var->map[var->row_user + 1][var->col_user] = 'l';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->row_user++;
	}
	else if (var->map[var->row_user + 1][var->col_user] == 'E')
	{
		var->map[var->row_user + 1][var->col_user] = 'h';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->row_user++;
	}
	else if (var->map[var->row_user + 1][var->col_user] == 'C' ||
			var->map[var->row_user + 1][var->col_user] == '0')
	{
		var->map[var->row_user + 1][var->col_user] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->row_user++;
	}
}

static void	down(t_data *var)
{
	if (var->map[var->row_user - 1][var->col_user] == 'C')
		var->arg.obj--;
	if (var->map[var->row_user - 1][var->col_user] == 'U')
	{
		var->map[var->row_user - 1][var->col_user] = 'l';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->row_user--;
	}
	else if (var->map[var->row_user - 1][var->col_user] == 'E')
	{
		var->map[var->row_user - 1][var->col_user] = 'h';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->row_user--;
	}
	else if (var->map[var->row_user - 1][var->col_user] == 'C' ||
			var->map[var->row_user - 1][var->col_user] == '0')
	{
		var->map[var->row_user - 1][var->col_user] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->row_user--;
	}
}

static void	right(t_data *var)
{
	if (var->map[var->row_user][var->col_user + 1] == 'C')
		var->arg.obj--;
	if (var->map[var->row_user][var->col_user + 1] == 'U')
	{
		var->map[var->row_user][var->col_user + 1] = 'l';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->col_user++;
	}
	else if (var->map[var->row_user][var->col_user + 1] == 'E')
	{
		var->map[var->row_user][var->col_user + 1] = 'h';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->col_user++;
	}
	else if (var->map[var->row_user][var->col_user + 1] == 'C' ||
			var->map[var->row_user][var->col_user + 1] == '0')
	{
		var->map[var->row_user][var->col_user + 1] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->col_user++;
	}
}

static void	left(t_data *var)
{
	if (var->map[var->row_user][var->col_user - 1] == 'C')
		var->arg.obj--;
	if (var->map[var->row_user][var->col_user - 1] == 'U')
	{
		var->map[var->row_user][var->col_user - 1] = 'l';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->col_user--;
	}
	else if (var->map[var->row_user][var->col_user - 1] == 'E')
	{
		var->map[var->row_user][var->col_user - 1] = 'h';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->col_user--;
	}
	else if (var->map[var->row_user][var->col_user - 1] == 'C' ||
			var->map[var->row_user][var->col_user - 1] == '0')
	{
		var->map[var->row_user][var->col_user - 1] = 'P';
		var->map[var->row_user][var->col_user] = '0';
		var->steps++;
		var->col_user--;
	}
}

void	check_move(t_data *var, int key)
{
	if ((key == 1)
		&& var->map[var->row_user + 1][var->col_user] == 'e')
		winner(var, 'U');
	else if (key == 1)
		up(var);
	else if ((key == 13)
		&& var->map[var->row_user - 1][var->col_user] == 'e')
		winner(var, 'D');
	else if (key == 13)
		down(var);
	else if ((key == 0)
		&& var->map[var->row_user][var->col_user - 1] == 'e')
		winner(var, 'L');
	else if (key == 0)
		left(var);
	else if ((key == 2)
		&& var->map[var->row_user][var->col_user + 1] == 'e')
		winner(var, 'R');
	else if (key == 2)
		right(var);
	if ((var->row_ex != var->row_user || var->col_ex != var->col_user)
		&& var->arg.win == 0)
		var->map[var->row_ex][var->col_ex] = 'E';
}
