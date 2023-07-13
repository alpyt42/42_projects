/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:28:31 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/08 18:31:31 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main ( void )
{
	const int		count = 10;
	Animal* animals[count];

	for (int i = 0; i < count; i++)
	{
		if (i < count/2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < count; i++) {
		std::cout << i << " : " << animals[i]->getType() << " --> ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < count; i++) {
		std::cout << i << " :\n";
		delete animals[i];
	}

	std::cout << std::endl << " --- Test deep copies--- " << std::endl;
	Dog dog;
	Dog dog_copy(dog);
	Cat cat;
	Cat cat_copy;

	cat_copy = cat;

	std::cout << std::endl << "dog brain adress:	" << dog.getBrain() << std::endl;
	std::cout << "dog_copy brain adress:	" << dog_copy.getBrain() << std::endl;

	std::cout << "cat brain adress:	" << cat.getBrain() << std::endl;
	std::cout << "cat_copy brain adress:	" << cat_copy.getBrain() << std::endl;

	std::cout << std::endl << dog.getType() << " | " << dog_copy.getType() << std::endl;
	dog.makeSound(); 
	dog_copy.makeSound();
	std::cout << cat.getType() << " | " << cat_copy.getType() << std::endl;
	cat.makeSound();
	cat_copy.makeSound();
	std::cout << std::endl;
	return (0);
}