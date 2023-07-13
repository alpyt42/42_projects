/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:39:44 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/26 16:25:56 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>
#include <string>

class Contact {
	public:
		Contact(void);
		~Contact(void);

	// getter
	std::string	get_firstname(void) const;
	std::string	get_lastname(void) const;
	std::string	get_nickname(void) const;
	std::string	get_phonenumber(void) const;
	std::string	get_darkestsecret(void) const;
	// setter
	void	set_firstname(std::string toset);
	void	set_lastname(std::string toset);
	void	set_nickname(std::string toset);
	void	set_phonenumber(std::string toset);
	void	set_darkestsecret(std::string toset);

	private :
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkestsecret;
};

#endif