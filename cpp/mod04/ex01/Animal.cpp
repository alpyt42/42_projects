/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:45 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/08 17:01:31 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal &	Animal::operator=( Animal const & other )
{
	std::cout << "Animal Assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Animal::Animal() : _type("Generic Animal"){
	std::cout << "Animal : Constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal : Destructor called" << std::endl;
}

Animal::Animal(const Animal& other){
	std::cout << "Animal : Copy Constructor called" << std::endl;
	*this = other;
}

std::string	Animal::getType(void) const {
	return _type;
}

void	Animal::makeSound(void) const{
	std::cout << "Animal " << _type << " sound : Animal sound!" << std::endl;
}
