/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:25:57 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/03 18:26:16 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **arr)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof(char *) * (ft_arrlen(arr) + 1));
	if (!str)
		return (NULL);
	while (arr[i])
	{
		str[i] = ft_strdup(arr[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
