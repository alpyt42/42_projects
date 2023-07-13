/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:39:32 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/08 18:01:39 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat : Constructor called" << std::endl;
	_type = "Cat";
	_brain = new (std::nothrow) Brain();
	if (!_brain)
		std::cout << "Cat : Creation of Cat's brain failed" << std::endl;
}

Cat::Cat(const Cat& other): Animal() {
	std::cout << "Cat : Copy Constructor called!" << std::endl;
	*this = other;
	_brain = new (std::nothrow) Brain(*other._brain);
	if (!_brain)
		std::cout << "Cat : Creation of Cat's brain failed" << std::endl;
}

Cat &	Cat::operator=( Cat const & other )
{
	std::cout << "Cat Assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
		*_brain = *other._brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat : Destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow" << std::endl;
}

Brain*	Cat::getBrain( void )
{
	return _brain;
}