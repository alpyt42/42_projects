/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:42:08 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/02 16:06:00 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);

		void	announce( void ) const;
		void	setName(std::string const& name);
	private:
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );
