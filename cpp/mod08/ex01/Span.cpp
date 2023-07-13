/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:33:26 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/16 20:24:40 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {

}

Span::Span(Span const &other){
	*this = other;
}

Span&	Span::operator=(Span const & other) {
	if (this != &other) {
		_N = other._N;
		_vec = other._vec;
	}
	return *this;
}

Span::~Span(void) {
	
}

void	Span::addNumber(int nb) {
	if (_vec.size() >= _N)
		throw TooManyNumbersException();
	_vec.push_back(nb);
}

unsigned int	Span::shortestSpan(void) const {
	if (_vec.size() <= 1)
		throw TooLowNumbersException();

	std::vector<int> sortedNumbers(_vec);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	unsigned int shortest = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 1; i < sortedNumbers.size(); i++)
	{
		unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

unsigned int	Span::longestSpan(void) const {
	if (_vec.size() <= 1)
		throw TooLowNumbersException();

	std::vector<int> sortedNumbers(_vec);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	unsigned int longest = sortedNumbers.back() - sortedNumbers.front();
	return longest;
}

int	Span::getNb(unsigned int id) const {
	if (id >= _vec.size()) {
		throw std::out_of_range("Index is out of range.");
	}
	return _vec[id];
}

const std::vector<int> &Span::getNumbers(void) const {
	return _vec;
}

std::ostream &operator<<(std::ostream &os, const Span &sp)
{
	const std::vector<int> &numbers = sp.getNumbers();
	for (size_t i = 0; i < numbers.size(); ++i)
		os << numbers[i] << " ";
	return os;
}
