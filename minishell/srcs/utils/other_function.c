/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:45:23 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/27 17:39:53 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strchars_i(const char *s, char *set)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (-1);
	while (s[i])
	{
		if (ft_strchr(set, s[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	pos_in_arr(char **arr, char *to_find, char set)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(to_find);
	while (arr[++i])
	{
		if (!ft_strncmp(arr[i], to_find, len)
			&& arr[i][len] && arr[i][len] == set)
			return (i);
	}
	return (-1);
}

void	display_arr(char **arr, char *info, int opt)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	if (opt)
	{
		while (arr[++i])
			ft_dprintf(1, "%s\n", arr[i]);
	}
	else
	{
		while (arr[++i])
		{
			if (arr[i] && arr[i][0] && arr[i][0] != '_')
				ft_dprintf(1, "%s%s\n", info, arr[i]);
		}
	}
}

char	**mini_split(char *str, int i, int j, int lenone)
{
	int		lentwo;
	char	**res;

	lentwo = 0;
	if (!str)
		return (NULL);
	res = ft_calloc(sizeof(char *), 3);
	if (!res)
		return (NULL);
	while (str[lenone] && str[lenone] != '=')
		lenone++;
	if (str[lenone])
		lentwo = ft_strlen(str + lenone);
	res[0] = ft_calloc(sizeof(char), lenone + 1);
	if (lentwo > 0)
		res[1] = ft_calloc(sizeof(char), lentwo);
	if (!res[0] || (!res[1] && lentwo > 0))
		return (NULL);
	while (++i < lenone)
		res[0][i] = str[i];
	i++;
	if (str[lenone])
		while (str[i])
			res[1][j++] = str[i++];
	return (res);
}

int	ft_str_isalnum(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (1);
	return (0);
}
