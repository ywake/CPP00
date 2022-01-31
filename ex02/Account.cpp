/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:46:52 by ywake             #+#    #+#             */
/*   Updated: 2022/01/31 14:48:29 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <iomanip>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( void )
{

}

// [19920104_091532] index:0;amount:42;created
Account::Account( int initial_deposit ) :
  _accountIndex(_nbAccounts),
  _amount(initial_deposit),
  _nbDeposits(0),
  _nbWithdrawals(0)
{
  _displayTimestamp();
  std::cout
    << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";"
    << "created" << std::endl;
  _nbAccounts++;
  _totalAmount += _amount;
}

// index:0;amount:47;closed
Account::~Account( void )
{
  _displayTimestamp();
  std::cout
    << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";"
    << "closed" << std::endl;
}

int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
  _displayTimestamp();
  std::cout
    << "accounts:" << _nbAccounts << ";"
    << "total:" << _totalAmount << ";"
    << "deposits:" << _totalNbDeposits << ";"
    << "withdrawals:" << _totalNbWithdrawals
    << std::endl;
}


// index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
  _displayTimestamp();
  std::cout
    << "index:" << _accountIndex << ";"
    << "p_amount:" << _amount << ";"
    << "deposit:" << deposit << ";";

  _amount += deposit;
  _nbDeposits++;
  _totalAmount += deposit;
  _totalNbDeposits++;

  std::cout
    << "amount:" << _amount << ";"
    << "nb_deposits:" << _nbDeposits
    << std::endl;
}

// index:0;p_amount:47;withdrawal:refused
// index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
  bool isSuccess = false;

  _displayTimestamp();
  std::cout
    << "index:" << _accountIndex << ";"
    << "p_amount:" << _amount << ";";

  if (_amount > withdrawal) {
    isSuccess = true;
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
  }

  if (isSuccess) {
    std::cout
      << "withdrawal:" << withdrawal << ";"
      << "amount:" << _amount << ";"
      << "nb_withdrawals:" << _nbWithdrawals
      << std::endl;
  } else {
    std::cout << "withdrawal:refused" << std::endl;
  }

  return isSuccess;
}

int	Account::checkAmount( void ) const
{
  return 0;
}

// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
  _displayTimestamp();
  std::cout
    << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";"
    << "deposits:" << _nbDeposits << ";"
    << "withdrawals:" << _nbWithdrawals
    << std::endl;
}

// [19920104_091532]
void	Account::_displayTimestamp( void )
{
  time_t now = std::time(NULL);
  const tm* localTime = localtime(&now);
  std::cout
    << "["
    << localTime->tm_year + 1900
    << std::setw(2) << std::setfill('0') << localTime->tm_mon + 1
    << std::setw(2) << std::setfill('0') << localTime->tm_mday
    << "_"
    << std::setw(2) << std::setfill('0') << localTime->tm_hour
    << std::setw(2) << std::setfill('0') << localTime->tm_min
    << std::setw(2) << std::setfill('0') << localTime->tm_sec
    << "] ";
}
