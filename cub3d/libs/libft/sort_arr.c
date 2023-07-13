/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:04:28 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/18 13:03:03 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**sort_arr(char **arr)
{
	char	**res;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	if (!arr)
		return (NULL);
	res = ft_arrdup(arr);
	if (!res)
		return (NULL);
	while (arr[++i])
	{
		j = i;
		while (arr[++j])
		{
			if (ft_strncmp(res[i], res[j], INT_MAX) > 0)
			{
				tmp = res[i];
				res[i] = res[j];
				res[j] = tmp;
			}
		}
	}
	return (res);
}
