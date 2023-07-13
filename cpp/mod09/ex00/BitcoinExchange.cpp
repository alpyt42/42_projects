/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:38:21 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/31 12:30:47 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(void) {

}

Bitcoin::Bitcoin(Bitcoin const &other){
	*this = other;
}

Bitcoin&	Bitcoin::operator=(Bitcoin const & other) {
	if (this != &other) {
		_database = other._database;
	}
	return *this;
}

Bitcoin::~Bitcoin(void) {
	
}

static bool isDateValid(int year, int month, int day) {
	std::tm date = {0, 0, 0, day, month - 1, year - 1900, 0, 0, 0, 0, NULL};
	std::time_t time = std::mktime(&date);
	std::time_t currentTime = std::time(NULL);
	if (time > currentTime)
		return false;
	return (time != -1) && (date.tm_year == year - 1900) && (date.tm_mon == month - 1) && (date.tm_mday == day);
}

static bool	checkdate(std::string date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (std::cout << "Error: not a valid date => " << date << std::endl, false);

	std::string	year = date.substr(0, 4);
	std::string	month = date.substr(5, 2);
	std::string	day = date.substr(8, 2);

	for (int i = 0; i < 4; i++) {
		if (i < 4 && !isdigit(year[i]))
			return (std::cout << "Error: not a valid date. => " << date << std::endl, false);
		if (i < 2 && !isdigit(month[i]))
			return (std::cout << "Error: not a valid date. => " << date << std::endl, false);
		if (i < 2 && !isdigit(day[i]))
			return (std::cout << "Error: not a valid date. => " << date << std::endl, false);
	}
	if ((atof(month.c_str()) > 12 || atof(day.c_str()) > 31) ||
		(atof(year.c_str()) < 2009 || atof(month.c_str()) < 1 || atof(day.c_str()) < 1) ||
		(date < "2009-01-02") || !isDateValid(atof(year.c_str()), atof(month.c_str()), atof(day.c_str())))
			return (std::cout << "Error: not a valid date (2009-01-02 <= date <= Today) => " << date << std::endl, false);
	return true;
}

static bool	checkFormatSpace(std::string line, char c, int direc) {
	if (direc == 0) {
		for (int i = 0; line[i] && line[i + 1] && line[i + 1] != c; i++) {
			if (line[i] && line[i + 1] && line[i] == ' ' && line[i + 1] != ' ')
				return false;
		}
	}
	if (direc == 1) {
		for (int i = line.size(); i > 0; i--) {
			if (line[i] == ' ' && line[i - 1] != ' ')
				return false;
		}
	}
	return true;
}

static std::string	extractDate(std::string line, char c) {
	size_t pos = line.find(c);
	if (pos == std::string::npos)
		return (std::cout << "Error: bad input : " << line << std::endl, "");
	std::string	line_tronc = line.substr(0, pos);
	if (!checkFormatSpace(line, c, 0))
		return (std::cout << "Error: bad input (space issue): " << line_tronc << std::endl, "");
	pos = line.find(' ');
	if (line_tronc.size() > 1)
		line_tronc = line_tronc.substr(0, pos);
	if (checkdate(line_tronc))
		return line_tronc;
	return "";
}

static std::string	extractExchange_rate(std::string line, char c) {
	size_t pos = line.find(c);
	if (pos == std::string::npos)
		return (std::cout << "Error: not a valid number.\n", "");
	if (line[pos + 1] == '\0')
		return (std::cout << "Error: not a valid number.\n", "");
	std::string exchange_rate = line.substr(pos + 1);
	if (!checkFormatSpace(exchange_rate, c, 1))
		return (std::cout << "Error: invalid value (space issue): " << exchange_rate << std::endl, "");
	for (int i = exchange_rate.size(); i >= 0; i--) {
		if (exchange_rate[i] == ' ') {
			exchange_rate = exchange_rate.substr(i + 1);
			if (exchange_rate.size() == 0)
				return (std::cout << "Error: not a valid number.\n", "");
			break;
		}
	}
	int	countdot = 0;
	int	countf = 0;
	int	sign = 1;
	if (exchange_rate.size() == 1 && isdigit(exchange_rate[0]))
		return exchange_rate;
	if (exchange_rate[0] == '-') {
		sign = -1;
		exchange_rate = exchange_rate.substr(1);
	}
	else if (exchange_rate[0] == 'f' || exchange_rate[0] == '.')
		return (std::cout << "Error: not a valid number.\n", "");
	for (int i = 0; exchange_rate[i]; i++) {
		if (exchange_rate[i] == '.')
			countdot++;
		if (exchange_rate[i] == 'f')
			countf++;
		if ((exchange_rate[i] != 'f' && exchange_rate[i] != '.' && !isdigit(exchange_rate[i])) || countdot > 1
			|| (exchange_rate[i] == '.' && exchange_rate[i + 1] && exchange_rate[i + 1] == 'f') || countf > 1
			|| (exchange_rate[i] == 'f' && exchange_rate[i + 1] != '\0') || (exchange_rate[i] == '.' && exchange_rate[i + 1] == '\0')) {
			return (std::cout << "Error: not a valid number.\n", "");
		}
	}
	if (sign == -1)
		return (std::cout << "Error: not a positive number.\n", "");
	if (atof(exchange_rate.c_str()) > INT_MAX)
		return (std::cout << "Error: too large a number.\n", "");
	return exchange_rate;
}

bool	Bitcoin::fill_csv(std::ifstream& datacsv) {
	std::string	line;
	std::string	date;
	std::string	exchange_rate;
	int			count = 0;

	while (std::getline(datacsv, line)) {
		if (line != "date,exchange_rate") {
			date = extractDate(line, ',');
			if (date.empty())
				return false;
			exchange_rate = extractExchange_rate(line, ',');
			if (exchange_rate.empty())
				return false;
			_database[date] = atof(exchange_rate.c_str());
		}
		else if (count > 0)
			return false;
		count++;
	}
	if (_database.size() == 0)
		return false;
	return true;
}

bool	Bitcoin::display_res(std::ifstream& ifs) const {
	std::string	line;
	std::string	date;
	std::string	quantity = "";
	int			count = 0;
	int			status;

	while (std::getline(ifs, line)) {
		if (line != "date | value" && line.size() > 0) {
			status = 0;
			date = extractDate(line, '|');
			if (date.empty())
				status = 1;
			if (status == 0)
				quantity = extractExchange_rate(line, '|');
			if (status == 0 && quantity.empty())
				status = 1;
			if (status == 0) {
				std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
				if (it == _database.end())
					--it; // previous date if not found
				float result = atof(quantity.c_str()) * it->second;
				if (atof(quantity.c_str()) > 1000.0)
					std::cout << "Error: not a valid number: " << quantity.c_str() << " (condition : 0.0 <= quantity <= 1000.0)\n";
				else
					std::cout << date << " => " << quantity << " = " << result << std::endl;
			}
		}
		else if (count > 0 && line == "date | value")
			return (std::cout << "Error: you must put 'date | value' only at the beginning of the file\n", false);
		count++;
	}
	return true;
}

void	Bitcoin::displaydatabase(void) const {
	std::map<std::string, float>::const_iterator iter;
	for (iter = _database.begin(); iter != _database.end(); ++iter)
		std::cout << iter->first << " => " << iter->second << std::endl;
}
