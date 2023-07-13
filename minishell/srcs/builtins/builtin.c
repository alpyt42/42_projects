/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:40:09 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/28 11:28:56 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

int	built_exit(t_data *data, t_node *node)
{
	long		nb_ex;

	nb_ex = 0;
	data->quit = 1;
	ft_putstr_fd("exit\n", 2);
	if (!node->all_cmd[1])
		return (0);
	nb_ex = ft_atoi_long(node->all_cmd[1]);
	if (nb_ex == -1)
	{
		ft_dprintf(2, "minishell: exit: %s", node->all_cmd[1]);
		ft_dprintf(2, ": numeric argument required\n");
		return (2);
	}
	else if (node->all_cmd[2])
	{
		data->quit = 0;
		ft_dprintf(2, "minishell: exit: too many arguments\n");
		return (1);
	}
	nb_ex = (nb_ex + 256) % 256;
	return (nb_ex);
}

int	built_pwd(void)
{
	char	*b_pwd;

	b_pwd = getcwd(NULL, 0);
	if (!b_pwd)
	{
		ft_dprintf(2, "minishell : %s", strerror(errno));
		return (errno);
	}
	ft_dprintf(2, "%s\n", b_pwd);
	free(b_pwd);
	return (0);
}

int	built_echo(t_node *n)
{
	char	**str;
	int		i;
	int		new_line;

	new_line = 1;
	i = 1;
	str = n->all_cmd;
	if (!str)
		return (0);
	while (str && str[i] && !ft_strncmp(str[i], "-n", 2)
		&& ft_strlen(str[i]) == ft_strlen("-n"))
	{
		new_line = 0;
		i++;
	}
	while (str && str[i])
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (new_line)
		ft_putchar_fd('\n', 1);
	return (0);
}

static int	open_cd(char **str[2])
{
	DIR	*dir;

	dir = NULL;
	if (!str[0][1] && str[1][0] && !str[1][0][0])
	{
		g_error = 1;
		ft_dprintf(2, "minishell : HOME not set\n");
	}
	if (str[1][0] && !str[0][1])
		if (chdir(str[1][0]) == -1)
			g_error = 1;
	if (str[0][1])
		dir = opendir(str[0][1]);
	if (str[0][1] && dir && access(str[0][1], F_OK) != -1)
		chdir(str[0][1]);
	else if (str[0][1] && access(str[0][1], F_OK) == -1)
		print_error(NDIR, "cd", str[0][1], 1);
	else if (str[0][1])
		print_error(NOT_DIR, "cd", str[0][1], 1);
	if (str[0][1] && dir)
		closedir(dir);
	return (g_error);
}

int	built_cd(t_data *data, t_node *n)
{
	char	**str[2];
	char	*val;

	str[0] = n->all_cmd;
	if (!n->all_cmd)
		return (0);
	val = ft_strjoin(search_dico("HOME", data), "");
	str[1] = ft_append_tab(NULL, val);
	free(val);
	val = getcwd(NULL, 0);
	if (!val)
		val = ft_strdup("");
	str[1] = ft_append_tab(str[1], val);
	free(val);
	g_error = open_cd(str);
	if (!g_error && data->n_cmd == 1)
		set_env_vars(data, "OLDPWD=", str[1][1]);
	val = getcwd(NULL, 0);
	if (!val)
		val = ft_strdup("");
	set_env_vars(data, "PWD=", val);
	ft_free_arr(str[1]);
	return (free(val), g_error);
}
