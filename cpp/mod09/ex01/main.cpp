/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alric <alric@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:02:27 by ale-cont          #+#    #+#             */
/*   Updated: 2023/06/02 11:17:33 by alric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]) {
	RPN	expression;
	if (argc != 2)
		return (std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl, 1);

	try
	{
		float result = expression.evaluateRPN(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}