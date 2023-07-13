/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:47:16 by amontalb          #+#    #+#             */
/*   Updated: 2023/03/22 13:27:35 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_word(char *cmd, char *s)
{
	int	tab[4];

	tab[3] = 0;
	tab[0] = 0;
	while (cmd[tab[3]])
	{
		if (!ft_strchr(s, cmd[tab[3]]))
		{
			tab[1] = 0;
			tab[2] = 0;
			tab[0]++;
			while (cmd[tab[3]] && (!ft_strchr(s, cmd[tab[3]])
					|| tab[2] || tab[1]))
			{
				tab[1] = (tab[1] + (!tab[2] && cmd[tab[3]] == '\'')) % 2;
				tab[2] = (tab[2] + (!tab[1] && cmd[tab[3]] == '\"')) % 2;
				tab[3]++;
			}
			if ((tab[1] == 1) || (tab[2] == 1))
				return (-1);
		}
		else
			tab[3]++;
	}
	return (tab[0]);
}

static char	**fill_array(char **cmdlex, char *cmd, char *s)
{
	int	tab[5];

	tab[2] = 0;
	tab[4] = -1;
	tab[0] = 0;
	tab[1] = 0;
	while (cmd[tab[2]])
	{
		while (cmd[tab[2]] && ft_strchr(s, cmd[tab[2]]))
			tab[2]++;
		tab[3] = tab[2];
		while (cmd[tab[2]] && (!ft_strchr(s, cmd[tab[2]]) || tab[1] || tab[0]))
		{
			tab[0] = (tab[0] + (!tab[1] && cmd[tab[2]] == '\'')) % 2;
			tab[1] = (tab[1] + (!tab[0] && cmd[tab[2]] == '\"')) % 2;
			tab[2]++;
		}
		if (++tab[4] == count_word(cmd, " \t"))
			cmdlex[tab[4]] = NULL;
		else
			cmdlex[tab[4]] = ft_substr(cmd, tab[3], tab[2] - tab[3]);
	}
	return (cmdlex);
}

char	**cmdlexing(char *cmd)
{
	char	**cmdlex;
	int		nbr_words;

	nbr_words = count_word(cmd, " \t");
	if (nbr_words == -1)
		return (NULL);
	cmdlex = ft_calloc(sizeof(char *), (nbr_words + 1));
	if (!cmdlex)
		return (NULL);
	cmdlex = fill_array(cmdlex, cmd, " ");
	return (cmdlex);
}
