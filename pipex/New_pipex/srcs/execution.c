/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:01:50 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/30 17:42:15 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_fds(t_data *p, int i)
{
	int	j;

	j = 0;
	while (j < p->n_cmds - 1)
	{
		if (j != i - 1)
			close(p->fds[j][0]);
		if (j != i)
			close(p->fds[j][1]);
		j++;
	}
}

void	close_all_fds(t_data *p, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		close(p->fds[j][0]);
		close(p->fds[j][1]);
		j++;
	}
}


static void	dup_fds(t_data *p, int i)
{
	if (i == 0)
	{
		if (dup2(p->in, STDIN_FILENO) == -1)
			exit(3);
		close(p->in);
	}
	else
	{
		if (dup2(p->fds[i - 1][0], STDIN_FILENO) == -1)
			exit(3);
		close(p->fds[i - 1][0]);
	}
	if (i == p->n_cmds - 1)
	{
		if (dup2(p->out, STDOUT_FILENO) == -1)
			exit(3);
		close(p->out);
	}
	else
	{
		if (dup2(p->fds[i][1], STDOUT_FILENO) == -1)
			exit(3);
		close(p->fds[i][1]);
	}
}

void	wait_for_process_ids(t_data *p)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < p->n_cmds)
	{
		waitpid(p->p_id[i], &status, 0);
		if (WEXITSTATUS(status) && i == p->n_cmds - 1)
			exit(127);
		i++;
	}
}

void	pipex_exec(t_data *p)
{
	int		i;
	char	*cmd;

	i = 0;
	while (i < p->n_cmds)
	{
		if (pipe(p->fds[i]) == -1)
			exit(ft_dprintf(2, "Pipe Issue\n"));
		p->p_id[i] = fork();
		if (p->p_id[i] == 0)
		{
			close_fds(p, i);
			dup_fds(p, i);
			cmd = get_cmd_path(p->cmds[i][0], p->en_cmd);
			// dprintf(1,"cmd : %s\n", cmd);
			execve(cmd, p->cmds[i], p->en);
			exit(1);
		}
		i++;
	}
	close_all_fds(p, i);
}
