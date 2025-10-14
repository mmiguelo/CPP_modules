#include "../Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account( int initial_deposit ) :_amount(initial_deposit) , _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = this->_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " " << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return ;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	Account::_nbAccounts--;
	std::cout << " " << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

//Getters
int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

int Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
	<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount << ";deposit:" << deposit ;

	this->_amount += deposit;
	this->_nbDeposits++;

	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount
	<< ";withdrawal:";

	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	_totalAmount -=withdrawal;
	this->_totalNbWithdrawals++;

	std::cout << withdrawal << ";amount:" << this->_amount
	<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

void    Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposit:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(NULL);
	std::tm *tm = std::localtime(&t);

	std::cout << '['
	<< std::setw(4) << std::setfill('0') << (tm->tm_year + 1900)
	<< std::setw(2) << std::setfill('0') << (tm->tm_mon + 1)
	<< std::setw(2) << std::setfill('0') << tm->tm_mday << '_'
	<< std::setw(2) << std::setfill('0') << tm->tm_hour
	<< std::setw(2) << std::setfill('0')  << tm->tm_min
	<< std::setw(2) << std::setfill('0') << tm->tm_sec
	<< ']' ;
}