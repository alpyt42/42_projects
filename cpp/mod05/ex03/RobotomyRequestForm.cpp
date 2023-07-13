/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:10:35 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/09 23:43:56 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("RobotomyRequestForm", 72, 45), _target(target) {
	std::srand(std::time(NULL));
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & other )
{
	if (this != &other) {
		Form::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other.getName(), other.getGradeToSign(), other.getGradeToExec()) {
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	std::cout << _target << " Vroom Vroom, (yes that's drilling noises...)" << std::endl;
	int randomNumber = rand() % 2;
	if (randomNumber == 0)
		std::cout << _target << " has been robotomized successfully 50% of the time" << std::endl;
	else
		std::cout << "Robotomy failed for " << _target << std::endl;
}
