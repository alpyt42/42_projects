/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:07:57 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/09 14:20:50 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*toadd;
	t_list	*before;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	before = *lst;
	if (before->next != NULL && before->next->next != NULL)
		while (before->next->next != NULL)
			before = before->next;
	toadd = ft_lstlast(*lst);
	toadd->next = new;
	toadd->bef = before;
}
