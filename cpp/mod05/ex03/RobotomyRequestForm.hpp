/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:10:37 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/10 00:07:27 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);

		RobotomyRequestForm&	operator=( RobotomyRequestForm const & other );
		void	execute(Bureaucrat const & executor) const;
	private:
		std::string	_target;
};
