/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:20:50 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/05 09:09:13 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_find_char(char **str, char c)
{
	int	row;
	int	col;

	row = -1;
	while (str[++row])
	{
		col = -1;
		while (str[row][++col])
			if (str[row][col] == c)
				return (1);
	}
	return (0);
}

static int	check_arg(t_data *var)
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
				var->arg.ex++;
			if (var->map[row][col] == 'C')
				var->arg.obj++;
			if (var->map[row][col] == 'P')
				var->arg.start++;
			if (var->map[row][col] == 'U')
				var->arg.en++;
			if (!ft_strchr("10CEUP", (int)var->map[row][col]))
				return (2);
		}
	}
	if (var->arg.ex != 1 || var->arg.obj == 0
		|| var->arg.start != 1)
		return (1);
	return (0);
}

static int	check_wall(t_data *var)
{
	int	row;
	int	col;

	row = -1;
	while (++row < var->row_map)
	{
		if ((int)ft_strlen(var->map[row]) != (var->col_map))
			return (2);
		col = -1;
		while (++col < var->col_map)
		{
			if (col == 0 || row == 0 || row == (var->row_map - 1)
				|| col == (var->col_map - 1))
				if (var->map[row][col] != '1')
					return (1);
		}
	}
	return (0);
}

static void	backtracking(t_data *var, int row, int col)
{
	if (var->bt_map[row - 1][col] != '1' &&
		var->bt_map[row - 1][col] != 'U')
	{
		var->bt_map[row - 1][col] = '1';
		backtracking(var, row - 1, col);
	}
	if (var->bt_map[row + 1][col] != '1' &&
		var->bt_map[row + 1][col] != 'U')
	{
		var->bt_map[row + 1][col] = '1';
		backtracking(var, row + 1, col);
	}
	if (var->bt_map[row][col - 1] != '1' &&
		var->bt_map[row][col - 1] != 'U')
	{
		var->bt_map[row][col - 1] = '1';
		backtracking(var, row, col - 1);
	}
	if (var->bt_map[row][col + 1] != '1' &&
		var->bt_map[row][col + 1] != 'U')
	{
		var->bt_map[row][col + 1] = '1';
		backtracking(var, row, col + 1);
	}
	var->bt_map[row][col] = '1';
}

void	check_map(t_data *var)
{
	int	check_w;
	int	check_a;

	check_w = check_wall(var);
	check_a = check_arg(var);
	if (check_w == 2)
		display_error(var, "Invalid map (Map is not a rectangle)!");
	if (check_w == 1)
		display_error(var, "Invalid map (Must be surrounded by 1)!");
	if (check_a == 1)
		display_error(var, "Invalid map: Map must have :1 'E', 1 'P', many'C'");
	if (check_a == 2)
		display_error(var, "Invalid map (Some characters are invalids)!");
	get_position(var);
	backtracking(var, var->row_user, var->col_user);
	if (ft_find_char(var->bt_map, 'C') || ft_find_char(var->bt_map, 'E'))
		display_error(var, "\033[1;33mInvalid map (No path found)!\033[0m");
	ft_free_arr(var->bt_map);
}
