/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:43:31 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/15 16:35:48 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

int main()
{
	// Test with integers
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i + 1;
	std::cout << "Original Array (int): ";
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	Array<int> intArrayCopy(intArray);
	std::cout << "Copied Array (int): ";
	for (unsigned int i = 0; i < intArrayCopy.size(); i++)
		std::cout << intArrayCopy[i] << " ";
	std::cout << std::endl;
	intArray[2] = 100;
	std::cout << "Modified Original Array (int): ";
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	std::cout << "Copied Array after Modification of Original (int): ";
	for (unsigned int i = 0; i < intArrayCopy.size(); i++)
		std::cout << intArrayCopy[i] << " ";
	std::cout << std::endl;
	Array<int> intArrayAssign;
	intArrayAssign = intArray;
	std::cout << "Assigned Array (int): ";
	for (unsigned int i = 0; i < intArrayAssign.size(); i++)
		std::cout << intArrayAssign[i] << " ";
	std::cout << std::endl;

	// Test with strings
	std::cout << std::endl;
	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";
	std::cout << "Original Array (string): ";
	for (unsigned int i = 0; i < stringArray.size(); i++)
		std::cout << stringArray[i] << " ";
	std::cout << std::endl;
	Array<std::string> stringArrayCopy(stringArray);
	std::cout << "Copied Array (string): ";
	for (unsigned int i = 0; i < stringArrayCopy.size(); i++)
		std::cout << stringArrayCopy[i] << " ";
	std::cout << std::endl;
	stringArray[1] = "42";
	std::cout << "Modified Original Array (string): ";
	for (unsigned int i = 0; i < stringArray.size(); i++)
		std::cout << stringArray[i] << " ";
	std::cout << std::endl;
	std::cout << "Copied Array after Modification of Original (string): ";
	for (unsigned int i = 0; i < stringArrayCopy.size(); i++)
		std::cout << stringArrayCopy[i] << " ";
	std::cout << std::endl;
	Array<std::string> stringArrayAssign;
	stringArrayAssign = stringArray;
	std::cout << "Assigned Array (string): ";
	for (unsigned int i = 0; i < stringArrayAssign.size(); i++)
		std::cout << stringArrayAssign[i] << " ";
	std::cout << std::endl;

	// Test with double
	std::cout << std::endl;
	Array<double> doubleArray(4);
	for (unsigned int i = 0; i < doubleArray.size(); i++)
		doubleArray[i] = i + 0.234 * i;
	std::cout << "Original Array (double): ";
	for (unsigned int i = 0; i < doubleArray.size(); i++)
		std::cout << doubleArray[i] << " ";
	std::cout << std::endl;
	Array<double> doubleArrayCopy(doubleArray);
	std::cout << "Copied Array (double): ";
	for (unsigned int i = 0; i < doubleArrayCopy.size(); i++)
		std::cout << doubleArrayCopy[i] << " ";
	std::cout << std::endl;
	doubleArray[2] = 10000.00002;
	std::cout << "Modified Original Array (double): ";
	for (unsigned int i = 0; i < doubleArray.size(); i++)
		std::cout << doubleArray[i] << " ";
	std::cout << std::endl;
	std::cout << "Copied Array after Modification of Original (double): ";
	for (unsigned int i = 0; i < doubleArrayCopy.size(); i++)
		std::cout << doubleArrayCopy[i] << " ";
	std::cout << std::endl;
	Array<double> doubleArrayAssign;
	doubleArrayAssign = doubleArray;
	std::cout << "Assigned Array (double): ";
	for (unsigned int i = 0; i < doubleArrayAssign.size(); i++)
		std::cout << doubleArrayAssign[i] << " ";
	std::cout << std::endl;

	// Test out-of-range exception
	std::cout << std::endl;
	try
	{
		std::cout << "Trying to access out-of-range index..." << std::endl;
		std::cout << intArray[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test self-assignment
	std::cout << "Performing self-assignment..." << std::endl;
	stringArray = stringArray;
	std::cout << "Array after self-assignment (string): ";
	for (unsigned int i = 0; i < stringArray.size(); i++)
		std::cout << stringArray[i] << " ";
	std::cout << std::endl;
	return 0;
}
