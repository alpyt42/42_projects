/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:43:16 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/05 20:47:00 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap( void );
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap(void);

	ScavTrap &	operator=( ScavTrap const & other );
	
	void guardGate(void);
};
