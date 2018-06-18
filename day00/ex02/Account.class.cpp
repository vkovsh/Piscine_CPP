/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:36:29 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/18 14:36:30 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <ctime>
#include <iostream>

//static fields
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//static getters
int		Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int		Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

//static methods
void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t t = std::time(0);
	std::tm	*now = std::localtime(&t);
	std::cout << "[" << 1900 + now->tm_year;
	if (now->tm_mon < 10)
		std::cout << "0";
	std::cout << now->tm_mon;
	if (now->tm_mday < 10)
		std::cout << "0";
	std::cout << now->tm_mday;
	std::cout << "_";
	if (now->tm_hour < 10)
		std::cout << "0";
	std::cout << now->tm_hour;
	if (now->tm_min < 10)
		std::cout << "0";
	std::cout << now->tm_min;
	if (now->tm_sec < 10)
		std::cout << "0";
	std::cout << now->tm_sec << "] ";
}

//dynamic methods
void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl; 
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	(this->_nbDeposits)++;
	(Account::_totalNbDeposits)++;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (this->_amount >= withdrawal) {
		(this->_nbWithdrawals)++;
		(Account::_totalNbWithdrawals)++;
		this->_amount  -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	else {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	return (true);
}

//constructors
Account::Account( int initial_deposit ): _amount(initial_deposit) {
	Account::_displayTimestamp();
	this->_accountIndex = (Account::_nbAccounts);
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	(Account::_nbAccounts)++;
	(Account::_totalAmount) += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

//destructors
Account::~Account( void ) {
	Account::_displayTimestamp();
	(Account::_nbAccounts)--;
	(Account::_totalAmount) -= this->_amount;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}
