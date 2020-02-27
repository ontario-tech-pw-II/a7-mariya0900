## Inheritance program

Learning outcomes highlights: 
- know how to derive from a base class
- undertand the overriding 

**Problem:** The Account class is designed to represent customers’ bank accounts (base class). It includes a data member (of type double) to represent the account balance. This class provides a constructor that receives an initial balance and uses it to initialize the data member. 

# Account Class
## Account.h 
```C++
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;
   
class Account{
	private:
		double balance; // data member that stores the balance

	protected:
		double getBalance() const; // return the account balance
		void setBalance( double ); // sets the account balance

		public:
		Account( double = 0.0); // constructor initializes balance
	
		virtual void credit(double);

		virtual bool debit(double);

		virtual void display(ostream &) const; 					
};

#endif
```
## Account.cpp 
```C++
#include "Account.h"

using namespace std;

Account::Account( double initialBalance)
{
	if( initialBalance >= 0.0 )
		balance = initialBalance;
	else 
		balance = 0.0;
}	

//credit (add) an amount to the account balance
void Account::credit( double amount )
{
	balance = balance + amount; 
} 

//debit (subtract) an amount from the account balance return bool indicating whether money was debited
bool Account::debit( double amount )
{
	if ( amount > balance ){
		return false;
	} else{
		balance = balance - amount;
		return true;
	}
}

double Account::getBalance() const
{
	return balance;
} 

void Account::setBalance( double newBalance )
{
	balance = newBalance;
} 

void Account::display(ostream & out) const
{
	out << "None " << endl;
} 					
```
# Part1: SavingAccount Class
Derived class SavingsAccount that inherits the functionality of an Account, but also include a data member of type double indicating the interest rate (for example 0.12) assigned to the Account (interestRate). 
* Write the SavingsAccount’s constructor that receives the initial balance, as well as an initial value for the SavingsAccount’s interest rate, and then initializes the object. If interest rate is less than zero, the interestRate will be set to zero. 
* Override the display function in the Account class that prints a SavingsAccount in the following format (this is an example):
```C++
Account type: Saving
Balance: $ 400.00
Interest Rate (%): 12.00
```
# Part2: CheckingAccount Class
Derive class CheckingAccount that inherits from base class Account and include an additional data member of type double that represents the fee charged per transaction (transactionFee). 
* Write CheckingAccount’s constructor that receives the initial balance, as well as a parameter indicating a transaction fee amount. If transaction fee is less than zero, the transactionFee will be set to zero. 
* Write the chargeFee member function that updates the balance by deducting the transactionFee from the balance. 
Override member functions debit for class CheckingAccount so that it subtracts the transactionFee from the account balance (call chargeFee). If the operation is successful, it will return true otherwise it does nothing and will return false (debit is successful if the amount is not greater than the balance). CheckingAccount’s versions of this function should invoke the base-class Account version to perform the debit operation.
  * Hint: Define Account’s debit function so that it returns a bool indicating whether money was withdrawn. Then use the return value to determine whether a fee should be charged.
* Override member functions credit for class CheckingAccount so that it subtracts the transactionFee from the account balance (call chargeFee). CheckingAccount’s versions of this function should invoke the base-class Account version to perform the credit operation. 
* Override the display function in the Account class that prints a CheckingAccount in the following format (example):
```C++
Account type: Checking
Balance: $ 400.00
Transaction Fee: 1.00
```
