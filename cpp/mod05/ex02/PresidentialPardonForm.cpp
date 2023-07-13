/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:10:32 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/09 23:03:05 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form("PresidentialPardonForm", 25, 5), _target(target) {
	
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & other )
{
	if (this != &other) {
		Form::operator=(other);
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(other.getName(), other.getGradeToSign(), other.getGradeToExec()) {
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
