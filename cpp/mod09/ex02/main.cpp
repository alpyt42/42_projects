/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:02:27 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/24 11:25:21 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool	checkArguments(int ac, char **av) {
	if (ac < 2 || (ac == 2 && strlen(av[1]) == 0))
		return (std::cerr << "Error: No numbers found. Provide for example: ./PmergeMe 5 4 8 6 9" << std::endl, false);
	for (int i = 1; av[i]; i++) {
		if (strlen(av[i]) > 10)
			return (std::cerr << "Error: Possible overflow detected: '" << av[i] << "'." << std::endl, false);
		for (int j = 0; av[i][j]; j++) {
			if (j == 0 && av[i][j] == '-')
				return (std::cerr << "Error: Negative numbers are not allowed: '" << av[i] << "'." << std::endl, false);
			else if (!isdigit(av[i][j]))
				return (std::cerr << "Error: Invalid number: '" << av[i] << "'." << std::endl, false);
		}
		unsigned long	nb = std::strtoul(av[i], NULL, 10);
		if (nb > UINT_MAX)
			return (std::cerr << "Error: Overfow detected for this number: '" << av[i] << "'." << std::endl, false);
	}
	return (true);
}

int main(int ac, char* av[])
{
	PmergeMe	nbs;

	if (!checkArguments(ac, av))
		return 1;
	std::cout << "Vector Before:\t";
	for (int i = 1; av[i] && i < 11; ++i) {
		std::cout << av[i] << " ";
	}
	if (ac > 11)
		std::cout << "[...]";
	std::cout << std::endl;
	nbs.addNumberstoVec(av);
	clock_t start = clock();
	nbs.mergeInsertSortVec();
	clock_t end = clock();
	double duration = double (end - start) / CLOCKS_PER_SEC * 100000;
	std::cout << "Vector After:\t";
	nbs.printVec();
	if (nbs.isSorted("Vec")) {
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector<size_t> : " << duration << " us.\n";
		std::cout << "Vector is sorted\n\n";
	}
	else
		std::cout << "Vector is not sorted\n";

	if (!checkArguments(ac, av))
		return 1;
	std::cout << "Deque Before:\t";
	for (int i = 1; av[i] && i < 11; ++i) {
		std::cout << av[i] << " ";
	}
	if (ac > 11)
		std::cout << "[...]";
	std::cout << std::endl;
	nbs.addNumberstoDeq(av);
	start = clock();
	nbs.mergeInsertSortDeq();
	end = clock();
	duration = double (end - start) / CLOCKS_PER_SEC * 100000;
	std::cout << "Deque After:\t";
	nbs.printDeq();
	if (nbs.isSorted("Deq")) {
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque<size_t> : " << duration << " us.\n";
		std::cout << "Deque is sorted\n";
	}
	else
		std::cout << "Deque is not sorted\n";
	return 0;
}
