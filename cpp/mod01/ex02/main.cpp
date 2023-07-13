/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:18:47 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/27 14:47:19 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string&	stringREF = brain;
	
	std::cout << "The address of the string in memory : " << &brain << std::endl;
	std::cout << "The address stored in stringPTR : " << stringPTR << std::endl;
	std::cout << "The address stored in stringREF : " << &stringREF << std::endl;
	std::cout << "The value of the string : " << brain << std::endl;
	std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;

	return (0);
}