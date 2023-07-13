/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:28:49 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/31 12:13:41 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
			{
				j++;
				if (!to_find[j])
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
