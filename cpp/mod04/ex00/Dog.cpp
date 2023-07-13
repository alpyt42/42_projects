/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:39:29 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/08 17:02:14 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog : Constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(){
	std::cout << "Dog : Copy Constructor called!" << std::endl;
	*this = other;
}

Dog &	Dog::operator=( Dog const & other )
{
	std::cout << "Dog Assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog : Destructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Wouf" << std::endl;
}