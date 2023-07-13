/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:12:16 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/12 19:48:43 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void) {
	{
		int	a = 0;
		int	b = 1;
		
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min : " << ::min(a,b) << std::endl;
		std::cout << "max : " << ::max(a,b) << std::endl;
	}
	{
		float	a = 0.35f;
		float	b = 1.95f;
		
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min : " << ::min(a,b) << std::endl;
		std::cout << "max : " << ::max(a,b) << std::endl;
	}
	{
		std::string	a = "salut1";
		std::string	b = "salut2";
		
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min : " << ::min(a,b) << std::endl;
		std::cout << "max : " << ::max(a,b) << std::endl;
	}
}