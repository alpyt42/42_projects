/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:27:48 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/25 16:25:33 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_opt(char c, va_list *ap, int fd)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(*ap, int), fd);
	if (c == 's')
		i = ft_putstr(va_arg(*ap, char *), fd);
	if (c == 'p')
	{
		i += ft_putstr("0x", fd);
		i += ft_putnbr_uns(va_arg(*ap, unsigned long int), "0123456789abcdef", fd);
	}
	if (c == 'd' || c == 'i')
		i = ft_putnbr_int(va_arg(*ap, int), "0123456789", fd);
	if (c == 'u')
		i = ft_putnbr_uns(va_arg(*ap, unsigned int), "0123456789", fd);
	if (c == 'x')
		i = ft_putnbr_uns(va_arg(*ap, unsigned int), "0123456789abcdef", fd);
	if (c == 'X')
		i = ft_putnbr_uns(va_arg(*ap, unsigned int), "0123456789ABCDEF", fd);
	if (c == '%')
		i = ft_putchar('%', fd);
	return (i);
}

int	opt_list(char c)
{
	char	*optlist;
	int		i;

	optlist = "cspdiuxX%";
	i = 0;
	while (optlist[i])
	{
		if (optlist[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	lentot;
	va_list	ap;

	i = 0;
	lentot = 0;
	va_start(ap, format);
	if (write(1, 0, 0))
		return (-1);
	while (format[i])
	{
		if (format[i] != '%' && format[i])
			lentot += ft_putchar(format[i], 1);
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (opt_list(format[i]) >= 0)
				lentot += display_opt(format[i], &ap, 1);
			else if (format[i])
				lentot += ft_putchar(format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (lentot);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	size_t	i;
	size_t	lentot;
	va_list	ap;

	i = 0;
	lentot = 0;
	va_start(ap, format);
	if (write(1, 0, 0))
		return (-1);
	while (format[i])
	{
		if (format[i] != '%' && format[i])
			lentot += ft_putchar(format[i], fd);
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (opt_list(format[i]) >= 0)
				lentot += display_opt(format[i], &ap, fd);
			else if (format[i])
				lentot += ft_putchar(format[i], fd);
		}
		i++;
	}
	va_end(ap);
	return (lentot);
}