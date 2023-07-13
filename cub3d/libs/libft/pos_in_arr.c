/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_in_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:01:49 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/18 13:02:47 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pos_in_arr(char **arr, char *to_find, char set)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(to_find);
	while (arr[++i])
	{
		if (!ft_strncmp(arr[i], to_find, len)
			&& arr[i][len] && arr[i][len] == set)
			return (i);
	}
	return (-1);
}
