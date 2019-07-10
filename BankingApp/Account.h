#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include <string>

using namespace std;

class Account
{
private:
   int accountNumber;
   string ownerName;
   static int numberAccounts;
protected:
   double balance;
   static double totalNetDeposits;
public:
   Account(int, string, double);
   void withdraw(double);
   void deposit(double);
   int getAccountNumber() const;
   string getName() const;
   double getBalance() const;
   static double getTotalNetDeposit();
   static int getNumberAccounts();
   void print() const;
}; // end class Account

#endif // ACCOUNT_H_INCLUDED
