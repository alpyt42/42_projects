/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:36:35 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/27 17:19:48 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {
}

Weapon::~Weapon(void){
}

const std::string&	Weapon::getType() { return _type; }

void				Weapon::setType(const std::string& newType){
	_type = newType;
}
