/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:39 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/27 14:19:25 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

static void	*redir_npipe(t_data *d, t_node *n)
{
	if (!n || n->infile < 0 || n->outfile < 0)
		return (0);
	d->stdout_fd = dup(STDOUT_FILENO);
	d->stdin_fd = dup(STDIN_FILENO);
	if (d->stdout_fd == -1 || d->stdin_fd == -1)
		return (print_error(DUPERR, NULL, NULL, errno));
	if (n->infile != STDIN_FILENO)
	{
		if (dup2(n->infile, STDIN_FILENO) == -1)
			return (print_error(DUPERR, NULL, NULL, errno));
		close(n->infile);
	}
	if (n->outfile != STDOUT_FILENO)
	{
		if (dup2(n->outfile, STDOUT_FILENO) == -1)
			return (print_error(DUPERR, NULL, NULL, errno));
		close(n->outfile);
	}
	return ("");
}

static void	*mini_no_pipe(t_data *d, t_node *n)
{
	if (!redir_npipe(d, n))
		return (NULL);
	exec_builtin(d, n);
	if (n->infile > 2)
	{
		if (dup2(d->stdin_fd, STDIN_FILENO) == -1)
			return (print_error(DUPERR, NULL, NULL, errno));
		close(n->infile);
	}
	close(d->stdin_fd);
	if (n->outfile > 2)
	{
		if (dup2(d->stdout_fd, STDOUT_FILENO) == -1)
			return (print_error(DUPERR, NULL, NULL, errno));
		close(n->outfile);
	}
	close(d->stdout_fd);
	return ("");
}

void	*mini_process(t_data *data, t_list *cmds)
{
	t_node	*n;

	n = data->cmds->content;
	if (data->n_cmd == 1 && is_builtin(n) >= 0)
	{
		if (!mini_no_pipe(data, n))
			ft_free_mini(data);
		return (NULL);
	}
	while (cmds)
	{
		if (!n->all_cmd)
			return (NULL);
		else
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			exec(data, cmds);
		}
		cmds = cmds->next;
	}
	return (NULL);
}

static void	get_error(t_data *d)
{
	t_node	*n;

	if (!d->cmds)
		return ;
	n = d->cmds->content;
	if (!d->quit && g_error == 13)
		g_error = 0;
	else if (g_error > 255)
		g_error = g_error / 255;
	if (d && !d->cmds->next && !g_error
		&& n->all_cmd && n->all_cmd[0])
		set_env_vars(d, "_=", n->all_cmd[0]);
}

int	launch_mini(t_data *data, char *cmd)
{
	if (!cmd)
	{
		ft_dprintf(2, "exit\n");
		return (ft_free_mini(data), 0);
	}
	if (ft_strlen(cmd) <= 0)
		return (1);
	if (cmd[0] != '\0')
		add_history(cmd);
	if (check_pars(cmd, data) || !data->exe)
		return (1);
	data->n_cmd = ft_lstsize(data->cmds);
	if (data->n_cmd > 0 && data->exe)
		mini_process(data, data->cmds);
	if (data->n_cmd >= 1 && !(data->n_cmd == 1
			&& is_builtin(data->cmds->content) >= 0))
		while (data->n_cmd-- > 0)
			waitpid(-1, &g_error, 0);
	get_error(data);
	ft_lstclear(&data->dico, ft_free_dico);
	ft_lstclear(&data->cmds, ft_free_node);
	init_dico(data);
	if (data->quit)
		ft_free_mini(data);
	return (1);
}
