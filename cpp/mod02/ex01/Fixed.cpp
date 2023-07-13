/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:37:27 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/09 12:38:31 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _val(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << _frac);
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * (1 << _frac)));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		setRawBits(other.getRawBits());
	return *this;
}

int	Fixed::getRawBits() const {
	return _val;
}

void	Fixed::setRawBits(int const raw) {
	_val = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)(_val) / (1 << _frac);
}

int		Fixed::toInt( void ) const {
	return _val >> _frac;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
