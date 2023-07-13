/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:36:34 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/27 17:21:42 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& newName, Weapon& newWeapon) : _name(newName), _weapon(newWeapon) {}

HumanA::~HumanA(void){}

void	HumanA::attack(void) const{
	std::cout << _name <<  " attacks with their " << _weapon.getType() << std::endl;
}