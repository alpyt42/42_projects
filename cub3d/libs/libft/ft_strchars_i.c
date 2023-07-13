/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchars_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:54:07 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/18 13:01:58 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchars_i(const char *s, char *set)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (-1);
	while (s[i])
	{
		if (ft_strchr(set, s[i]))
			return (i);
		i++;
	}
	return (-1);
}
