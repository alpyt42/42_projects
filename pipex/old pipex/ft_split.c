/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:43:26 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/21 13:54:48 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_freeall(char **res, size_t args)
{
	size_t	i;

	i = 0;
	while (res[i] && i < args)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static size_t	ft_nbline(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (len);
}

static char	*ft_createline(char const *s, char c)
{
	size_t		len;
	size_t		j;
	char		*line;

	len = 0;
	j = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	line = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!line)
		return (NULL);
	while (j < len)
	{
		line[j] = s[j];
		j++;
	}
	return (line);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char **)ft_calloc(sizeof(char *), (ft_nbline(s, c) + 1));
	if (!str)
		return (NULL);
	while (j < ft_nbline(s, c))
	{
		while (s[i] == c && s[i != '\0'])
			i++;
		if (s[i] != c && s[i != '\0'])
		{
			str[j] = ft_createline(&s[i], c);
			if (!str[j++])
				return ((char **)ft_freeall(str, ft_nbline(s, c)));
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (str);
}
