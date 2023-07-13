/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:06:47 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/26 18:06:54 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *heapZombie = newZombie("Heap Zombie");
	if (heapZombie == NULL)
		return (0);
	heapZombie->announce();
	delete heapZombie;

	Zombie stackZombie("Stack Zombie");
	stackZombie.announce();

	randomChump("Chump Zombie");

	return 0;
}