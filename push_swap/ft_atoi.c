/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:18:11 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/20 14:14:50 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	size_t	i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (!str)
		return (2147483649);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (2147483649);
		nb = nb * 10 + str[i++] - 48;
	}
	if (nb == 0 && str[0] != '0' && str[1] == '\0')
		return (2147483649);
	return (sign * nb);
}
