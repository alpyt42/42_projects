/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:41:32 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/28 15:19:26 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *left_str, char *buf)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!left_str && !buf)
		return (NULL);
	if (!left_str)
		return (ft_strdup(buf));
	if (!buf)
		return (ft_strdup(left_str));
	str = ft_calloc(sizeof(char), (ft_strlen(left_str) + ft_strlen(buf) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (left_str[++i])
		str[i] = left_str[i];
	while (buf[j])
		str[i++] = buf[j++];
	return (str);
}
