/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:21:28 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/09 22:58:52 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int const gradetosign, int const gradetoexec) : _name(name), _gradetosign(gradetosign), _gradetoexec(gradetoexec), _signed(false) {
	if (_gradetosign < 1 || _gradetoexec < 1)
		throw GradeTooHighException();
	else if (_gradetosign > 150 || _gradetoexec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other.getName()), _gradetosign(other.getGradeToSign()), _gradetoexec(other.getGradeToExec()){
	*this = other;
}

Form::~Form(void) {
	
}

Form &	Form::operator=( Form const & other )
{
	if (this != &other) {
		_signed = other.isSigned();
	}
	return (*this);
}

void	Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() <= _gradetosign)
		_signed = true;
	else
		throw GradeTooLowException();
}

static std::string	stringbool(bool sts){
	if (sts)
		return "true";
	return "false";
}

// getters
std::string const	&Form::getName(void) const { return _name; }
int const			&Form::getGradeToSign(void) const { return _gradetosign; }
int const			&Form::getGradeToExec(void) const { return _gradetoexec; }
bool				Form::isSigned(void) const { return _signed; }

// operator <<
std::ostream &operator<<(std::ostream &os, const Form &form) {
		os << form.getName() << ", form GradeToSign: " << form.getGradeToSign() << std::endl;
		os << form.getName() << ", form GradeToExec: " << form.getGradeToExec() << std::endl;
		os << form.getName() << ", form Signed: " << stringbool(form.isSigned()) << std::endl;
		return os;
}
