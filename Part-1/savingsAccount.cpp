#include "SavingsAccount.h"
#include <iomanip>
using namespace std;

// constructor initializes balance and interest rate
SavingsAccount::SavingsAccount( double initialBalance, double rate ) : Account( initialBalance ) 
{
	if (rate<0)
		interestRate=0.0;
	else
		interestRate=rate;
}

double SavingsAccount::calculateInterest(){
	return getBalance()*interestRate;
} 
void SavingsAccount::display(ostream & os) const
{
	cout.setf(ios::fixed|ios::right);
	cout.precision(2);
	
	os<<"Account type: Saving"<<endl;
	
	Account::display(cout);
	
	os<<"Interest rate (%): "<<interestRate*100<<endl;
	
}