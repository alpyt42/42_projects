/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:37:22 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/25 16:20:57 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", fd);
		return (6);
	}
	while (str[i])
		ft_putchar(str[i++], fd);
	return (i);
}

int	ft_putnbr_int(long int nbr, char *base, int fd)
{
	int	lbase;
	int	i;

	lbase = 0;
	i = 0;
	if (!base)
		return (0);
	if (nbr < 0)
	{
		i += ft_putchar('-', fd);
		nbr *= -1;
	}
	while (base[lbase])
		lbase++;
	if (nbr >= 0 && nbr < lbase)
		i += ft_putchar(base[nbr], fd);
	else
	{
		i += ft_putnbr_int(nbr / lbase, base, fd);
		i += ft_putchar(base[nbr % lbase], fd);
	}
	return (i);
}

int	ft_putnbr_uns(unsigned long nbr, char *base, int fd)
{
	unsigned int	lbase;
	unsigned int	i;

	lbase = 0;
	i = 0;
	if (!base)
		return (0);
	if (nbr < 0)
	{
		i ++;
		nbr *= -1;
	}
	while (base[lbase])
		lbase++;
	if (nbr >= 0 && nbr < lbase)
		i += ft_putchar(base[nbr], fd);
	else
	{
		i += ft_putnbr_uns(nbr / lbase, base, fd);
		i += ft_putchar(base[nbr % lbase], fd);
	}
	return (i);
}
