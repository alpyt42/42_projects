/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:35:06 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/14 12:15:44 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
