#include "Account.h"
#include "RegularAccount.h"
#include "PremiumAccount.h"
#include <iostream>
#include <iomanip>

double Account::totalNetDeposits = 0; // initialize to 0
int Account::numberAccounts = 0; // initialize to 0
int RegularAccount::numberRegularAccounts = 0;
int PremiumAccount::numberPremiumAccounts = 0; // initialize to 0
double PremiumAccount::MIN_BALANCE = 1000; // initialize to 1000

// initialized account constructor, takes account number, name, and amount. Update totalNetDeposits. Increment numberAccounts.
Account::Account(int number, string name, double amount)
{
   accountNumber = number;
   ownerName = name;
   balance = amount;
   totalNetDeposits += amount;
   numberAccounts++;
}

// withdraws from account, takes amount. Update totalNetDeposits.
void Account::withdraw(double amount)
{
   balance -= amount;
   totalNetDeposits -= amount;
   cout << "New balance is " << fixed << setprecision(2) << balance << endl;
}

// deposits to account, takes amount. Update totalNetDeposits.
void Account::deposit(double amount)
{
   balance += amount;
   totalNetDeposits += amount;
   cout << "New balance is " << fixed << setprecision(2) << balance << endl;
}

// returns account number
int Account::getAccountNumber() const
{
   return accountNumber;
}

// returns balance
double Account::getBalance() const
{
   return balance;
}

// returns totalNetDeposits
double Account::getTotalNetDeposit()
{
   return totalNetDeposits;
}

// returns numberAccounts
int Account::getNumberAccounts()
{
   return numberAccounts;
}

// prints accountNumber, ownerName, balance
void Account::print() const
{
   cout << "Number: " << setw(7) << accountNumber;
   cout << ", Name: " << setw(10) << ownerName;
   cout << ", Balance: " << setw(7) << setprecision(2) << balance << endl;
}
