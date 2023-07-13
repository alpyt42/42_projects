/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:56:28 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/25 13:22:53 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	int randomNum = std::rand() % 3;

	switch (randomNum)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
		default:
			break;
	}
	return NULL;
}

void identify(Base *p)
{
	A *derivedPtrA = dynamic_cast<A *>(p);
	B *derivedPtrB = dynamic_cast<B *>(p);
	C *derivedPtrC = dynamic_cast<C *>(p);
	
	if (derivedPtrA)
		std::cout << "A" << std::endl;
	else if (derivedPtrB)
		std::cout << "B" << std::endl;
	else if (derivedPtrC)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	Base	res;

	try
	{
		res = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast &bc) {
	}

	try
	{
		res = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast &bc) {
	}

	try
	{
		res = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast &bc) {
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	try
	{
		Base *instancePtr = generate();
		identify(instancePtr);
		delete instancePtr;
	}
	catch (...)
	{
		std::cout << "Unknown type (Pointer)" << std::endl;
	}

	try
	{
		Base *instancePtr = generate();
		identify(*instancePtr);
		delete instancePtr;
	}
	catch (...)
	{
		std::cout << "Unknown type (Reference)" << std::endl;
	}

	return 0;
}

