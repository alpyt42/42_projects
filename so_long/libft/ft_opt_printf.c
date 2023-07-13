/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:37:22 by ale-cont          #+#    #+#             */
/*   Updated: 2023/01/20 15:54:15 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr_int(long int nbr, char *base)
{
	int	lbase;
	int	i;

	lbase = 0;
	i = 0;
	if (!base)
		return (0);
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr *= -1;
	}
	while (base[lbase])
		lbase++;
	if (nbr >= 0 && nbr < lbase)
		i += ft_putchar(base[nbr]);
	else
	{
		i += ft_putnbr_int(nbr / lbase, base);
		i += ft_putchar(base[nbr % lbase]);
	}
	return (i);
}

int	ft_putnbr_uns(unsigned long nbr, char *base)
{
	unsigned int	lbase;
	unsigned int	i;

	lbase = 0;
	i = 0;
	if (!base)
		return (0);
	while (base[lbase])
		lbase++;
	if (nbr < lbase)
		i += ft_putchar(base[nbr]);
	else
	{
		i += ft_putnbr_uns(nbr / lbase, base);
		i += ft_putchar(base[nbr % lbase]);
	}
	return (i);
}
