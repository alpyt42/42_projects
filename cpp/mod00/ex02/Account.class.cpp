/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:05:07 by ale-cont          #+#    #+#             */
/*   Updated: 2023/04/26 16:01:45 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ){return(_nbAccounts);}
int	Account::getTotalAmount( void ){return(_totalAmount);}
int	Account::getNbDeposits( void ){return(_totalNbDeposits);}
int	Account::getNbWithdrawals( void ){return(_totalNbWithdrawals);}
int	Account::checkAmount( void ) const{return (_amount);}

Account::Account( int initial_deposit ){
	_amount = initial_deposit;
	_accountIndex = getNbAccounts();
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount 
				<< ";deposits:" << _totalNbDeposits 
				<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount 
				<< ";deposits:" << _nbDeposits 
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
	int	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount 
				<< ";deposit:" << deposit << ";amount:" << _amount 
				<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	int	p_amount = _amount;
	_displayTimestamp();
	if (checkAmount() < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount 
				<< ";withdrawal:" << "refused" <<  std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount 
				<< ";withdrawal:" << withdrawal << ";amount:" << _amount 
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

void Account::_displayTimestamp(void)
{
	// Get current time
	std::time_t	now_time;
	std::time(&now_time);

	// Convert current time to struct tm
	std::tm *now_tm = std::localtime(&now_time);

	// Format the timestamp and display
	char timestamp[20];
	std::strftime(timestamp, 20, "%Y%m%d_%H%M%S", now_tm);
	std::cout << '[' << timestamp << "] ";
}

