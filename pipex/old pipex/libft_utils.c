/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:30:47 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/15 20:46:06 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*memcal;

	if (size > 0 && count > (SIZE_MAX / size))
		return (NULL);
	memcal = malloc (size * count);
	if (!memcal)
		return (NULL);
	ft_bzero(memcal, size * count);
	return (memcal);
}
