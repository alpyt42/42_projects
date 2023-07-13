/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:58:01 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/10 19:32:29 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void){
	
}

Intern &	Intern::operator=( Intern const & other )
{
	(void)other;
	return (*this);
}

Intern::Intern(const Intern& other){
	*this = other;
}

Intern::~Intern(void) {
	
}

static Form*	newPresidentialPardonForm(std::string target) {
	return (new PresidentialPardonForm(target));
}

static Form*	newShrubberyCreationForm(std::string target) {
	return (new ShrubberyCreationForm(target));
}

static Form*	newRobotomyRequestForm(std::string target) {
	return (new RobotomyRequestForm(target));
}

Form *Intern::makeForm(std::string nameForm, std::string target) {
	std::string tab[3] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
	Form *(*fct[3])(std::string) = {&newPresidentialPardonForm, &newShrubberyCreationForm, &newRobotomyRequestForm};

	for (int i = 0; i < 3; i++)
	{
		if (nameForm == tab[i])
			return fct[i](target);
	}

	std::cout << "Form not found --> provide either : 'PresidentialPardonForm', 'ShrubberyCreationForm', 'RobotomyRequestForm'\n";
	return NULL;
}
