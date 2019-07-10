#ifndef REGULARACCOUNT_H_INCLUDED
#define REGULARACCOUNT_H_INCLUDED
#include "Account.h"

using namespace std;

class RegularAccount : public Account
{
private:
   static int numberRegularAccounts;
public:

   RegularAccount(int number, string name, double amount):Account(number, name, amount)
   {
      numberRegularAccounts++;
   }

   static int getNumberRegularAccounts()
   {
      return numberRegularAccounts;
   }
};

#endif // REGULARACCOUNT_H_INCLUDED
