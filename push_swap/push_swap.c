/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:17:37 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/15 12:52:41 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*idx(char *argv[], int size)
{
	int	j;
	int	k;
	int	pos;
	int	*tab;
	int	*res;

	res = (int *)ft_calloc(sizeof(int), size);
	tab = (int *)ft_calloc(sizeof(int), size);
	if (!res || !tab)
		return (NULL);
	j = -1;
	while (++j < size)
		tab[j] = ft_atoi(argv[j]);
	j = -1;
	while (++j < size)
	{
		pos = 0;
		k = -1;
		while (++k < size)
			if (tab[j] > tab[k])
				pos++;
		res[j] = pos;
	}
	return (free(tab), res);
}

t_list	*ft_init(int *tab, int size)
{
	t_list	*new;
	t_list	*list;
	int		i;

	i = 0;
	list = (void *)0;
	while (i < size)
	{
		new = ft_lstnew(tab[i++]);
		ft_lstadd_back(&list, new);
	}
	return (list);
}
