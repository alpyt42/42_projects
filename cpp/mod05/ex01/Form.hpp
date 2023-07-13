/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:21:30 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/09 18:49:06 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
class Bureaucrat;

// Base class
class Form
{
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Form grade is too High.";
				}
		};
	
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Form grade is too Low.";
				}
		};

		Form(const std::string& name, int const gradetosign, int const gradetoexec);
		~Form(void);
		Form(const Form& other);
		Form &		operator=( Form const & other );

		void	beSigned(Bureaucrat const &bureaucrat);

		// getters
		std::string const &	getName(void) const;
		int const &			getGradeToSign(void) const;
		int const &			getGradeToExec(void) const;
		bool				isSigned(void) const;

	private:
		std::string const	_name;
		int const			_gradetosign;
		int const			_gradetoexec;
		bool				_signed;
};

std::ostream &operator<<(std::ostream &os, const Form &form);