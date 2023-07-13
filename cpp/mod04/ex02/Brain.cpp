/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:54:51 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/08 18:09:06 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain : Constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain : Copy Constructor called!" << std::endl;
	*this = other;
}

Brain &	Brain::operator=( Brain const & other )
{
	std::cout << "Brain Assignment operator called" << std::endl;
	if (this != &other) {
		for (size_t i = 0; i < _ideas->size(); i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain : Destructor called" << std::endl;
}
