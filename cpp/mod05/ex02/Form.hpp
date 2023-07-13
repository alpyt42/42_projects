/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:21:30 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/10 00:20:15 by ale-cont         ###   ########.fr       */
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

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw() {
					return "Form not signed";
				}
		};

		Form(const std::string& name, int const gradetosign, int const gradetoexec);
		Form(const Form& other);
		virtual ~Form(void);
		Form &		operator=( Form const & other );

		void			beSigned(Bureaucrat const & bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
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