/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:37:28 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/02 19:21:31 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	public:
		Fixed();								// constructeur par défaut qui initialise la valeur à 0
		~Fixed();								// destructeur
		Fixed(const Fixed &other);				// constructeur de recopie
		void	operator=(const Fixed &other);	// surcharge de l'operateur d'affectation
		int		getRawBits() const;				// retourne la valeur brute du nombre
		void	setRawBits(int const raw);		// initialise la valeur brute du nombre

	private:
		int _val;								// stocke la valeur du nombre en virgule fixe
		static const int _frac = 8;				// nombre de bits de la partie fractionnaire (constante)
};
