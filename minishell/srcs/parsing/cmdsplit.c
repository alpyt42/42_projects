/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:52:13 by amontalb          #+#    #+#             */
/*   Updated: 2023/03/20 17:49:15 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_word(char *cmd, char *s)
{
	int	words;
	int	simple_q;
	int	double_q;
	int	i;

	i = 0;
	words = 0;
	while (cmd[i])
	{
		words++;
		if (!ft_strchr(s, cmd[i]))
		{
			simple_q = 0;
			double_q = 0;
			while (cmd[i] && (!ft_strchr(s, cmd[i]) || double_q || simple_q))
			{
				simple_q = (simple_q + (!double_q && cmd[i] == '\'')) % 2 ;
				double_q = (double_q + (!simple_q && cmd[i] == '\"')) % 2 ;
				i++;
			}
		}
		else
			i++;
	}
	return (words);
}

static char	**fill_array(char **cmdlex, char *cmd, char *s)
{
	int	tab[5];

	tab[2] = 0;
	tab[3] = 0;
	tab[0] = 0;
	tab[1] = 0;
	while (cmd[tab[2]])
	{
		tab[4] = tab[2];
		if (!ft_strchr(s, cmd[tab[2]]))
		{
			while (cmd[tab[2]] && (!ft_strchr(s, cmd[tab[2]])
					|| tab[1] || tab[0]))
			{
				tab[0] = (tab[0] + (!tab[1] && cmd[tab[2]] == '\'')) % 2 ;
				tab[1] = (tab[1] + (!tab[0] && cmd[tab[2]] == '\"')) % 2 ;
				tab[2]++;
			}
		}
		else
			tab[2]++;
		cmdlex[tab[3]] = ft_substr(cmd, tab[4], tab[2] - tab[4]);
		tab[3]++;
	}
	return (cmdlex);
}

char	**ft_cmdsplit(char *cmd, char *s)
{
	char	**cmdsplit;
	int		nbrwords;

	nbrwords = count_word(cmd, s);
	if (nbrwords == -1)
		return (NULL);
	cmdsplit = ft_calloc((nbrwords + 1), sizeof(char *));
	if (!cmdsplit)
		return (NULL);
	cmdsplit = fill_array(cmdsplit, cmd, s);
	cmdsplit[nbrwords] = NULL;
	return (cmdsplit);
}
