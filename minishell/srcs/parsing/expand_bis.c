/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:34:46 by amontalb          #+#    #+#             */
/*   Updated: 2023/03/21 14:34:51 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

char	*sub_path(char *cmd, t_data *data, int i)
{
	char	*before;
	char	*path;

	before = NULL;
	if (i != 0)
	{
		before = ft_substr(cmd, 0, i);
		path = ft_strjoin(before, search_dico("HOME", data));
		free(before);
	}
	else
		path = ft_strdup(search_dico("HOME", data));
	i++;
	if (cmd[i])
	{
		before = strdup(path);
		path = ft_strjoin(before, &cmd[i]);
		free(before);
	}
	free (cmd);
	return (path);
}
