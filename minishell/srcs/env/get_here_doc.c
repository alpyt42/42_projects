/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_here_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:08:00 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/29 10:31:15 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_error;

static char	*sub_vars(char *del, t_data *data, int *i)
{
	char	*str;
	char	*var;
	char	*before;
	char	*user;
	int		searchd;

	before = ft_substr(del, 0, *i);
	searchd = ft_strchars_i(&del[*i + 1], "|/`!*@=><+-;#&$?~%^{}: \"\'\n\0");
	user = ft_substr(del, *i + 1, searchd);
	var = search_dico(user, data);
	free(user);
	if (var)
		str = ft_strjoin(before, var);
	else
		str = ft_strdup(before);
	if (searchd != -1)
		del = ft_strjoin(str, &del[*i + 1 + searchd]);
	else
		del = ft_strdup(str);
	if (var)
		(*i)++;
	free (before);
	free (str);
	return (del);
}

static char	*get_var_hd(char *str, t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str && str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			tmp = str;
			str = sub_vars(str, data, &i);
			free(tmp);
		}
		else
			i++;
	}
	return (str);
}

static char	*fill_here_doc(char *del, char *warn)
{
	char	*line;
	char	*readstr;
	char	*tmp;

	line = NULL;
	readstr = NULL;
	while (g_error != 130)
	{
		readstr = readline("> ");
		if (!readstr)
			return (ft_dprintf(2, "%s : %s\n", warn, del), line);
		if (!ft_strncmp(del, readstr, ft_strlen(readstr))
			&& ft_strlen(readstr) == ft_strlen(del))
		{
				free(readstr);
				break ;
		}
		tmp = line;
		line = ft_strjoin(line, readstr);
		free(tmp);
		tmp = line;
		line = ft_strjoin(line, "\n");
		free(tmp);
		free(readstr);
	}
	return (line);
}

static void	check_quotes(char **del, int *q)
{
	int	i;

	i = -1;
	*q = 0;
	if (!(*del))
		return ;
	while (*del && *del[i])
		if (*del[i] == '\"' || *del[i] == '\'')
			*q = 1;
	*del = ft_strim_quotes(*del);
}

int	get_here_doc(char *del, t_data *data, char *warn)
{
	int		fd[2];
	char	*str;
	int		q;

	g_error = 0;
	q = 0;
	if (!del || ft_strchr(del, '<') || ft_strchr(del, '|'))
		return (symbol_errors(del, 2, &data->exe));
	check_quotes(&del, &q);
	if (pipe(fd) == -1)
		return (print_error(PIPERR, NULL, NULL, errno), -1);
	str = fill_here_doc(del, warn);
	if (!q && str)
		str = get_var_hd(str, data);
	if (str)
		write(fd[1], str, ft_strlen(str));
	close(fd[1]);
	free(str);
	if (g_error == 130)
	{
		close(fd[0]);
		return (free(del), -1);
	}
	return (free(del), fd[0]);
}
