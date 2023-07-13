/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:05:47 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/12 20:15:43 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
void	iter(T* array, size_t len, void f(const T& elem)) {
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}