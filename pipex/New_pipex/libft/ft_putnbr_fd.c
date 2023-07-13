/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:56:09 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/15 12:41:29 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nb < 10)
		ft_putchar_fd(nb + 48, fd);
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nb % 10 + 48, fd);
	}
}
