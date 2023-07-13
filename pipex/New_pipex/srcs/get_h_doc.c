/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_h_doc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:44:48 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/30 14:41:35 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	fill_here_doc(t_data *p, int fd)
{
	char	*line;
	
	(void)fd;
	while (1)
	{
		ft_dprintf(1, "> ");
		line = get_next_line(0);
		if (!line)
			exit(1);
		if (!ft_strncmp(p->av[2], line, ft_strlen(line) - 1)\
			&& ft_strlen(line) - 1 == ft_strlen(p->av[2]))
			break ;
		ft_dprintf(fd, "%s", line);
		free(line);
	}
	free(line);
}

void	get_here_doc(t_data *pipex)
{
	int	fd_in;

	fd_in = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_in == -1)
		perror("open");
	fill_here_doc(pipex, fd_in);
	close(fd_in);
	pipex->in = open("here_doc", O_RDONLY);
	if (pipex->in == -1)
	{
		unlink("here_doc");
		perror("open");
	}
}
