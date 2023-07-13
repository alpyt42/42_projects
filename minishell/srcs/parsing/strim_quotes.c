/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strim_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:57:31 by amontalb          #+#    #+#             */
/*   Updated: 2023/03/20 17:49:38 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	malloc_len(char *s)
{
	int	size;
	int	i;
	int	simple_q;
	int	double_q;

	i = 0;
	size = 0;
	simple_q = 0;
	double_q = 0;
	while (s[i])
	{
		simple_q = (simple_q + (!double_q && s[i] == '\'')) % 2 ;
		double_q = (double_q + (!simple_q && s[i] == '\"')) % 2 ;
		if (((s[i]) == '\"' && !simple_q) || ((s[i]) == '\"' && !double_q))
			size++;
		i++;
	}
	if (simple_q || double_q)
		return (-1);
	return (size);
}

char	*ft_strim_quotes(char *s)
{
	int		simple_q;
	int		double_q;
	char	*trim;
	int		i;
	int		j;

	i = 0;
	j = -1;
	simple_q = 0;
	double_q = 0;
	if (!s || malloc_len(s) == -1)
		return (NULL);
	trim = ft_calloc((ft_strlen(s) - malloc_len(s) + 1), sizeof(char));
	if (!trim)
		return (NULL);
	while (s[i])
	{
		simple_q = (simple_q + (!double_q && s[i] == '\'')) % 2 ;
		double_q = (double_q + (!simple_q && s[i] == '\"')) % 2 ;
		if ((s[i] != '\"' || simple_q) && (s[i] != '\'' || double_q))
			trim[++j] = s[i];
		i++;
	}
	trim[++j] = '\0';
	return (trim);
}
