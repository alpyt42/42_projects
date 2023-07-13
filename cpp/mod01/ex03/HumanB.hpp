/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:36:37 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/02 16:05:50 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(const std::string& newName);
		~HumanB(void);

	void	attack(void) const;
	void	setWeapon(Weapon& newWeapon);
	
	private :
		std::string	_name;
		Weapon*		_weapon;
};
