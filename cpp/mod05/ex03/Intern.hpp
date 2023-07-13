/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:58:02 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/10 19:08:34 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern(void);

		Intern&	operator=( Intern const & other );
		Form*	makeForm(std::string nameForm, std::string target);
};