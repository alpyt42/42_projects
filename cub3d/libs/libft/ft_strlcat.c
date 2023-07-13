/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:14:06 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/11 11:30:12 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= len)
		return (ft_strlen(src) + dstsize);
	while (i < (dstsize - len - 1) && src[i])
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	return (ft_strlen(src) + len);
}
