/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:08:13 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/15 10:46:00 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	starttrim(char const *s1, char const *set)
{
	int	i;
	int	len;

	len = ft_strlen(s1);
	i = 0;
	while (check(s1[i], set) == 1 && i < len)
		i++;
	return (i);
}

static int	endtrim(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (check(s1[len - i - 1], set) == 1 && i < len)
		i++;
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(""));
	start = starttrim(s1, set);
	end = endtrim(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
