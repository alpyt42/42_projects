/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:03:29 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/28 18:24:24 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || (ac == 2 && std::string(av[1]).length() == 0)) {
		std::cout << "Please provide one complain non NULL" << std::endl;
		return 1;
	}

	Harl harl;
	std::string	level = std::string(av[1]);
	harl.complain(level);
	return 0;
}
