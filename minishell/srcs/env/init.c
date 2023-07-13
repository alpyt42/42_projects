/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:33:30 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/22 15:56:01 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

static void	init_shlvl(t_data *data)
{
	char	*shlvl;

	shlvl = NULL;
	shlvl = find_in_arr(data->env, "SHLVL=");
	if (!shlvl)
		set_env_vars(data, "SHLVL=", "1");
	else if ((ft_atoi(shlvl) + 1) < 0)
		set_env_vars(data, "SHLVL=", "0");
	else
	{
		shlvl = ft_itoa((ft_atoi(shlvl) + 1));
		set_env_vars(data, "SHLVL=", shlvl);
		free(shlvl);
	}
}

static void	init_vars(t_data *data)
{
	char	*pwd;
	char	*underscore;
	char	*path;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = ft_strdup("no_path_found");
	if (pos_in_arr(data->env, "PWD", '=') == -1)
		set_env_vars(data, "PWD=", pwd);
	if (pos_in_arr(data->env, "OLDPWD", '=') == -1)
		set_env_vars(data, "OLDPWD=", pwd);
	init_shlvl(data);
	free(pwd);
	path = find_in_arr(data->env, "PATH=");
	if (!path)
		set_env_vars(data, "PATH=",
			"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
	underscore = find_in_arr(data->env, "_=");
	if (!underscore)
		set_env_vars(data, "_=", data->argv[0]);
}

void	init_data(t_data *data)
{
	if (ft_arrlen(data->argv) == 1)
		ft_dprintf(1, "\033[1;90mMINI.SHELL  |  ale-cont \\ amontalb\033[0;39m\n");
	g_error = 0;
	get_pid(data);
	data->cmds = NULL;
	data->dico = NULL;
	data->quit = 0;
	data->n_cmd = 0;
	data->env = ft_arrdup(data->env);
	init_vars(data);
	init_dico(data);
}
