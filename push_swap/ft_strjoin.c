/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:38:00 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/15 12:48:23 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char *left_str, char *buf)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (left_str == NULL)
	{
		left_str = (char *)ft_calloc(sizeof(char), 1);
		if (!left_str)
			return (NULL);
	}
	if (!left_str || !buf)
		return (NULL);
	str = ft_calloc(sizeof(char), (ft_strlen(left_str) + ft_strlen(buf) + 2));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(left_str) + ft_strlen(buf)] = ' ';
	return (free(left_str), str);
}
