/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:39:28 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/26 13:11:31 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

void	print_timestamp(void)
{
	std::chrono::system_clock::time_point time_now;
	std::time_t time_to_print;

	time_now = std::chrono::system_clock::now();
	time_to_print = std::chrono::system_clock::to_time_t(time_now);
	std::cout << std::put_time(std::localtime(&time_to_print), "[%Y%m%d_%S%M%H]");
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	++Account::_nbAccounts;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts - 1;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	print_timestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return;
}

Account::~Account(void)
{
	print_timestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return;
}

void	Account::makeDeposit(int deposit)
{
	print_timestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	++this->_nbDeposits;
	++Account::_totalNbDeposits;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << ";deposits:" << deposit << ";amount:" << this->_amount;
	std::cout <<";nb_desposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool	autorisation;

	if (withdrawal > this->checkAmount())
		autorisation = false;
	else
		autorisation = true;
	print_timestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";withdrawal:";
	if (autorisation == true)
	{
		++this->_nbWithdrawals;
		++Account::_totalNbWithdrawals;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals;
	}
	else
		std::cout << "refused";
	std::cout << std::endl;
	return autorisation;
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	print_timestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	print_timestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
