/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:40:02 by ale-cont          #+#    #+#             */
/*   Updated: 2023/02/03 19:00:06 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_in_arr(char **arr, char *to_find)
{
	int	i;

	i = -1;
	if (!arr || !to_find)
		return (NULL);
	while (arr[++i])
		if (ft_strstr(arr[i], to_find))
			return (&(arr[i][ft_strlen(to_find)]));
	return (NULL);
}

int	set_env_vars(t_data *data, char *glob_var, char *val)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strjoin(glob_var, val);
	while (data->env && data->env[++i])
	{
		if (data->env && data->env[i] && ft_strstr(data->env[i], glob_var))
		{
			free(data->env[i]);
			data->env[i] = tmp;
			return (1);
		}
	}
	data->env = ft_append_tab(data->env, tmp);
	free(tmp);
	return (1);
}

void	init_dico(t_data *data)
{
	int		i;
	int		j;
	int		k;
	int		lenone;
	char	**cmd;

	i = 0;
	j = -1;
	k = 0;
	lenone = 0;
	while (data->env[i])
	{
		cmd = mini_split(data->env[i], j, k, lenone);
		ft_lstadd_back(&data->dico, ft_lstnew(cmd));
		i++;
	}
}

char	*search_dico(char *search, t_data *data)
{
	char	**cmd;
	void	*tmp;

	tmp = data->dico;
	while (data->dico)
	{
		cmd = data->dico->content;
		if (!ft_strncmp(cmd[0], search, ft_strlen(search))
			&& ft_strlen(cmd[0]) == ft_strlen(search))
		{
			data->dico = tmp;
			return (cmd[1]);
		}
		data->dico = data->dico->next;
	}
	data->dico = tmp;
	return (NULL);
}
