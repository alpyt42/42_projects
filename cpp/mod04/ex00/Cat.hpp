/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:38:50 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/08 17:23:55 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat& other);
		~Cat(void);
		Cat &	operator=(Cat const & other);
		void	makeSound( void ) const;
};
