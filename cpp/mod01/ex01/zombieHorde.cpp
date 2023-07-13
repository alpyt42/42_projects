/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:42:04 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/26 18:06:37 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	if (horde == NULL)
		return NULL;
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}