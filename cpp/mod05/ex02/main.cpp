/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:28:31 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/10 13:26:36 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat	Sarko("Sarko", 42);
	PresidentialPardonForm	Contrat1("Contrat PresidentialPardonForm");
	ShrubberyCreationForm	Contrat2("Contrat ShrubberyCreationForm");
	RobotomyRequestForm	Contrat3("Contrat RobotomyRequestForm");

	std::cout << "---TEST EXEC FORM WITOUT SIGN IT---" << std::endl;
	Sarko.executeForm(Contrat1);
	Sarko.executeForm(Contrat2);
	Sarko.executeForm(Contrat3);
	
	try
	{
		Contrat1.execute(Sarko);
		std::cout << "Success\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception catched: " << e.what() << '\n';
	}
	
	try
	{
		Contrat2.execute(Sarko);
		std::cout << "Success\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception catched: " << e.what() << '\n';
	}
	
	try
	{
		Contrat3.execute(Sarko);
		std::cout << "Success\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception catched: " << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "---TEST SIGN IT---" << std::endl;
	std::cout << Sarko;
	std::cout << std::endl;
	std::cout << Contrat1;
	try
	{
		Contrat1.beSigned(Sarko);
		std::cout << "Success\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception catched: " << e.what() << '\n';
	}
	std::cout << Contrat1;
	std::cout << std::endl;
	std::cout << Contrat2;
	try
	{
		Contrat2.beSigned(Sarko);
		std::cout << "Success\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception catched: " << e.what() << '\n';
	}
	std::cout << Contrat2;
	std::cout << std::endl;
	std::cout << Contrat3;
	try
	{
		Contrat3.beSigned(Sarko);
		std::cout << "Success\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception catched: " << e.what() << '\n';
	}
	std::cout << Contrat3;
	std::cout << std::endl;
	std::cout << "---TEST EXEC IT---" << std::endl;
	Sarko.executeForm(Contrat1);
	Sarko.executeForm(Contrat2);
	Sarko.executeForm(Contrat3);
	std::cout << std::endl;
	std::cout << Contrat1;
	std::cout << Contrat2;
	std::cout << Contrat3;
	
	std::cout << "---TEST COPY IT---" << std::endl;
	PresidentialPardonForm	Contrat_success(Contrat1);
	Bureaucrat	Chief("Chief", 4);
	std::cout << Chief;
	std::cout << std::endl;
	std::cout << Contrat_success;
	try
	{
		Contrat_success.execute(Chief);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception catched: " << e.what() << '\n';
	}
	Chief.executeForm(Contrat_success);
	std::cout << Contrat_success;
	std::cout << std::endl;
	try
	{
		Contrat_success.beSigned(Chief);
		Contrat_success.execute(Chief);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception catched: " << e.what() << '\n';
	}
	return (0);
}
