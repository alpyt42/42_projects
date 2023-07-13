/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:54:22 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/15 16:16:39 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
class Array
{
public:
	class OutOfRangeException : public std::exception
	{
		virtual const char* what( void ) const throw() {
			return ("The index is out of limits.");
		}
	};

	Array<T>() : _elements(NULL), _arrsize(0) { }

	Array<T>(unsigned int size) : _elements(new T[size]), _arrsize(size) { }

	Array<T>(const Array& other) : _arrsize(0) { *this = other; }

	~Array<T>() {
		if (this->_elements)
			delete[]	_elements;
	}

	T &	operator[](unsigned int index) const {
		if (index > this->size())
			throw OutOfRangeException();
		return _elements[index];
	}

	unsigned int	size(void) const { return _arrsize; }

	Array<T>& operator=(const Array& other) {
		if (this != &other)
		{
			if (this->_arrsize > 0)
				delete[] this->_elements;
			this->_arrsize = other._arrsize;
			T *newElements = new T[this->size()];
			for (unsigned int i = 0; i < this->_arrsize; i++)
				newElements[i] = other[i];
			this->_elements = newElements;
		}
		return *this;
	}

private:
	T*				_elements;
	unsigned int	_arrsize;
};
