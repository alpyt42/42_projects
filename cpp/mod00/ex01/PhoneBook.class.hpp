/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:12:50 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/26 16:25:50 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <cstdlib>

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

	void		get_contactinfo(void);
	void		set_contactinfo(std::string firstName,
								std::string lastName,
								std::string nickName,
								std::string phoneNumber,
								std::string darkestSecret);
	void		searchcontact(void);
	void		display_contact(void);
	void		displaythecontact(int index);
	bool		check_number(std::string str);
	bool		control_string(std::string str);
	std::string	format(std::string str);

	private:
		Contact	contact[8];
		int		_id;
		int		_nb_contact;
};

#endif