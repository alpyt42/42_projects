/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:39:44 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/30 19:38:11 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

void	*print_error(int type, char *cmd, char *arg, int error)
{
	g_error = error;
	if (type == QUOTE)
		ft_dprintf(2, "mini: error while looking for matching quote\n");
	else if (type == NDIR)
		ft_dprintf(2, "mini: %s: %s: No such file or directory\n", cmd, arg);
	else if (type == NPERM)
		ft_dprintf(2, "mini: %s: %s: permission denied\n", cmd, arg);
	else if (type == NCMD)
		ft_dprintf(2, "mini: %s: command not found\n", cmd);
	else if (type == DUPERR)
		ft_dprintf(2, "mini: dup2 failed\n");
	else if (type == FORKERR)
		ft_dprintf(2, "mini: fork failed\n");
	else if (type == PIPERR)
		ft_dprintf(2, "mini: error creating pipe\n");
	else if (type == SYMB)
		ft_dprintf(2, "mini: syntax error near unexpected token `%s'\n", arg);
	else if (type == MEM)
		ft_dprintf(2, "mini: no memory left on device\n");
	else if (type == IS_DIR)
		ft_dprintf(2, "mini: %s: %s: Is a directory\n", cmd, arg);
	else if (type == NOT_DIR)
		ft_dprintf(2, "mini: %s: %s: Not a directory\n", cmd, arg);
	return (NULL);
}

int	symbol_errors(char *error, int type, int *exit)
{
	g_error = type;
	*exit = 0;
	if (error && error[0] && error[1] && error[0] == '>' && error[1] == '>')
		ft_dprintf(2, "mini: syntax error near unexpected token `%s'\n", ">>");
	else if (error && error[0]
		&& error[1] && error[0] == '<' && error[1] == '<')
		ft_dprintf(2, "mini: syntax error near unexpected token `%s'\n", ">>");
	else if (error && error[0]
		&& error[1] && error[0] == '|' && error[1] == '|')
		ft_dprintf(2, "mini: syntax error near unexpected token `%s'\n", "||");
	else if (error && error[0] && error[1]
		&& error[0] == '<' && error[1] == '<')
		ft_dprintf(2, "mini: syntax error near unexpected token `%s'\n", ">>");
	else if (ft_strchr(error, '<'))
		ft_dprintf(2, "mini: syntax error near unexpected token `%s'\n", "<");
	else if (ft_strchr(error, '|'))
		ft_dprintf(2, "mini: syntax error near unexpected token `%s'\n", "|");
	else if (ft_strchr(error, '>'))
		ft_dprintf(2, "mini: syntax error near unexpected token `%s'\n", ">");
	else
		ft_dprintf(2, "mini: syntax error near unexpected token `newline'\n");
	return (-1);
}

void	ft_free_node(void *content)
{
	t_node	*n;

	n = content;
	if (!n)
		return ;
	if (n->all_cmd)
		ft_free_arr(n->all_cmd);
	if (n->all_path)
		free(n->all_path);
	if (n->infile != STDIN_FILENO)
		close(n->infile);
	if (n->outfile != STDOUT_FILENO)
		close(n->outfile);
	free(n);
}

void	ft_free_dico(void *content)
{
	char	**dico;

	dico = content;
	ft_free_arr(dico);
}

void	*ft_free_mini(t_data *data)
{
	if (!data)
		return (NULL);
	if (data->cmds)
		ft_lstclear(&data->cmds, ft_free_node);
	if (data->dico)
		ft_lstclear(&data->dico, ft_free_dico);
	ft_free_arr(data->env);
	data->exe = 0;
	data->quit = 1;
	return (NULL);
}
