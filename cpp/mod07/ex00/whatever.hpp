/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:12:22 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/12 19:39:56 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
void	swap(T &a, T &b) {
	T	tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	const min(T const& a, T const& b) {
	return (a < b ? a : b);
}

template<typename T>
T	const max(T const& a, T const& b) {
	return (a > b ? a : b);
}