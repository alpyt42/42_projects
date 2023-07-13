/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:50:49 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/24 15:48:36 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for(int i = 1; av[i]; i++)
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
	std::cout << std::endl;
	return (0);
}
