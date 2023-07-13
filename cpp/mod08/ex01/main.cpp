/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:33:25 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/16 20:29:51 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	{
		Span	sp(4);
		sp.addNumber(0);
		sp.addNumber(-2);
		sp.addNumber(25);
		std::cout << "TEST 1\n";
		std::cout << "Numbers : " << sp << std::endl;
		try
		{
			std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		Span	sp(4);
		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);
		std::cout << "TEST 2 (LIMITS INT)\n";
		std::cout << "Numbers : " << sp << std::endl;
		try
		{
			std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		Span	sp(4);
		sp.addNumber(0);
		std::cout << "TEST ERROR (TOO LOW NUMBERS)\n";
		std::cout << "Numbers : " << sp << std::endl;
		try
		{
			std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Copy Operator\n";
		Span	sp(4);
		sp.addNumber(0);
		sp.addNumber(-566);
		sp.addNumber(424242);
		std::cout << "Numbers : " << sp << std::endl;
		
		Span	sp1(sp);
		std::cout << "Numbers : " << sp1 << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "'=' Operator\n";
		Span	sp(4);
		sp.addNumber(0);
		sp.addNumber(-566);
		sp.addNumber(424242);
		std::cout << "Numbers : " << sp << std::endl;
		
		Span	sp1(4);
		sp1 = sp;
		std::cout << "Numbers : " << sp1 << std::endl;
		try
		{
			std::cout << "shortestSpan: " << sp1.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "longestSpan: " << sp1.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		std::srand(std::time(NULL));
		std::cout << "Adding multiple numbers (vector)" << std::endl;
		Span sp(10000);
		std::vector<int> vec;
		for (int i = 0; i < 10000; i++) {
			vec.push_back(std::rand() * i);
		}
		sp.addNumbers(vec.begin(), vec.end());
		std::cout << "Numbers: " << sp << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::srand(std::time(NULL));
		std::cout << "Adding multiple numbers (int)" << std::endl;
		Span sp(10000);
		int arr[] = {2, 2, -8, 58, 57, 5744};
		sp.addNumbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::cout << "Numbers: " << sp << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
}
