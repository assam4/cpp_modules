#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

// statics initialization
int    Account::_nbAccounts = 0;
int    Account::_totalAmount = 0;
int    Account::_totalNbDeposits = 0;
int    Account::_totalNbWithdrawals = 0;

// time_format
static const int      Buffer_size = 19;
// For general info
static const std::string  Accs = "accounts:";
static const std::string  Total = "total:";
static const std::string  Deposits = "deposits:";
static const std::string  Withdrawals = "withdrawals:";
static const char      Separator = ';';
// For single info
static const std::string  Index = "index:";
static const std::string  Amount = "amount:";
static const std::string  Created = "created";
static const std::string  Closed = "closed";
static const std::string  Pamount = "p_amount:";
static const std::string  Deposit = "deposit:";
static const std::string  Nbdeposits = "nb_deposits:";
static const std::string  Withdrawal = "withdrawal:";
static const std::string  Refused = "refused";
static const std::string  Nbwithdrawals = "nb_withdrawals:";

int  Account::getNbAccounts() {
  return Account::_nbAccounts;
}


int Account::getTotalAmount() {
  return Account::_totalAmount;
}

int Account::getNbDeposits() {
  return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals() {
  return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
  Account::_displayTimestamp();
  std::cout << Accs << Account::_nbAccounts << Separator
        << Total << Account::_totalAmount << Separator
        << Deposits << Account::_totalNbDeposits << Separator
        << Withdrawals << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int init_dep) {
  this->_accountIndex = Account::_nbAccounts++;
  this->_amount = init_dep;
  Account::_totalAmount += this->_amount;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  Account::_displayTimestamp();
  std::cout << Index << this->_accountIndex << Separator
        << Amount << this->_amount << Separator
        << Created << std::endl;
}

Account::~Account() {
  Account::_displayTimestamp();
  std::cout << Index << this->_accountIndex << Separator
        << Amount << this->_amount << Separator
        << Closed << std::endl;
  --Account::_nbAccounts;
  Account::_totalAmount -= this->_amount;
}

void  Account::makeDeposit(int deposit) {
  ++this->_nbDeposits;
  ++Account::_totalNbDeposits;
  Account::_totalAmount += deposit;
  Account::_displayTimestamp();
  std::cout << Index << this->_accountIndex << Separator
        << Pamount << this->_amount << Separator
        << Deposit << deposit << Separator;
  this->_amount += deposit;
  std::cout << Amount << this->_amount << Separator
        << Nbdeposits << this->_nbDeposits << std::endl;
}

bool  Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();
  if (this->_amount < withdrawal) {
    std::cout << Index << this->_accountIndex << Separator
        << Pamount << this->_amount << Separator
        << Withdrawal << Refused << std::endl;
    return false;
  }
  ++this->_nbWithdrawals;
  ++Account::_totalNbWithdrawals;
  Account::_totalAmount -= withdrawal;
  this->_amount -= withdrawal;
  std::cout << Index << this->_accountIndex << Separator
        << Pamount << this->_amount + withdrawal << Separator
        << Withdrawal << withdrawal << Separator
        << Amount << this->_amount << Separator
        << Nbwithdrawals << this->_nbWithdrawals << std::endl;
  return true;
}

int    Account::checkAmount() const {
  return this->_amount;
}

void  Account::displayStatus() const {
  Account::_displayTimestamp();
  std::cout << Index << this->_accountIndex << Separator
    << Amount << this->_amount << Separator
    << Deposits << this->_nbDeposits << Separator
    << Withdrawals << this->_nbWithdrawals << std::endl;
}

void  Account::_displayTimestamp() {
  std::time_t  now = std::time(NULL);
  std::tm    *tinfo = std::localtime(&now);

  char buffer[Buffer_size];
  std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", tinfo);
  std::cout << buffer;
}
