/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:36:40 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/02 16:09:26 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon {
	public:
		Weapon(const std::string& type);
		~Weapon(void);
	// getter
	const std::string&	getType();
	// setter
	void				setType(const std::string& newType);

	private :
		std::string	_type;
};
