/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:12:27 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/26 11:55:13 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "PhoneBook created" << std::endl;
	this->_id = 0;
	this->_nb_contact = 0;
}

PhoneBook::~PhoneBook(void){
	std::cout << std::endl << "PhoneBook destroyed" << std::endl;
}

bool	PhoneBook::check_number(std::string str){
	for (int i = 0; str[i]; i++){
			if (!isdigit(str[i]))
				return (false);
		}
	return(true);
}

bool	PhoneBook::control_string(std::string str){
	int	count = 0;
	for (int i = 0; str[i]; i++){
			if (!isalnum(str[i]) && str[i] != ' '){
				std::cout << "Please enter alphanumeric characters or spaces." << std::endl;
				return (false);
			}
			if (isalnum(str[i]))
				count++;
		}
	if (!count){
		std::cout << "The string does not contain alphanumeric characters, please try again." << std::endl;
		return (false);
	}
	return(true);
}

std::string	PhoneBook::format(std::string str){
	std::string space = "          ";
	space = space.substr(0, 10 - str.length());
	if (str.length() <= 10)
		return (space + str);
	else
		return (str.substr(0, 9) + '.');
}

void		PhoneBook::displaythecontact(int index){
	std::cout << "first name : " << contact[index].get_firstname() << std::endl;
	std::cout << "last name : " << contact[index].get_lastname() << std::endl;
	std::cout << "nick name : " << contact[index].get_nickname() << std::endl;
	std::cout << "phone number : " << contact[index].get_phonenumber() << std::endl;
	std::cout << "darkest secret : " << contact[index].get_darkestsecret() << std::endl;
}

void	PhoneBook::display_contact(void){
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name|  lastname|  nickname|" << std::endl;
	for (int i = 0; i < this->_nb_contact; i++){
		std::cout << "|         " << i << "|";
		std::cout << format(contact[i].get_firstname()) << "|";
		std::cout << format(contact[i].get_lastname()) << "|";
		std::cout << format(contact[i].get_nickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void		PhoneBook::searchcontact(void){
	std::string	input;
	int			index;

	if (this->_nb_contact == 0){
		std::cout << "PhoneBook empty, for now.. Please add some." << std::endl;
		return ;
	}
	display_contact();
	while (1){
		std::cout << "Enter an index to display : ";
		std::getline(std::cin, input);
		if (std::cin.eof() || !input.compare("quit"))
			return ;
		index = std::atoi(input.c_str());
		if (index < this->_nb_contact && check_number(input))
			return(displaythecontact(index));
		else if (!check_number(input))
			std::cout << "Incorrect index format." << std::endl;
		else
			std::cout << "This contact does not exist ('quit' to leave this action)." << std::endl;
	}
}

void	PhoneBook::set_contactinfo(std::string firstName,
							std::string lastName,
							std::string nickName,
							std::string phoneNumber,
							std::string darkestsecret)
{
	contact[this->_id].set_firstname(firstName);
	contact[this->_id].set_lastname(lastName);
	contact[this->_id].set_nickname(nickName);
	contact[this->_id].set_phonenumber(phoneNumber);
	contact[this->_id].set_darkestsecret(darkestsecret);
}

void	PhoneBook::get_contactinfo(void)
{
	std::string	inputs[5];
	std::string	infos[5] = {
			"first name : ",
			"last name : ",
			"nick name : ",
			"phone number : ",
			"darkest secret : "
	};
	if (this->_id > 7)
		this->_id = 0;
	for(int i = 0; i <= 5; i++) {
		while (inputs[i].length() == 0){
			std::cout << "Enter your " << infos[i];
			std::getline(std::cin, inputs[i]);
			if (std::cin.eof()){
				std::cout << std::endl << "Contact configuration failed.";
				return ;
			}
			if (!control_string(inputs[i]))
				inputs[i] = "";
			if (i == 3 && !check_number(inputs[i])){
				std::cout << "The phone number must be composed only by numbers." << std::endl;
				inputs[i] = "";
			}
			else if (i == 3 && inputs[i].length() != 10){
				std::cout << "The length of the phone number must be 10 digits." << std::endl;
				inputs[i] = "";
			}
		}
	}
	set_contactinfo(inputs[0], inputs[1], inputs[2], inputs[3], inputs[4]);
	this->_id++;
	if (this->_nb_contact < 8)
		this->_nb_contact++;
}