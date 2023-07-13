/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_in_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:05:40 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/18 13:02:56 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_replace_in_arr(char **matrix, char **insert, int n, int i)
{
	char	**temp;
	int		j;
	int		k;

	j = -1;
	k = -1;
	if (!matrix || n < 0 || n >= ft_arrlen(matrix))
		return (NULL);
	temp = ft_calloc((ft_arrlen(matrix) + ft_arrlen(insert)), sizeof(char *));
	if (!temp)
		return (NULL);
	while (temp && matrix[++i])
	{
		if (i != n)
			temp[++j] = ft_strdup(matrix[i]);
		else
		{
			while (insert && insert[++k])
				temp[++j] = ft_strdup(insert[k]);
		}
	}
	ft_free_arr(matrix);
	matrix = temp;
	return (matrix);
}
