/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:28:31 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/09 15:45:34 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	std::cout << "Test 1\n";
	{
		// Create a Bureaucrat and a Form
		Bureaucrat John("Johnny", 50);
		Form form1("Concert à l'Olympia", 60, 70);

		// Output initial states
		std::cout << John << std::endl;
		std::cout << form1 << std::endl;

		// Attempt to sign the form using Bureaucrat's signForm()
		try {
			John.signForm(form1);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		// Output the form's updated state
		std::cout << form1 << std::endl;
	}

	std::cout << "Test 2\n";
	{
		// Create a Bureaucrat and a Form
		Bureaucrat Jack("Jackson", 65);
		Form form2("Concert au Zenith", 60, 70);

		// Output initial states
		std::cout << Jack << std::endl;
		std::cout << form2 << std::endl;

		// Attempt to sign the form using Bureaucrat's signForm()
		try {
			Jack.signForm(form2);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		// Output the form's updated state
		std::cout << form2 << std::endl;
	}
	
	std::cout << "Test 3\n";
	{
		// Attempt to create a Form with invalid grade
		try {
			Form invalidForm("Invalid Form", 200, 100);
		} catch (const std::exception& e) {
			std::cout << "Exception caught while creating form: " << e.what() << std::endl;
		}

		// Attempt to create a Form with invalid grade
		try {
			Form invalidForm("Invalid Form", 100, 200);
		} catch (const std::exception& e) {
			std::cout << "Exception caught while creating form: " << e.what() << std::endl;
		}

		// Attempt to create a Form with invalid grade
		try {
			Form invalidForm("Invalid Form", 0, 100);
		} catch (const std::exception& e) {
			std::cout << "Exception caught while creating form: " << e.what() << std::endl;
		}

		// Attempt to create a Form with invalid grade
		try {
			Form invalidForm("Invalid Form", 100, 0);
		} catch (const std::exception& e) {
			std::cout << "Exception caught while creating form: " << e.what() << std::endl;
		}
	}
	return 0;
}
