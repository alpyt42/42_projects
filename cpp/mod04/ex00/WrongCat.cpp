/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:05:05 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/08 17:03:00 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat : Constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(){
	std::cout << "WrongCat : Copy Constructor called!" << std::endl;
	*this = other;
}

WrongCat &	WrongCat::operator=( WrongCat const & other )
{
	std::cout << "WrongCat Assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Meow" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat : Destructor called" << std::endl;
}
