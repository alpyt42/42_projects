/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:29:13 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/15 12:29:39 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_nbr(t_list *list)
{
	int		nbr;
	t_list	*elem;

	nbr = INT_MIN;
	elem = list;
	while (elem != NULL)
	{
		if (elem->nbr > nbr)
			nbr = elem->nbr;
		elem = elem->next;
	}
	return (nbr);
}

static int	min_nbr(t_list *list)
{
	int		nbr;
	t_list	*elem;

	nbr = INT_MAX;
	elem = list;
	while (elem != NULL)
	{
		if (elem->nbr < nbr)
			nbr = elem->nbr;
		elem = elem->next;
	}
	return (nbr);
}

void	algo_three_nbrs(t_list *list, char c)
{
	int	third;

	third = ft_lstlast(list)->nbr;
	if (list->next->nbr == third)
	{
		if (list->nbr > list->next->nbr)
			swap(list, c);
	}
	else if (list->nbr > list->next->nbr && list->nbr < third)
		swap(list, c);
	else if (list->nbr > list->next->nbr && list->next->nbr > third)
	{
		swap(list, c);
		rev_rotate(list, c);
	}
	else if (list->nbr > list->next->nbr && list->next->nbr < third)
		rotate(list, c);
	else if (list->nbr < list->next->nbr && list->nbr > third)
		rev_rotate(list, c);
	else if (list->nbr < list->next->nbr && list->next->nbr > third)
	{
		swap(list, c);
		rotate(list, c);
	}
}

static void	fill_a(t_list **lista, t_list **listb)
{
	while ((*listb) != NULL)
	{
		if ((*listb) != NULL && (*listb)->nbr < min_nbr((*lista))
			&& (*lista)->nbr == min_nbr((*lista)))
			push(&(*listb), &(*lista), 'a');
		if ((*listb) != NULL && (*listb)->nbr > max_nbr((*lista))
			&& ft_lstlast((*lista))->nbr == max_nbr((*lista)))
		{
			push(&(*listb), &(*lista), 'a');
			rotate((*lista), 'a');
		}
		if ((*listb) == NULL)
			return ;
		if ((*listb)->nbr > min_nbr((*lista))
			&& (*listb)->nbr < max_nbr((*lista)))
		{
			while ((*listb)->nbr > (*lista)->nbr)
				rotate((*lista), 'a');
			push(&(*listb), &(*lista), 'a');
		}
		else if (ft_lstlast(*lista)->nbr != max_nbr((*lista)))
			rotate((*lista), 'a');
	}
}

void	algo_six_nbrs(t_list *lista, t_list *listb, int size)
{
	int	i;

	i = -1;
	while (++i < size - 3)
		push(&lista, &listb, 'b');
	algo_three_nbrs(lista, 'a');
	if (size >= 5)
		algo_three_nbrs(listb, 'b');
	fill_a(&lista, &listb);
	while (istri(lista) == 0)
		rotate(lista, 'a');
}
