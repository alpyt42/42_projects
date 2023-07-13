/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:37:27 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/02 19:41:40 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _val(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		setRawBits(other.getRawBits());
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _val;
}

void	Fixed::setRawBits(int const raw) {
	_val = raw;
}
