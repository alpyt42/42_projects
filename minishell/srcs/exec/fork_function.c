/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:58:56 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/22 14:26:57 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

int	exec_builtin(t_data *d, t_node *n)
{
	if (is_builtin(n) == -1)
		return (0);
	if (is_builtin(n) == 0)
		g_error = built_cd(d, n);
	else if (is_builtin(n) == 1)
		g_error = built_export(d, n, 0, NULL);
	else if (is_builtin(n) == 2)
		g_error = built_exit(d, n);
	else if (is_builtin(n) == 3)
		g_error = built_unset(d, n);
	else if (is_builtin(n) == 4)
		g_error = built_echo(n);
	else if (is_builtin(n) == 5)
		g_error = built_env(d, 0);
	else if (is_builtin(n) == 6)
		g_error = built_pwd();
	return (g_error);
}

static void	exec_cmd(t_data *d, t_list *cmd)
{
	t_node	*n;

	n = cmd->content;
	if (is_builtin(n) >= 0)
		g_error = exec_builtin(d, n);
	else if (is_builtin(n) < 0 && n->all_cmd && n->all_path)
		if (execve(n->all_path, n->all_cmd, d->env) == -1)
			g_error = errno;
}

void	*redir_dup(t_list *cmd, int fd[2])
{
	t_node	*n;

	n = cmd->content;
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
	else if (cmd->next && dup2(fd[1], STDOUT_FILENO) == -1)
		return (print_error(DUPERR, NULL, NULL, errno));
	close(fd[1]);
	return ("");
}

static void	*get_fork(t_data *d, t_list *cmd, int fd[2])
{
	pid_t	pdt;

	pdt = fork();
	if (pdt == -1)
	{
		close(fd[0]);
		close(fd[1]);
		d->exe = 1;
		return (print_error(FORKERR, NULL, NULL, 1));
	}
	else if (pdt == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (!redir_dup(cmd, fd))
		{
			d->exe = 1;
			return (NULL);
		}
		close(fd[0]);
		exec_cmd(d, cmd);
		ft_lstclear(&cmd, ft_free_node);
		exit(g_error);
	}
	return ("");
}

void	*fork_fct(t_data *d, t_list *cmd, int fd[2])
{
	t_node	*n;
	DIR		*dir;

	dir = NULL;
	n = cmd->content;
	if (!n || !n->all_cmd || n->outfile < 0 || n->infile < 0)
		return (NULL);
	if (n->all_cmd)
		dir = opendir(*n->all_cmd);
	if (is_builtin(n) >= 0
		|| (n->all_path && !access(n->all_path, X_OK)))
	{
		if (!get_fork(d, cmd, fd))
			return (NULL);
	}
	else if (is_builtin(n) < 0
		&& (dir || (n->all_path && !access(n->all_path, F_OK))))
		g_error = 126;
	else if (is_builtin(n) < 0 && n->all_cmd)
		g_error = 127;
	if (dir)
		closedir(dir);
	return ("");
}
