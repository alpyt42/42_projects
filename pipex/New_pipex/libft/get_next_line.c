/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:09:24 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/26 10:25:51 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	pos_return(char *buf)
{
	size_t	pos;

	pos = 0;
	while (buf[pos] != '\n' && buf[pos] != '\0')
		pos++;
	if (buf[pos] == '\n')
		pos++;
	return (pos);
}

static ssize_t	read_buf(int fd, char *buf)
{
	ssize_t	rd_bytes;

	rd_bytes = read(fd, buf, BUFFER_SIZE);
	if (rd_bytes > 0)
		buf[rd_bytes] = 0;
	else
		buf[0] = 0;
	return (rd_bytes);
}

static int	check_error(int *endline, int rd_bytes)
{
	if (rd_bytes == 0)
		return (0);
	else if (rd_bytes < 0)
	{
		*endline = -1;
		return (0);
	}
	return (1);
}

static char	*get_line(char *buf, int fd, int *endline)
{
	ssize_t	rd_bytes;
	size_t	pos_r;
	char	*line;
	char	*tmp;

	if (ft_strlen(buf) == 0)
	{
		rd_bytes = read_buf(fd, buf);
		if (check_error(endline, rd_bytes) == 0)
			return (NULL);
	}
	pos_r = pos_return(buf);
	if (buf[pos_r - 1] == '\n')
		*endline = 1;
	line = malloc(pos_r + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buf, pos_r + 1);
	tmp = ft_strdup((buf) + pos_r);
	if (!tmp)
		return (NULL);
	ft_strlcpy(buf, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			endline;
	char		*old;
	char		*line;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	endline = 0;
	line = get_line(buf, fd, &endline);
	if (!line)
		return (NULL);
	while (endline == 0)
	{
		new_line = get_line(buf, fd, &endline);
		if (!new_line && endline != -1)
			return (line);
		if (endline == -1)
			return (free(line), NULL);
		old = line;
		line = ft_strjoin(line, new_line);
		free(new_line);
		free(old);
	}
	return (line);
}
