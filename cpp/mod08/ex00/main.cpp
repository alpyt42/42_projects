/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:42:43 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/29 14:19:16 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	std::cout << "VECTOR : " << std::endl;
	int arr[] = {1, 2, 3, 4, 3};
	std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	try
	{
		int	tofind1 = 3;
		std::cout << "Try to find : " << tofind1 << std::endl;
		std::vector<int>::iterator it = easyfind(numbers, tofind1);
		std::cout << "Found value at index: " << std::distance(numbers.begin(), it) << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "LIST : " << std::endl;
	std::list<int> list;
	for (int i = 0; i < 22; i++)
		list.push_back(i + i);
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	try
	{
		int	tofind2 = 15;
		std::cout << "Try to find : " << tofind2 << std::endl;
		std::list<int>::iterator it = easyfind(list, tofind2);
		std::cout << "Found value at index: " << std::distance(list.begin(), it) << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}