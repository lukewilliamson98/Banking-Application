/*
Author: Luke Williamson
Compiler: GNU GCC
Date: 4/16/2017
Purpose of program: Lets user create, deposit to, and withdraw from multiple types of bank accounts.
*/

#include <iostream>
#include <cstdlib>
#include "Account.h"
#include "RegularAccount.h"
#include "PremiumAccount.h"

using namespace std;

const int NUM_REGULAR_ACCOUNT = 5;
const int NUM_PREMIUM_ACCOUNT = 5;
RegularAccount * regularAccountArray[NUM_REGULAR_ACCOUNT];
PremiumAccount * premiumAccountArray[NUM_PREMIUM_ACCOUNT];

int main()
{
   int choice; // user choice
   int regCount = 0, premCount = 0; // counts number of instances
   do
   {
      int acc; // user entered account number
      string name; // user entered name
      double bal, dAmt, wAmt; // user entered balance, deposit amount, and withdraw amount
      bool found = 0; // truth value for searching
      int loc; // value in array if found during search
      cout << "\n1 - Create regular account\n";
      cout << "2 - Create premium account\n";
      cout << "3 - Deposit to regular account\n";
      cout << "4 - Deposit to premium account\n";
      cout << "5 - Withdraw from regular account\n";
      cout << "6 - Withdraw from premium account\n";
      cout << "7 - Display information for all accounts\n";
      cout << "8 - Get total net deposits\n";
      cout << "9 - Exit\n\n";
      cin >> choice; // get user choice
      if(((choice == 1) && (regCount >= NUM_REGULAR_ACCOUNT)) || ((choice == 2) && (premCount >= NUM_PREMIUM_ACCOUNT)))
         cout << "Max number of accounts reached, cannot add a new account\n";  // max accounts check
      else if(choice == 1) // create new regular account
      {
         cout << "Enter account number: ";
         cin >> acc; // get account number
         for(int j = 0; j < 5; j++) // search
         {
            if(regularAccountArray[j])
               if(regularAccountArray[j]->getAccountNumber() == acc)
               {
                  found = 1;
                  loc = j;
               }
         } // end search
         if(found) // if account exists
         {
            cout << "This account number already exists.\n";
         }
         else // if account does not exist
         {
            cout << "Enter owner's name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter amount: ";
            cin >> bal;
            regularAccountArray[regCount] = new RegularAccount(acc, name, bal); // dynamically allocate RegularAccount object
            regCount++; // increase number of regular accounts
         } // end conditional
      } // end choice 1 condition
      else if(choice == 2) // create new premium account
      {
         cout << "Enter account number: ";
         cin >> acc; // get account number
         for(int j = 0; j < 5; j++) // search
         {
            if(premiumAccountArray[j])
               if(premiumAccountArray[j]->getAccountNumber() == acc)
               {
                  found = 1;
                  loc = j;
               }
         } // end search
         if(found) // if account exists
         {
            cout << "This account number already exists.\n";
         }
         else // if account does not exist
         {
            cout << "Enter owner's name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter amount: ";
            cin >> bal;
            premiumAccountArray[premCount] = new PremiumAccount(acc, name, bal); // dynamically allocate PremiumAccount object
            premCount++; // increase number of premium accounts
         } // end conditional
      } // end choice 2 condition
      else if (choice == 3) // deposit to regular
      {
         cout << "Enter account number: ";
         cin >> acc;
         for(int j = 0; j < 5; j++) // search
         {
            if(regularAccountArray[j])
               if(regularAccountArray[j]->getAccountNumber() == acc)
               {
                  found = 1;
                  loc = j;
               }
         } // end search
         if(found) // if account exists
         {
            cout << "Enter amount: ";
            cin >> dAmt; // get amount
            if(dAmt < 0)
               cout << "Deposit amount cannot be negative, deposit not executed\n";
            else
               regularAccountArray[loc]->deposit(dAmt); // stores new balance
         } // end if found
         else
            cout << "No such account\n";
      } // end choice 3 condition
      else if (choice == 4) // deposit to premium
      {
         cout << "Enter account number: ";
         cin >> acc;
         for(int j = 0; j < 5; j++) // search
         {
            if(premiumAccountArray[j])
               if(premiumAccountArray[j]->getAccountNumber() == acc)
               {
                  found = 1;
                  loc = j;
               }
         } // end search
         if(found) // if account exists
         {
            cout << "Enter amount: ";
            cin >> dAmt; // get amount
            if(dAmt < 0)
               cout << "Deposit amount cannot be negative, deposit not executed\n";
            else
               premiumAccountArray[loc]->deposit(dAmt); // stores new balance
         } // end if found
         else
            cout << "No such account\n";
      } // end choice 4 condition
      else if(choice == 5) // withdraw from regular
      {
         cout << "Enter account number: ";
         cin >> acc;
         for(int j = 0; j < 5; j++) // search
         {
            if(regularAccountArray[j])
               if(regularAccountArray[j]->getAccountNumber() == acc)
               {
                  found = 1;
                  loc = j;
               }
         } // end search
         if(found) // if account exists
         {
            cout << "Enter amount: ";
            cin >> wAmt; // get amount
            if(wAmt > regularAccountArray[loc]->getBalance()) // if amount exceeds balance
               cout << "Insufficient balance, withdrawal not executed\n";
            else
               regularAccountArray[loc]->withdraw(wAmt); // stores new balance
         }
         else
            cout << "No such account\n";
      } // end choice 5 condition
      else if(choice == 6) // withdraw from premium
      {
         cout << "Enter account number: ";
         cin >> acc;
         for(int j = 0; j < 5; j++) // search
         {
            if(premiumAccountArray[j])
               if(premiumAccountArray[j]->getAccountNumber() == acc)
               {
                  found = 1;
                  loc = j;
               }
         } // end search
         if(found) // if account exists
         {
            cout << "Enter amount: ";
            cin >> wAmt; // get amount
            if(wAmt > premiumAccountArray[loc]->getBalance()) // if amount exceeds balance
               cout << "Insufficient balance, withdrawal not executed\n";
            else
               premiumAccountArray[loc]->withdraw(wAmt); // stores new balance
         }
         else
            cout << "No such account\n";
      } // end choice 6 condition
      else if(choice == 7) // display account info
      {
         int j = 0; // counter
         cout << "Regular Accounts\n================\n";
         while(regularAccountArray[j]) // while regular account exists
         {
            regularAccountArray[j]->print(); // print function
            j++; // increment counter
         }
         int k = 0; // counter
         cout << "Premium Accounts\n================\n";
         while(premiumAccountArray[k]) // while regular account exists
         {
            premiumAccountArray[k]->print(); // print function
            k++; // increment counter
         }
      } // end choice 7 condition
      else if(choice == 8) // display total net deposits
         cout << "Total net deposits: " << setprecision(2) << Account::getTotalNetDeposit() << endl;
      else if(choice == 9) // quit program
         exit(1); // successful exit
   } // end do-while loop
   while(choice != 6); // condition for looping
   return 0;
}
