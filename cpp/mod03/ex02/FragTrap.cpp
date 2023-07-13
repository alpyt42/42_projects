/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:45:14 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/05 21:05:42 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " : Constructor called" << std::endl;
	_hit = 100;
	_energy = 100;
	_attack = 30;
}

FragTrap::FragTrap( void ) : ClapTrap()
{
	_hit = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "FragTrap " << _name << " : Constructor called" << std::endl;
}

FragTrap &	FragTrap::operator=( FragTrap const & other )
{
	std::cout << "FragTrap assignment operator called" << std::endl;

	if (this != &other)
	{
		this->_name			= other._name;
		this->_hit	= other._hit;
		this->_energy	= other._energy;
		this->_attack	= other._attack;
	}
	return (*this);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other._name){
	_hit = other._hit;
	_energy = other._energy;
	_attack = other._attack;
	std::cout << "FragTrap " << _name << " : Copy Constructor called!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " : Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " : High fives!" << std::endl;
}
