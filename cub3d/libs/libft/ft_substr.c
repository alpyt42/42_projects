/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:13:58 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/16 14:54:39 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;
	size_t	startbis;

	startbis = start;
	if (startbis >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - startbis))
	{
		len = ft_strlen(s) - startbis;
	}
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	tmp = str;
	s += startbis;
	while (*s != '\0' && len--)
		*str++ = *s++;
	*str = '\0';
	return (tmp);
}
