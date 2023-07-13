/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:01:10 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/02 15:55:16 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool checkArguments(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Please provide <filename> <string1> <string2>" << std::endl;
		return false;
	}

	if (std::string(argv[2]).length() == 0) {
		std::cerr << "Please provide a string non NULL to find/replace." << std::endl;
		return false;
	}

	if (std::string(argv[2]) == std::string(argv[3])) {
		std::cerr << "Please provide different strings" << std::endl;
		return false;
	}
	
	return true;
}

bool openFiles(std::ifstream& ifs, std::ofstream& ofs, char **argv) {
	ifs.open(argv[1]);
	if (!ifs.is_open()) {
		std::cerr << "Error: could not open input file '" << argv[1] << "'" << std::endl;
		return false;
	}

	std::string	fd_output = std::string(argv[1]) + ".replace";
	ofs.open(fd_output.c_str());
	if (!ofs.is_open()) {
		std::cerr << "Error: could not open output file '" << fd_output << "'" << std::endl;
		return false;
	}

	return true;
}

int findAndReplace(std::ifstream& ifs, std::ofstream& ofs, char **argv) {
	char	c;
	std::string	line = "";
	std::string	newline = "";
	std::string	restline = "";
	size_t		pos = 0;
	size_t		count = 0;
	size_t		start_pos = 0;

	while (ifs.get(c))
		line += c;
	while (true) {
		pos = line.find(argv[2], start_pos);
		if (pos == std::string::npos) {
			newline += line.substr(start_pos);
			break;
		} else {
			newline += line.substr(start_pos, pos - start_pos);
			newline += argv[3];
			restline = newline;
			restline += line.substr(pos + std::string(argv[2]).length());
			line = restline;
			start_pos = pos + std::string(argv[3]).length();
			count++;
		}
	}
	ofs << line;
	return count;
}

int main(int argc, char **argv) {
	int	count;
	std::ifstream ifs;
	std::ofstream ofs;

	if (!checkArguments(argc, argv))
		return 1;

	if (!openFiles(ifs, ofs, argv))
		return 1;

	count = findAndReplace(ifs, ofs, argv);
	ifs.close();
	ofs.close();

	if (count)
		std::cout << "File has been copied and pasted to '" << argv[1] << ".replace"
			<< "' and \n" << count << " portion(s) of '"
			<< argv[2] << "' was/were successfully replaced by '" << argv[3] << "'." << std::endl;
	else
		std::cout << "File has been copied and pasted to '" << argv[1] << ".replace"
			<< "' but no correspondance of '" << argv[2]
			<< "' has been found in the input file." << std::endl;

	return 0;
}
