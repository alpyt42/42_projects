/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:05:44 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/12 20:24:07 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
static void	printElement(const T& elem) {
	std::cout << elem << " ";
}

int main()
{
	std::string stringArray[7] = {"C", "O", "U", "C", "O", "U"};
	size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);
	std::cout << "Printing string array elements: ";
	::iter(stringArray, stringArrayLength, printElement);
	std::cout << std::endl;

	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
	std::cout << "Printing int array elements: ";
	::iter(intArray, intArrayLength, printElement);
	std::cout << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
	std::cout << "Printing double array elements: ";
	::iter(doubleArray, doubleArrayLength, printElement);
	std::cout << std::endl;
	return 0;
}