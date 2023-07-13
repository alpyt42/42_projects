/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:36:39 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/02 16:05:42 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(const std::string& newName, Weapon& newWeapon);
		~HumanA(void);

	void	attack(void) const;

	private :
		std::string	_name;
		Weapon&		_weapon;
};
