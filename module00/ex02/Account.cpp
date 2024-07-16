
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
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account() 
{
    return;
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
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
    //FINISH THIS
}

bool    Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal <= _amount)
    {
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        return(true);
    }
    else
        return(false);
    // ADD PTINTS FOR THIS AND CHECK AND CHANGE THE NUMBERS LIKE REMOVE THE WOTHDRAWAL MONEY FROM THE AMOUNT EETC
}

void    Account::_displayTimestamp(void)
{
    //CHANGE THIS FUNCTION !!!
}

int Account::checkAmount(void) const
{
    return(_amount);
}

void    Account::displayStatus(void) const
{

}

void    Account::displayAccountsInfos(void)
{

}