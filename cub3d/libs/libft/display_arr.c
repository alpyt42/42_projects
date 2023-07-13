/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:03:21 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/18 13:03:21 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	display_arr(char **arr, char *info)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		ft_dprintf(1, "%s%s\n", info, arr[i]);
}
