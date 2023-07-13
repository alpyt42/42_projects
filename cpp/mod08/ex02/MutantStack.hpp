/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:12:57 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/17 14:23:36 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack<T>(void) { return; };
		MutantStack<T>( const MutantStack<T> &other ) { *this = other; };
		~MutantStack<T>(void) { return; };

		MutantStack<T>	&operator=( const MutantStack<T> &other ) {
		(void)other;
		return *this;
	}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin( void ) { return this->c.begin(); }
		iterator	end( void ) { return this->c.end(); }
	private:
};
