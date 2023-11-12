#include "Account.hpp"
#include <ctime>
#include <iostream>

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccount;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithDrawals = 0;

	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp(); 
	std::cout << ' ';
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp(); 
	std::cout << ' ';
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithDrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = _amount;

	_amount += deposit;
	_nbDeposits++;
}

int	Account::checkAmount(void)
{
	return (_amount);
}

static void	Account::displayAccountsInfos(void)
{
	_displayTimestamp(); 
	std::cout << ' ';
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals << std::endl;
}

static int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

static int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

static int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

static int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

static void	Account::_displayTimestamp(void)
{
	std::time_t	time = std::time(NULL);
	std::tm		localTime;
	char		timeText[30];

	std::localtime_r(&time, &localTime);
	strftime(timeText, 30, "[%Y%m%d_%H%M%S]", &localTime);
	std::cout << timeText;
}
