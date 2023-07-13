/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:25:42 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/12 16:40:44 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataStruct.hpp"

static uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

static Data	*deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	Data data(42);

	std::cout << "Before : data.value = " << data.value << "\n";
	uintptr_t serialized = serialize(&data);
	Data *deserialized = deserialize(serialized);
	std::cout << "After : deserialized->value = " << deserialized->value << "\n";

	if (deserialized == &data)
		std::cout << "Deserialization successful. Pointers match." << std::endl;
	else
		std::cout << "Deserialization failed. Pointers do not match." << std::endl;
	return 0;
}
