/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:37:28 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/05 21:03:23 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>

// Base class
class ClapTrap
{
	public:
		ClapTrap( void );
		ClapTrap(std::string name);					// constructeur par défaut qui initialise la valeur à 0
		~ClapTrap();								// destructeur
		ClapTrap(const ClapTrap& other);

		ClapTrap &	operator=( ClapTrap const & other );
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;
};
