/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:33:27 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/16 20:23:48 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <ctime>

class Span {
public:
	class TooManyNumbersException : public std::exception {
		virtual const char* what( void ) const throw() {
			return ("The vector is already full");
		}
	};

	class TooLowNumbersException : public std::exception {
		virtual const char* what( void ) const throw() {
			return ("Please add more numbers for this action");
		}
	};

	Span(unsigned int N);
	Span(Span const &other);
	Span&	operator=(Span const & other);
	~Span(void);

	void			addNumber(int nb);
	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;
	template <typename InputIterator>
	void	addNumbers(InputIterator first, InputIterator last) {
		while (first != last)
		{
			addNumber(*first);
			++first;
		}
	}
	//getters
	int				getNb(unsigned int id) const;
	const std::vector<int>& getNumbers(void) const;
private:
	unsigned int		_N;
	std::vector<int>	_vec;
};

std::ostream &operator<<(std::ostream &os, const Span &sp);