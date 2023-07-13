/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:29:54 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/20 17:49:09 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_user_name(t_data *data)
{
	char	**user_name;
	char	*tmp;
	char	*tmp2;

	user_name = NULL;
	tmp = NULL;
	tmp2 = NULL;
	exec_cmd_path(&user_name, "/usr/bin/whoami", "whoami", data->env);
	if (!user_name)
		ft_append_tab(user_name, "guest");
	if (user_name && *user_name)
	{
		tmp = ft_strjoin(user_name[0], "@minishell:");
		tmp2 = ft_strjoin(GREEN, tmp);
		free(tmp);
		tmp = ft_strjoin(tmp2, DEFAULT);
		free(tmp2);
		ft_free_arr(user_name);
		return (tmp);
	}
	else
		tmp = ft_strjoin("unknown", "@minishell:");
	return (tmp);
}

static char	*get_path(t_data *data)
{
	char	*pwd;
	char	*home;
	char	*tmp;

	home = search_dico("HOME", data);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = ft_strdup("∅ ");
	if (pwd && home && home[0] && ft_strstr(pwd, home))
	{
		tmp = pwd;
		pwd = ft_strjoin("~", &pwd[ft_strlen(home)]);
		free(tmp);
	}
	home = ft_strjoin(BLUE, pwd);
	free(pwd);
	pwd = ft_strjoin(home, DEFAULT);
	free(home);
	return (pwd);
}

char	*get_prompt(t_data *data)
{
	char	*prompt;
	char	*user_name;
	char	*path;
	char	*tmp;

	user_name = get_user_name(data);
	path = get_path(data);
	tmp = ft_strjoin(user_name, path);
	prompt = ft_strjoin(tmp, "$ ");
	free(tmp);
	free(path);
	free(user_name);
	return (prompt);
}
