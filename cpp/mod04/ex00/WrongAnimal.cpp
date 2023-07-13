/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:03:28 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/08 17:02:38 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"){
	std::cout << "WrongAnimal : Constructor called" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & other )
{
	std::cout << "WrongAnimal Assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}


WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal : Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type){
	std::cout << "WrongAnimal : Copy Constructor called" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return _type;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "WrongAnimal " << _type << " sound : WrongAnimal sound!" << std::endl;
}
