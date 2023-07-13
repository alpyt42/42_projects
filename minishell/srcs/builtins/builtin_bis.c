/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:06:32 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/27 17:40:05 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

int	is_builtin(t_node *n)
{
	int			i;
	const char	*built[9];

	i = -1;
	built[0] = "cd";
	built[1] = "export";
	built[2] = "exit";
	built[3] = "unset";
	built[4] = "echo";
	built[5] = "env";
	built[6] = "pwd";
	built[7] = NULL;
	if (!n->all_cmd || n->all_path)
		return (-1);
	while (built[++i])
		if (ft_strncmp(built[i], *n->all_cmd, ft_strlen(*n->all_cmd)) == 0
			&& ft_strlen(*n->all_cmd) == ft_strlen(built[i]))
			return (i);
	return (-1);
}

int	built_env(t_data *d, int tri)
{
	char	**env;
	char	**tab;

	env = d->env;
	if (!env)
		return (0);
	if (!tri)
	{
		(void)tab;
		display_arr(env, "", 1);
	}
	else if (tri)
	{
		tab = sort_arr(env);
		display_arr(tab, "declare -x ", 0);
		ft_free_arr(tab);
	}
	return (0);
}

static int	error_built(char *cmd, char *fct, char *tab)
{
	if (!tab && (!cmd || !cmd[0]))
		return (0);
	if (tab && tab[0] && tab[0] == '=')
		ft_dprintf(2, "mini: %s: '=': not a valid identifier\n", fct);
	else if (ft_strchars_i(cmd, "()") != -1)
		ft_dprintf(2, "mini: syntax error near unexpected token '%c'\n",
			cmd[ft_strchars_i(cmd, "()")]);
	else if (ft_str_isalnum(cmd))
	{
		if (ft_strchars_i(cmd, "-") != -1 && cmd[0] == '-' && cmd[1])
			ft_dprintf(2, "mini: %s: %c%c: invalid option\n",
				fct, cmd[0], cmd[1]);
		else
			ft_dprintf(2, "mini: %s: '%s': not a valid identifier\n",
				fct, cmd);
	}
	else if (!ft_str_isalnum(cmd) && tab && tab[0] && tab[0] != '=')
		return (1);
	g_error = 1;
	return (g_error);
}

int	built_export(t_data *data, t_node *n, int i, char **tmp)
{
	char	*var_glob;
	int		exe;

	if (!n->all_cmd)
		return (0);
	if (n->all_cmd[0] && !n->all_cmd[1])
		return (built_env(data, 1));
	while (n->all_cmd[++i])
	{
		exe = 1;
		tmp = mini_split(n->all_cmd[i], -1, 0, 0);
		exe = error_built(tmp[0], "export", n->all_cmd[i]);
		if (tmp && tmp[0] && exe && ft_arrlen(tmp) <= 2)
		{
			if (search_dico(tmp[0], data) && !ft_strlen(tmp[1]))
				return (ft_free_arr(tmp), 0);
			var_glob = ft_strjoin(tmp[0], "=");
			set_env_vars(data, var_glob, tmp[1]);
			free(var_glob);
		}
		ft_free_arr(tmp);
	}
	if (g_error)
		return (g_error);
	return (0);
}

int	built_unset(t_data *data, t_node *n)
{
	char	**cmds;
	int		i;
	int		check;
	int		pos;

	cmds = n->all_cmd;
	pos = 0;
	if (!cmds || !cmds[0] || !cmds[1])
		return (0);
	i = 0;
	while (cmds[++i])
	{
		check = 1;
		check = error_built(cmds[i], "unset", NULL);
		if (check)
		{
			pos = pos_in_arr(data->env, cmds[i], '=');
			if (search_dico(cmds[i], data) && pos != -1)
				data->env = ft_replace_in_matrix(data->env, NULL, pos, -1);
		}
	}
	if (g_error)
		return (g_error);
	return (0);
}
