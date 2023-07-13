/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:39:13 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/08 17:24:01 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog& other);
		~Dog(void);
		Dog &	operator=(Dog const & other);
		void	makeSound( void ) const;
};
