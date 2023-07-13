/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:37:25 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/04 18:54:33 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "ClapTrap : \n";
	ClapTrap	zizou("Zidane");
	ClapTrap	mate("Materazzi");

	zizou.attack("Materazzi");
	mate.takeDamage(9);
	mate.beRepaired(1);
	mate.beRepaired(1);
	mate.takeDamage(1);
	mate.takeDamage(1);
	zizou.beRepaired(1);

	std::cout << "\nScavTrap : \n";
	ScavTrap	govou("govou");
	ScavTrap	barthez(govou);
	
	barthez.takeDamage(20);
	govou.takeDamage(20);
	govou.takeDamage(20);
	govou.takeDamage(20);
	govou.takeDamage(20);
	govou.takeDamage(20);
	barthez.beRepaired(10);
	govou.beRepaired(10);
	govou.beRepaired(10);
	govou.guardGate();

	std::cout << "\nFragTrap : \n";
	FragTrap	mbappe("mbappe");
	mbappe.attack("govou");
	mbappe.attack("govou");
	mbappe.attack("govou");
	mbappe.attack("govou");
	mbappe.attack("govou");
	mbappe.takeDamage(20);
	mbappe.takeDamage(20);
	mbappe.takeDamage(20);
	mbappe.takeDamage(20);
	mbappe.takeDamage(20);
	mbappe.takeDamage(20);
	mbappe.beRepaired(10);
	mbappe.beRepaired(10);
	mbappe.beRepaired(10);
	mbappe.highFivesGuys();
	return 0;
}