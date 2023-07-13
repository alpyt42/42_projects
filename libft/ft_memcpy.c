/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:05:08 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/11 13:20:59 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*dst1;
	const char		*src1;

	dst1 = (char *)dst;
	src1 = (const char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < len)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}
