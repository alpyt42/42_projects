/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:52:21 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/05 13:42:29 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*count;

	i = 0;
	if (!lst)
		return (0);
	count = lst;
	while (count != NULL)
	{
		count = count->next;
		i++;
	}
	return (i);
}
