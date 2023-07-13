/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:12:55 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/17 14:26:50 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(17);
	mstack.push(5);
	MutantStack<int>::iterator it1 = mstack.begin();
	MutantStack<int>::iterator ite1 = mstack.end();
	std::cout << "numbers in the stack :" << std::endl;
	while (it1 != ite1) {
		std::cout << *it1++ << std::endl;
	}
	std::cout << std::endl;
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	std::cout << "remove: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	--ite;
	++ite;
	std::cout << "numbers in the stack :" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	return 0;
}
