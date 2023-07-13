/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:54:54 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/08 18:00:54 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// Base class
class Brain
{
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain& other);

		Brain &		operator=( Brain const & other );

	private:
		std::string	_ideas[100];
};
