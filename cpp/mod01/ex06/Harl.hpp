/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:03:25 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/02 16:27:19 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl {
	public:
		Harl();
		~Harl(void);

	void	complain(std::string level);
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

};
