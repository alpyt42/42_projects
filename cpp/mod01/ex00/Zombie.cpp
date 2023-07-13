/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:07:59 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/26 17:43:44 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){

}

Zombie::~Zombie(void){
	std::cout << _name << " died" << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
