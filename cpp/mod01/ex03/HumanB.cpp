/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:36:33 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/27 17:46:40 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& newName) : _name(newName) {
	_weapon = NULL;
}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon& newWeapon){
	_weapon = &newWeapon;
}

void	HumanB::attack(void) const{
	if (_weapon == NULL)
		std::cout << _name <<  " doesn't have weapon " << std::endl;
	else
		std::cout << _name <<  " attacks with their " << _weapon->getType() << std::endl;
}