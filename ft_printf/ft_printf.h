/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:52:48 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/25 16:25:41 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_putchar(char c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_putnbr_int(long int nbr, char *base, int fd);
int	ft_putnbr_uns(unsigned long nbr, char *base, int fd);
int	opt_list(char c);
int	display_opt(char c, va_list *ap, int fd);
#endif