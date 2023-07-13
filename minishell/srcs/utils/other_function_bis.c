/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:46:54 by ale-cont          #+#    #+#             */
/*   Updated: 2023/03/27 13:43:14 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_chev(char **cmd, t_data *d, int i, int j)
{
	int		count;
	char	ch[2];

	ch[1] = '\0';
	while (cmd[++i])
	{
		count = 1;
		j = i + 1;
		ch[0] = '\0';
		if (cmd && cmd[i] && cmd[j] && (cmd[i][0] == '>' || cmd[i][0] == '<'))
			ch[0] = cmd[i][0];
		while (ch[0] && cmd[j] && cmd[j][0]
			&& (cmd[j][0] == '>' || cmd[j][0] == '<'))
		{
			if (ch[0] != cmd[j][0] && (cmd[j][0] == '>' || cmd[j][0] == '<'))
				return (symbol_errors(cmd[j], 2, &d->exe));
			count++;
			j++;
		}
		if (ch[0] && (count > 2 && cmd[i + 1] && cmd[i + 2]))
			return (symbol_errors(ch, 2, &d->exe));
		else if ((!cmd[j] && cmd[j - 1][0] == ch[0]))
			return (symbol_errors("", 2, &d->exe));
	}
	return (0);
}
