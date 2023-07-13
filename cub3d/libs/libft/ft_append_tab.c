/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:07:24 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/18 13:03:08 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_append_tab(char **tab, char *line)
{
	char	**res;
	int		len;
	int		i;

	i = -1;
	res = NULL;
	if (!line)
		return (tab);
	len = ft_arrlen(tab);
	res = ft_calloc(sizeof(char *), (len + 2));
	if (!res)
		return (tab);
	while (++i < len)
	{
		res[i] = ft_strdup(tab[i]);
		if (!res[i])
		{
			ft_free_arr(tab);
			ft_free_arr(res);
			return (NULL);
		}
	}
	res[i] = ft_strdup(line);
	ft_free_arr(tab);
	return (res);
}
