/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alric <alric@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:02:32 by ale-cont          #+#    #+#             */
/*   Updated: 2023/06/02 11:15:40 by alric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>

class RPN {
public:
	RPN(void);
	RPN(RPN const &other);
	RPN&	operator=(RPN const & other);
	~RPN(void);

	float evaluateRPN(const std::string& expression);
private:
	std::stack<float>		_numbers;
};