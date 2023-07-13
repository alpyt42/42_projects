/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:32:53 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/21 19:00:23 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

void	get_pid(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		print_error(FORKERR, NULL, NULL, 1);
		exit(1);
	}
	if (!pid)
		exit(1);
	waitpid(pid, NULL, 0);
	data->p_ids = pid - 1;
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	char	*prompt;
	char	*cmd;

	data.env = env;
	data.argv = argv;
	if (argc >= 2 || !argc)
		return (0);
	init_data(&data);
	while (argc && argv)
	{
		data.exe = 1;
		signal(SIGINT, signal_receive);
		signal(SIGQUIT, SIG_IGN);
		prompt = get_prompt(&data);
		if (!prompt)
			prompt = ft_strdup("minishell $ ");
		cmd = readline(prompt);
		free(prompt);
		if (!launch_mini(&data, cmd) || data.quit)
			break ;
		free(cmd);
	}
	free(cmd);
	return (rl_clear_history(), g_error);
}
