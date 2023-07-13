/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:10:41 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/10 00:07:09 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm&	operator=( ShrubberyCreationForm const & other );
		void	execute(Bureaucrat const & executor) const;
	private:
		std::string	_target;
};
