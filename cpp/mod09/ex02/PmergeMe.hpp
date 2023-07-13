/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:52:58 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/23 16:17:52 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <deque>
#include <time.h>

class PmergeMe
{
public:
	PmergeMe(void);
	~PmergeMe(void);

	void	addNumberstoVec(char **av);
	void	addNumberstoDeq(char **av);
	void	printVec(void);
	void	printDeq(void);
	void	mergeInsertSortVec(void);
	void	mergeInsertSortDeq(void);
	bool	isSorted(std::string type);
private:
	PmergeMe & operator=(PmergeMe const & rhs);
	PmergeMe(PmergeMe const &);
	template<typename T>
	void	mergeInsertSort(T& A, size_t ths);
	template<typename T>
	void	InsertAlgo(T& A);
	std::vector<size_t>	_vector;
	std::deque<size_t>	_deq;
};
