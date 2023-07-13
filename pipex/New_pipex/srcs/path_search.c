/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:24:29 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/30 17:42:03 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_cmd_path(char *cmd, char **env)
{
	int		j;
	char	*test_path;

	j = 0;
	if (!access(cmd, F_OK))
		return (cmd);
	while (env[j])
	{
		// dprintf(1, "env[%d] : %s\n", j, env[j]);
		test_path = ft_strjoin(env[j], cmd);
		// dprintf(1, "test_path : %s\n", test_path);
		if (!access(test_path, F_OK))
			return (test_path);
		free(test_path);
		j++;
	}
	return (NULL);
}

int	pos_path(char **env)
{
	int		i;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
		i++;
	if (env[i] && ft_strnstr(env[i], "PATH=", 5))
		return (i);
	return (-1);
}

void	get_path(t_data *p)
{
	char	*tmp;
	char	**path_env;
	int		pos;
	int		i;

	i = 0;
	pos = pos_path(p->en);
	if (pos == -1)
		exit(EXIT_FAILURE);
	path_env = ft_split(p->en[pos] + 5, ':');
	while (path_env[i])
	{
		tmp = ft_strjoin(path_env[i], "/");
		free(path_env[i]);
		path_env[i] = tmp;
		i++;
	}
	p->en_cmd = path_env;
}