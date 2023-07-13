/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:51:14 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/09 14:05:26 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int nbr)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->nbr = nbr;
	elem->next = NULL;
	elem->bef = NULL;
	return (elem);
}
