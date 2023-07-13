/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:43:14 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/05 20:48:44 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " : Constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_attack = 20;
}

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	_hit = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "ScavTrap " << _name << " : Constructor called" << std::endl;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & other )
{
	std::cout << "ScavTrap assignment operator called" << std::endl;

	if (this != &other)
	{
		this->_name			= other._name;
		this->_hit	= other._hit;
		this->_energy	= other._energy;
		this->_attack	= other._attack;
	}
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other._name){
	_hit = other._hit;
	_energy = other._energy;
	_attack = other._attack;
	std::cout << "ScavTrap " << _name << " : Copy Constructor called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " : Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " : Gate keeper mode activated!" << std::endl;
}
