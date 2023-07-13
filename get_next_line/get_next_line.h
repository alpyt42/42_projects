/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:20:10 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/20 11:20:10 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FD_MAX 10240

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif