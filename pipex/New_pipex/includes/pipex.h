/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:06:51 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/30 14:19:50 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int		ac;
	char	**av;
	pid_t	*p_id;
	char	***cmds;
	char	**en;
	char	**en_cmd;
	int		n_cmds;
	int		**fds;
	int		in;
	int		out;
	int		h_doc;
}	t_data;

void	get_here_doc(t_data *pipex);
void	get_path(t_data *p);
void	free_struct(t_data *p);
char	*get_cmd_path(char *cmd, char **env);
void	wait_for_process_ids(t_data *p);
void	pipex_exec(t_data *p);
void	wait_for_process_ids(t_data *p);

#endif