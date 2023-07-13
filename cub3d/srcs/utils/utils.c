/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:24:14 by amontalb          #+#    #+#             */
/*   Updated: 2023/04/18 13:08:57 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*error(char *str)
{
	ft_dprintf(2, "ERROR\n");
	if (!str)
		return (NULL);
	else
		ft_dprintf(2, "%s\n", str);
	return (NULL);
}

void	*check_arr_type(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			if (!ft_isdigit(str[i][j]))
				return (NULL);
	}
	return ("");
}

int	count_char(char *val, char c)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	if (!val)
		return (0);
	while (val[++i])
		if (val[i] == c)
			len++;
	return (len);
}
