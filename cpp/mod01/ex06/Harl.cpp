/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:03:22 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/02 16:28:50 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){}

Harl::~Harl(void){}

void	Harl::debug( void ) {
	std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "WARNING : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "ERROR : This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	pos;

	std::string	tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (level == tab[i]) {
			pos = i;
			break ;
		}
		else
			pos = -1;
	}

	switch (pos)
	{
	case 0:
		debug();
		complain("INFO");
		break;
	case 1:
		info();
		complain("WARNING");
		break;
	case 2:
		warning();
		complain("ERROR");
		break;
	case 3:
		error();
		break;
	default:
		break;
	}
}