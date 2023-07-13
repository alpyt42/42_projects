/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:39:46 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/25 16:31:33 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void){
}

Contact::~Contact(void){
}

std::string	Contact::get_firstname(void) const {
	return (this->_firstname);
}

std::string	Contact::get_lastname(void) const {
	return (this->_lastname);
}

std::string	Contact::get_nickname(void) const {
	return (this->_nickname);
}

std::string	Contact::get_phonenumber(void) const {
	return (this->_phonenumber);
}

std::string	Contact::get_darkestsecret(void) const {
	return (this->_darkestsecret);
}

void	Contact::set_firstname(std::string toset){
	this->_firstname = toset;
}

void	Contact::set_lastname(std::string toset){
	this->_lastname = toset;
}

void	Contact::set_nickname(std::string toset){
	this->_nickname = toset;
}

void	Contact::set_phonenumber(std::string toset){
	this->_phonenumber = toset;
}

void	Contact::set_darkestsecret(std::string toset){
	this->_darkestsecret = toset;
}

