/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:52:55 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/23 17:57:13 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
	(void)rhs;
	return *this;
}

PmergeMe::PmergeMe(PmergeMe const & src) { (void)src; }

void	PmergeMe::addNumberstoVec(char **av) {
	for (int i = 1; av[i]; i++) {
		if (strlen(av[i]) > 0) {
			size_t	nb = std::strtoul(av[i], NULL, 10);
			_vector.push_back(nb);
		}
	}
}

void	PmergeMe::addNumberstoDeq(char **av) {
	for (int i = 1; av[i]; i++) {
		if (strlen(av[i]) > 0) {
			size_t	nb = std::strtoul(av[i], NULL, 10);
			_deq.push_back(nb);
		}
	}
}

void	PmergeMe::printVec(void) {
	for (size_t i = 0; i < _vector.size() && i < 10; ++i) {
		std::cout << _vector[i] << " ";
	}
	if (_vector.size() > 10)
		std::cout << "[...]";
	std::cout << std::endl;
}

void	PmergeMe::printDeq(void) {
	for (size_t i = 0; i < _deq.size() && i < 10; ++i) {
		std::cout << _deq[i] << " ";
	}
	if (_deq.size() > 10)
		std::cout << "[...]";
	std::cout << std::endl;
}

template<typename T>
void PmergeMe::InsertAlgo(T& A) {
    typename T::iterator key, j;
    for (typename T::iterator i = A.begin() + 1; i != A.end(); ++i) {
        key = i;
        j = i - 1;
        while (j >= A.begin() && *j > *key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = *key;
    }
}

template<typename T>
void PmergeMe::mergeInsertSort(T& A, size_t ths) {
	size_t	mid;
	size_t	N = A.size();
	if (N < ths) {
		InsertAlgo(A);
		return;
	}
	mid = N / 2;
	T left(A.begin(), A.begin() + mid);
	T right(A.begin() + mid, A.end());
	mergeInsertSort(left, ths);
	mergeInsertSort(right, ths);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), A.begin());
}

void	PmergeMe::mergeInsertSortDeq(void) {
	mergeInsertSort(_deq, (_deq.size() / 100) + 2);
}

void	PmergeMe::mergeInsertSortVec(void) {
	mergeInsertSort(_vector, (_vector.size() / 100) + 2);
}

bool	PmergeMe::isSorted(std::string type) {
	if (type == "Vec") {
		for (std::vector<size_t>::iterator it = _vector.begin() ; it != _vector.end() - 1; ++it) {
			if (*it > *(it + 1))
				return false;
		}
		return true;
	}
	else if (type == "Deq") {
		for (std::deque<size_t>::iterator it = _deq.begin() ; it != _deq.end() - 1; ++it) {
			if (*it > *(it + 1))
				return false;
		}
		return true;
	}
	else
		return (std::cout << "Provide Deq or Vec to check if sorted\n", false);
	return true;
}
