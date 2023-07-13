/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:37:25 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/04 13:08:59 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	zizou("Zidane");
	ClapTrap	mate("Materazzi");

	zizou.attack("Materazzi");
	mate.takeDamage(9);
	mate.beRepaired(1);
	mate.beRepaired(1);
	mate.takeDamage(1);
	mate.takeDamage(1);
	zizou.beRepaired(1);

	ScavTrap	govou("govou");
	ScavTrap	barthez(govou);
	
	govou.takeDamage(20);
	govou.takeDamage(20);
	govou.takeDamage(20);
	govou.takeDamage(20);
	govou.takeDamage(20);
	govou.takeDamage(20);
    govou.beRepaired(10);
	govou.beRepaired(10);
	govou.beRepaired(10);
    govou.guardGate();
	return 0;
}