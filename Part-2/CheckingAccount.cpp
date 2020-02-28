#include "CheckingAccount.h"

using namespace std;

	
// constructor initializes balance and transaction fee
CheckingAccount::CheckingAccount( double initialBalance, double fee ) : Account( initialBalance ) 
{
	if (fee<0)
		transactionFee=0;
	else
		transactionFee=fee;
} 

// credit (add) an amount to the account balance and charge fee
void CheckingAccount::credit( double amount )
{
	Account::credit(amount);
	chargeFee();
} 

// debit (subtract) an amount from the account balance and charge fee
bool CheckingAccount::debit( double amount )
{
	if (Account::debit(amount)){
		Account::debit(amount);
		chargeFee();
		return true;
	}
	else
		return false;
	
}

// subtract transaction fee
void CheckingAccount::chargeFee()
{
	setBalance(getBalance()-transactionFee);
}

void CheckingAccount::display(ostream & os) const
{
	
	os<<"Account type: Checking"<<endl;
	Account::display(cout);
	
	cout.setf(ios::fixed|ios::right);
	cout.precision(2);
	os<<"Transaction fee: "<<transactionFee<<endl;
}