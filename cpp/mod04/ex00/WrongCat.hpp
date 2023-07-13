/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:05:07 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/05 21:25:52 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat& other);
	~WrongCat(void);
	WrongCat &	operator=(WrongCat const & other);
	void	makeSound(void) const;
};
