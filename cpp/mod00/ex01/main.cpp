/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:12:46 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/25 18:49:43 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	while (1)
	{
		std::cout << "Please enter an action : ADD | SEARCH | EXIT -> ";
		std::getline(std::cin, input);
		if (std::cin.eof() || !input.compare("EXIT"))
			return (0);
		if (!input.compare("ADD"))
			book.get_contactinfo();
		else if (!input.compare("SEARCH"))
			book.searchcontact();
		else if (input.length() != 0)
			std::cout << "Action non valid" << std::endl;
		if (std::cin.eof())
			return (0);
	}
	return (0);
}
