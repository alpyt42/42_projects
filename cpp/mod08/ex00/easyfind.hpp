/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:45:43 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/15 19:20:27 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return it;
	throw std::runtime_error("Value not found");
}
