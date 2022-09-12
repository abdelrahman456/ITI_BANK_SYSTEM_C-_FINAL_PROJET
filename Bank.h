
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
#define MIN_BALANCE 100

#ifndef _Bank_H
#define _Bank_H




class Bank
{
	
 private:

		map<long,Cl_Accounts> accounts_cl;

 public:

	Bank();

	Cl_Accounts Cl_Open_Account(string fname,string lname,float balance);
	Cl_Accounts Cl_Balance_Enquiry(long Account_no);
	Cl_Accounts Deposit(long Account_no,float amt);
	Cl_Accounts Withdraw(long Account_no,float amt);
	void CloseAccount(long Account_no);
	void ShowAllAccounts();
	~Bank();
	
};

#endif