/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:12:18 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/15 12:08:15 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_list(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
