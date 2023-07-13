/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:39:33 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/10 13:50:19 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_bis;
	unsigned char	*s2_bis;

	s1_bis = (unsigned char *)s1;
	s2_bis = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_bis != *s2_bis)
			return (*s1_bis - *s2_bis);
		s1_bis++;
		s2_bis++;
	}
	return (0);
}
