/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:37:25 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/04 11:36:06 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	zizou("Zidane");
	ClapTrap	mate("Materazzi");

	zizou.attack("Materazzi");
	zizou.attack("Materazzi");
	zizou.attack("Materazzi");
	zizou.attack("Materazzi");
	zizou.attack("Materazzi");
	zizou.attack("Materazzi");
	zizou.attack("Materazzi");
	zizou.attack("Materazzi");
	zizou.attack("Materazzi");
	zizou.attack("Materazzi");
	zizou.attack("Materazzi");
	zizou.attack("Materazzi");

	mate.takeDamage(9);
	mate.takeDamage(1);
	mate.takeDamage(0);
	mate.beRepaired(1);
	mate.beRepaired(1);
	mate.takeDamage(0);
	mate.takeDamage(1);
	mate.takeDamage(1);
	mate.takeDamage(1);
	mate.takeDamage(1);
	zizou.beRepaired(1);
	zizou.beRepaired(1);
	zizou.beRepaired(1);

	return 0;
}