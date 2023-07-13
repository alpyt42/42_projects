/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:45:13 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/05 21:04:54 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap( void );
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);
	~FragTrap();

	FragTrap &	operator=( FragTrap const & other );
	void	highFivesGuys(void);
};
