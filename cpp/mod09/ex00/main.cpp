/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:38:18 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/18 11:44:56 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	checkOpenFiles(char **av, std::ifstream& ifs, std::ifstream& datacsv) {
	datacsv.open("data.csv");
	if (!datacsv.is_open()) {
		std::cerr << "Error: could not open 'data.csv'" << std::endl;
		return false;
	}
	ifs.open(av[1]);
	if (!ifs.is_open()) {
		datacsv.close();
		std::cerr << "Error: could not open input file '" << av[1] << "'" << std::endl;
		return false;
	}
	return true;
}

int	main(int ac, char **av) {
	std::ifstream	ifs;
	std::ifstream	datacsv;
	Bitcoin			btc;

	if (ac != 2)
		return (std::cout << "Please provide a input file : ./btc <filename>\n", 1);
	if (!checkOpenFiles(av, ifs, datacsv))
		return (1);
	if (!btc.fill_csv(datacsv)) {
		std::cout << "Invalid 'data.csv', please check it\n";
		datacsv.close();
		ifs.close();
		return 3;
	}
	if (!btc.display_res(ifs)) {
		datacsv.close();
		ifs.close();
		return 4;
	}
	// btc.displaydatabase();
	datacsv.close();
	ifs.close();
	return 0;
}
