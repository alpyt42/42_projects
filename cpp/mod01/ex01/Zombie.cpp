/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:42:06 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/26 18:09:27 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("noname"){

}

Zombie::~Zombie(void){
	std::cout << _name << " died" << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string const& name){
	_name = name;
}
