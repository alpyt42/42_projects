/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:37:27 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/05 21:03:45 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attack(0){
	std::cout << "ClavTrap " << _name << " : Constructor called" << std::endl;
}

ClapTrap::ClapTrap( void ) : _hit(10), _energy(10), _attack(0)
{
	this->_name = "Clap_default";
	std::cout << "ClapTrap " << _name << " : Constructor called" << std::endl;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & other )
{
	std::cout << "ClapTrap assignment operator called" << std::endl;

	if (this != &other)
	{
		this->_name			= other._name;
		this->_hit	= other._hit;
		this->_energy	= other._energy;
		this->_attack	= other._attack;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClavTrap " << _name << " : Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
											_hit(other._hit),
											_energy(other._energy),
											_attack(other._attack)
{
	std::cout << "ClapTrap " << _name << " has been cloned!" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (_energy > 0) {
		_energy--;
		std::cout << "ClapTrap " << _name << " attacks "
				<< target << ", causing " << _hit << " hit points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << "doesn't have enough energy points" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hit > 0){
		if (_hit < amount)
			_hit = 0;
		else
			_hit -= amount;
		std::cout << "ClapTrap " << _name << " lose "
			<< amount << " hit points." << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is already dead (cannot inflict more damage)" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit == 0){
		std::cout << "ClapTrap " << _name << " is already dead (not possible to resuscitate)" << std::endl;
		return;
	}
	if (_energy > 0){
		_energy--;
		_hit += amount;
		std::cout << "ClapTrap " << _name << " gained "
					<< amount << " hit points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points" << std::endl;
}
