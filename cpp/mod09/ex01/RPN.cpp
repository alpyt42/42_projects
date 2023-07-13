/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alric <alric@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:02:29 by ale-cont          #+#    #+#             */
/*   Updated: 2023/06/02 11:15:54 by alric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {
}

RPN::RPN(RPN const &other){
	*this = other;
}

RPN&	RPN::operator=(RPN const & other) {
	if (this != &other) {
		_numbers = other._numbers;
	}
	return *this;
}

RPN::~RPN(void) {
}

static float	performOperation(char operation, float nb1, float nb2) {
	switch (operation) {
	case '+':
		return nb1 + nb2;
	case '-':
		return nb1 - nb2;
	case '*':
		return nb1 * nb2;
	case '/':
		return nb1 / nb2;
	default:
		throw std::runtime_error("Invalid operation");
	}
}

static bool	isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

float RPN::evaluateRPN(const std::string &expression) {
	for (int i = 0; expression[i]; i++) {
		if (isdigit(expression[i])) {
			int operand = expression[i] - '0';
			_numbers.push(operand);
		}
		else if (isOperator(expression[i])) {
			if (_numbers.size() < 2) {
				throw std::runtime_error("Invalid expression: please enter enough digit to proceed");
			}
			float nb2 = _numbers.top();
			_numbers.pop();
			float nb1 = _numbers.top();
			_numbers.pop();
			if (nb2 == 0 && expression[i] == '/') {
				throw std::runtime_error("Division by zero.");
			}
			float result = performOperation(expression[i], nb1, nb2);
			_numbers.push(result);
		}
		else if (expression[i] != ' ') {
			throw std::runtime_error("Invalid expression: Invalid element");
		}
	}
	if (_numbers.size() != 1) {
		throw std::runtime_error("Invalid expression : please enter enough digit to proceed");
	}
	return _numbers.top();
}