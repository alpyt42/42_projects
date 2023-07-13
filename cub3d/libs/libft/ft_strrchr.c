/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:45:46 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/10 17:33:22 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (len != 0 && s[len] != (char)c)
		len--;
	if (len == 0 && s[len] != (char)c)
		return (NULL);
	else
		return ((char *)&s[len]);
	return (NULL);
}
