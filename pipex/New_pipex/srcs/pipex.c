/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:06:29 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/30 17:46:59 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_struct(t_data *p)
{
	int	i;
	int	j;

	i = -1;
	free(p->p_id);
	while (++i < p->n_cmds)
	{
		j = 0;
		free(p->fds[i]);
		while (p->cmds[i][j])
			free(p->cmds[i][j++]);
		free(p->cmds[i]);
	}
	free(p->fds);
	free(p->cmds);
}

static void	allocate_pid_fds_cmds(t_data *p)
{
	int	i;

	p->p_id = ft_calloc(p->n_cmds, sizeof(pid_t));
	p->fds = ft_calloc(p->n_cmds, sizeof(int *));
	p->cmds = ft_calloc(p->n_cmds, sizeof(char **));
	if (!p->fds || !p->p_id || !p->cmds)
	{
		ft_dprintf(2, "Allocation Issue :\np->fds:%s\n\
			p->p_id:%s\np->cmds:%s\n", p->fds, p->p_id, p->cmds);
		exit(2);
	}
	i = 0;
	while (i < p->n_cmds)
	{
		p->cmds[i] = ft_split(p->av[i + 2 + p->h_doc], ' ');
		p->fds[i] = ft_calloc(2, sizeof(int));
		if (!p->fds[i] || !p->cmds[i])
		{
			ft_dprintf(2, "Allocation Issue: fds[%d]\n", i);
			exit(2);
		}
		i++;
	}
	i = -1;
	// while (p->cmds[++i])
	// 	dprintf(1, "cmds [%d] : %s\n", i, p->cmds[i][0]);
}

static int	check_files(t_data *pipex)
{
	if (!ft_strncmp("here_doc", pipex->av[1], 9))
	{
		get_here_doc(pipex);
		pipex->out = open(pipex->av[pipex->ac - 1],\
		O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (pipex->out == -1)
			return (perror("open"), 0);
		pipex->h_doc = 1;
	}
	else
	{
		pipex->in = open(pipex->av[1], O_RDONLY);
		if (pipex->in == -1)
			return (perror("open"), 0);
		pipex->out = open(pipex->av[pipex->ac - 1],\
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->out == -1)
			return (perror("open"), 0);
	}
	pipex->n_cmds = pipex->ac - 3 - pipex->h_doc;
	return (1);
}

int	main(int ac, char **av, char **en)
{
	t_data	pipex;
	// int		i = 0;

	pipex.en = en;
	pipex.ac = ac;
	pipex.av = av;
	pipex.h_doc = 0;
	if (ac >= 5)
	{
		if (!check_files(&pipex))
			return (1);
		allocate_pid_fds_cmds(&pipex);
		get_path(&pipex);
		pipex_exec(&pipex);
		wait_for_process_ids(&pipex);
		free_struct(&pipex);
	}
	else
		ft_dprintf(2, "error: invalid number of arguments");
	return (0);
}