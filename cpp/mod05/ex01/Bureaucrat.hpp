/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:23:36 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/09 15:20:26 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"
class Form;
// Base class
class Bureaucrat
{
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Bureaucrat grade is too High.";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Bureaucrat grade is too Low.";
				}
		};

		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &		operator=( Bureaucrat const & other );


		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(Form &form);
	
		// getters
		std::string	getName(void) const;
		int			getGrade(void) const;

	private:
		std::string	_name;
		int			_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);