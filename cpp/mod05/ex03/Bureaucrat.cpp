/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:45 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/10 12:47:32 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & other )
{
	if (this != &other) {
		_grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade){
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {
	
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()){
	*this = other;
}

void	Bureaucrat::incrementGrade(void) {
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade(void) {
	_grade++;
	if (_grade > 150)
		throw GradeTooLowException();
}

std::string	Bureaucrat::getName(void) const { return _name; }

int	Bureaucrat::getGrade(void) const { return _grade; }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
		os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
		return os;
}

void	Bureaucrat::signForm(Form &form) {
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't signed " << form.getName() << " because: " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form) {
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception const & e )
	{
		std::cerr << _name << " couldn't execute form because: " <<  e.what() << std::endl;
	}
}