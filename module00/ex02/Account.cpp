
#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <cctype> 
#include <cstdlib> 
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _nbAccounts++;
	_totalAmount += initial_deposit;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex - 1
              << ";amount:" << _amount 
              << ";created" << std::endl;
}

Account::Account() 
{
    return;
}

Account::~Account( void ) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex - 1
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
    _nbAccounts--;
}

int Account::getNbAccounts(void)
{
    return(_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return(_totalAmount);
}

int Account::getNbDeposits(void)
{
    return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return(_totalNbWithdrawals);
}

void    Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex - 1
              << ";p_amount:" << _amount - deposit 
              << ";deposit:" << deposit 
              << ";amount:" << _amount 
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal <= _amount)
    {
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _amount -= withdrawal;
        _totalAmount -=withdrawal;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex - 1
                  << ";p_amount:" << _amount + withdrawal 
                  << ";withdrawal:" << withdrawal 
                  << ";amount:" << _amount
                  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return(true);
    }
    else
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex - 1
                  << ";p_amount:" << _amount 
                  << ";withdrawal:refused" << std::endl;
        return(false);
    }
}

void    Account::_displayTimestamp(void)
{
    std::time_t curtime = std::time(0);
    std::cout << std::setfill('0') 
              << "[" << 1900 + std::localtime(&curtime)->tm_year
              << std::setw(2) << std::localtime(&curtime)->tm_mday 
              << "_"
              << std::setw(2) << std::localtime(&curtime)->tm_hour
              << std::setw(2) << std::localtime(&curtime)->tm_min
              << std::setw(2) << std::localtime(&curtime)->tm_sec
              << "] " << std::flush;
}

int Account::checkAmount(void) const
{
    return(_amount);
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex - 1
              << ";amount:" << _amount << ";deposits:" 
              << _nbDeposits << ";withdrawals:" 
              << _nbWithdrawals << std::endl;

}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount << ";deposits:" 
              << _totalNbDeposits << ";withdrawals:" 
              << _totalNbWithdrawals << std::endl;
}