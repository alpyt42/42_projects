/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:37:28 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/05 20:40:17 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap( void );
		ClapTrap( ClapTrap const & other );
		~ClapTrap(void);

		ClapTrap &	operator=( ClapTrap const & other );
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;
};
