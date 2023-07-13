/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:56:55 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/30 17:26:20 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"



int	main(int ac, char **av, char **en)
{
	char	*test;
	char	**path;
	int	pos;

	(void)ac;
	(void)av;
	dprintf(1, "function %d", access(av[1], F_OK));
	// pos = 0;
	// path = cmd_path(en);
	// while (path[pos])
	// 	ft_dprintf(1, "%s\n", path[pos++]);
	// int fd_in = open("here_doc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	// while (1)
	// {
	// 	ft_dprintf(1, "> ");
	// 	char *line = get_next_line(0);
	// 	ft_dprintf(1, "line : %s", line);
	// 	ft_dprintf(fd_in, "line : %s", line);
	// }
}