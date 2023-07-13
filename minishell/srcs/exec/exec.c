/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:20:28 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/20 17:48:52 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_cmd_path(char *cmd, char **env)
{
	int		j;
	char	*test_path;

	j = 0;
	if (!access(cmd, F_OK) && ft_strchr(cmd, '/'))
		return (cmd);
	while (env[j])
	{
		test_path = ft_strjoin(env[j], cmd);
		if (!access(test_path, F_OK))
			return (test_path);
		free(test_path);
		j++;
	}
	return (NULL);
}

static char	*get_path(t_data *p, char **cmd)
{
	char	*tmp;
	char	*res;
	char	**path_env;
	int		pos;
	int		i;

	i = 0;
	pos = pos_in_arr(p->env, "PATH", '=');
	if (pos == -1)
		return (NULL);
	path_env = ft_split(p->env[pos] + 5, ':');
	if (!path_env)
		return (NULL);
	while (path_env[i])
	{
		tmp = ft_strjoin(path_env[i], "/");
		if (!tmp)
			return (ft_free_arr(path_env), NULL);
		free(path_env[i]);
		path_env[i] = tmp;
		i++;
	}
	res = get_cmd_path(*cmd, path_env);
	ft_free_arr(path_env);
	return (res);
}

static void	check_cmd(t_data *d, t_node *n)
{
	char	**tmp;

	if (n && n->all_cmd && ft_strchr(*n->all_cmd, '/'))
	{
		tmp = ft_split(*n->all_cmd, '/');
		n->all_path = ft_strdup(*n->all_cmd);
		free(*n->all_cmd);
		*n->all_cmd = ft_strdup(tmp[ft_arrlen(tmp) - 1]);
		ft_free_arr(tmp);
	}
	else if (n && n->all_cmd && is_builtin(n) < 0)
		n->all_path = get_path(d, n->all_cmd);
	if (n && is_builtin(n) < 0 && n->all_cmd && !n->all_path)
		print_error(NCMD, *n->all_cmd, NULL, 127);
}

static void	find_cmd(t_data *d, t_list *cmd)
{
	t_node	*n;
	DIR		*dir;
	char	*tmp;

	dir = NULL;
	n = cmd->content;
	tmp = ft_strdup(n->all_cmd[0]);
	if (n && n->all_cmd)
		dir = opendir(tmp);
	if (!dir)
		check_cmd(d, n);
	if (dir && access(n->all_path, F_OK) == -1
		&& is_builtin(n) < 0)
		print_error(IS_DIR, "", tmp, 126);
	else if (n && n->all_path
		&& access(n->all_path, F_OK) == -1 && is_builtin(n) < 0)
		print_error(NDIR, "", tmp, 1);
	else if (n && n->all_path && access(n->all_path, X_OK) == -1
		&& is_builtin(n) < 0)
		print_error(NPERM, "", *n->all_cmd, 126);
	if (dir)
		closedir(dir);
	if (tmp)
		free (tmp);
}

void	*exec(t_data *data, t_list *cmd)
{
	int	fd[2];

	find_cmd(data, cmd);
	if (pipe(fd) == -1)
	{
		ft_free_mini(data);
		return (print_error(PIPERR, NULL, NULL, errno));
	}
	if (!fork_fct(data, cmd, fd))
		return ("");
	close(fd[1]);
	if (cmd->next && !((t_node *)cmd->next->content)->infile)
		((t_node *)cmd->next->content)->infile = fd[0];
	else
		close(fd[0]);
	if (((t_node *)cmd->content)->infile > 2)
		close(((t_node *)cmd->content)->infile);
	if (((t_node *)cmd->content)->outfile > 2)
		close(((t_node *)cmd->content)->outfile);
	return ("");
}
