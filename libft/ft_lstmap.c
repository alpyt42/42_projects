/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:28:53 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/21 13:00:43 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*lstnew;

	lstnew = (void *)0;
	if (!lst)
		return (lstnew);
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&lstnew, del);
			return ((void *)0);
		}
		ft_lstadd_back(&lstnew, new);
		lst = lst->next;
	}
	return (lstnew);
}
