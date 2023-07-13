/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:43:16 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/05 21:01:58 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap( void );
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap();
	
	ScavTrap &	operator=( ScavTrap const & other );
	void guardGate();
};
