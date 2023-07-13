/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:56:50 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/12 19:02:50 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <typeinfo>

class Base
{
public:
	virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};