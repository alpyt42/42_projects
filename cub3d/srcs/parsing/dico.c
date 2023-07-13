/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dico.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:55:32 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/11 16:01:48 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*search_dico(char *search, t_data *d)
{
	char	**cmd;
	void	*tmp;

	tmp = d->h_dico;
	while (d->h_dico)
	{
		cmd = d->h_dico->content;
		if (!ft_strncmp(cmd[0], search, ft_strlen(search))
			&& ft_strlen(cmd[0]) == ft_strlen(search))
		{
			d->h_dico = tmp;
			return (cmd[1]);
		}
		d->h_dico = d->h_dico->next;
	}
	d->h_dico = tmp;
	return (NULL);
}

void	*add_dico(t_list **h_dico, char *key, char *val)
{
	char	*add_key;
	char	*add_val;
	t_dico	*node;

	if (!key || !val)
		return (error(PARSING));
	add_key = ft_strdup(key);
	add_val = ft_strdup(val);
	if (!add_key || !add_val)
		return (error(MALLOC_ERR));
	node = init_dico();
	if (!node)
		return (error(MALLOC_ERR));
	node->key = add_key;
	node->val = add_val;
	ft_lstadd_back(h_dico, ft_lstnew(node));
	return ("");
}

t_dico	*init_dico(void)
{
	t_dico	*dico;

	dico = (t_dico *)malloc(sizeof(t_dico));
	if (!dico)
		return (NULL);
	dico->key = NULL;
	dico->val = NULL;
	return (dico);
}
