/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:37:25 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/03 15:09:45 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed res;
	Fixed c(32.2f);
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << "a :" << a << std::endl;
	std::cout << "++a :" << ++a << std::endl;
	std::cout << "a :" << a << std::endl;
	std::cout << "a++ :" << a++ << std::endl;
	std::cout << "a :" << a << std::endl;
	std::cout << "a-- :" << a-- << std::endl;
	std::cout << "a :" << a << std::endl;
	std::cout << "--a :" << --a << std::endl;
	std::cout << "a :" << a << std::endl;
	std::cout << "--a :" << --a << std::endl;
	std::cout << "a :" << a << std::endl;
	std::cout << "c :" << c << std::endl;
	std::cout << "c++ :" << c++ << std::endl;
	std::cout << "c :" << c << std::endl;
	std::cout << "++c :" << ++c << std::endl;
	std::cout << "c :" << c << std::endl;
	res = c * b;
	std::cout << "c * b :" << res << std::endl;
	res = c / b;
	std::cout << "c / b :" << res << std::endl;
	res = c - b;
	std::cout << "c - b :" << res << std::endl;
	res = c + b;
	std::cout << "c + b :" << res << std::endl;
	if (c < b)
		std::cout << "c < b" << std::endl;
	if (b < c)
		std::cout << "b < c" << std::endl;
	Fixed e(res);
	if (e <= res)
		std::cout << "e <= res" << std::endl;
	if (b >= c)
		std::cout << "b >= c" << std::endl;
	if (e == res)
		std::cout << "e == res" << std::endl;
	std::cout << "max(a, b) :" << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b) :" << Fixed::min(a, b) << std::endl;

	return 0;
}