#ifndef PREMIUMACCOUNT_H_INCLUDED
#define PREMIUMACCOUNT_H_INCLUDED
#include "Account.h"
#include <iomanip>
#include <iostream>

using namespace std;

class PremiumAccount : public Account
{
private:
   static int numberPremiumAccounts;
   static double MIN_BALANCE;
public:

   PremiumAccount(int number, string name, double amount):Account(number, name, amount)
   {
      numberPremiumAccounts++;
   }

   static int getNumberPremiumAccounts()
   {
      return numberPremiumAccounts;
   }

   // withdraws from account, takes amount. Update totalNetDeposits.
   void withdraw(double amount)
   {
      if(balance >= (amount + MIN_BALANCE))
      {
         balance -= amount;
         totalNetDeposits -= amount;
         cout << "New balance is " << fixed << setprecision(2) << balance << endl;
      }
      else
         cout << "You need to maintain a min balance of $" << fixed << setprecision(2) << MIN_BALANCE
         << ", withdrawal not executed" << endl;
   }

   // returns minimum balance
   static double getMinBalance()
   {
      return MIN_BALANCE;
   }
};

#endif // PREMIUMACCOUNT_H_INCLUDED
