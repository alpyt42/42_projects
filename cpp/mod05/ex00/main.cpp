/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:28:31 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/09 13:18:00 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat pele("Pele", 1);
		std::cout << pele << std::endl;

		pele.decrementGrade();
		std::cout << pele << std::endl;

		pele.incrementGrade();
		std::cout << pele << std::endl;

		pele.incrementGrade();
		std::cout << pele << std::endl; // stop here because excpetion catch
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat mbappe("Mbappe", 150);
		std::cout << mbappe << std::endl;
		mbappe.decrementGrade();
		std::cout << mbappe << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	

	return 0;
}