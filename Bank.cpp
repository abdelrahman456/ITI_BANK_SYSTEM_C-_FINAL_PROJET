#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include "Account.h"
#include "Bank.h"
//#include "file.c"
using namespace std;
#define MIN_BALANCE 100

class deficient_funds{};


/*bank construct*/
Bank::Bank()
{
   Cl_Accounts acnt;
   ifstream infile;
   infile.open("Bank.data");
   if(!infile)
{
//cout<<"Error in Opening! File Not Found!!"<<endl;
	return;
}
while(!infile.eof())
{
   infile>>acnt;
   accounts_cl.insert(pair<long,Cl_Accounts>(acnt.getAccNo(),acnt));
}
	Cl_Accounts::setLstAccntNo(acnt.getAccNo());
	infile.close();
}

/*open account*/
Cl_Accounts Bank::Cl_Open_Account(string fname,string lname,float balance)
{
	ofstream outfile;
	Cl_Accounts acnt(fname,lname,balance);
	accounts_cl.insert(pair<long,Cl_Accounts>(acnt.getAccNo(),acnt));
	outfile.open("Bank.data", ios::trunc);
	map<long,Cl_Accounts>::iterator itr;
for(itr=accounts_cl.begin();itr!=accounts_cl.end();itr++)
{
	outfile<<itr->second;
}
	outfile.close();
	return acnt;
}

/*Balance_Enquiry*/
Cl_Accounts Bank::Cl_Balance_Enquiry(long Accnt_No)
{
	map<long,Cl_Accounts>::iterator itr=accounts_cl.find(Accnt_No);
	return itr->second;
}


Cl_Accounts Bank::Deposit(long Accnt_No,float amt)
{
    map<long,Cl_Accounts>::iterator itr=accounts_cl.find(Accnt_No);
	itr->second.Deposit(amt);
	return itr->second;
}


Cl_Accounts Bank::Withdraw(long Accnt_No,float amt)
{
	map<long,Cl_Accounts>::iterator itr=accounts_cl.find(Accnt_No);
	itr->second.Withdraw(amt);
	return itr->second;
}

void Bank::CloseAccount(long Accnt_No)
{
	/*colse account*/
	map<long,Cl_Accounts>::iterator itr=accounts_cl.find(Accnt_No);

	cout<<"Account Deleted"<<itr->second;
	accounts_cl.erase(Accnt_No);
}

void Bank::ShowAllAccounts()
{
	map<long,Cl_Accounts>::iterator itr;

for(itr=accounts_cl.begin();itr!=accounts_cl.end();itr++)
 {
	cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
 }

 }

/*bank distructor*/
Bank::~Bank()
{
	ofstream outfile;
	outfile.open("Bank.txt", ios::trunc);
	map<long,Cl_Accounts>::iterator itr;

for(itr=accounts_cl.begin();itr!=accounts_cl.end();itr++)
{
	outfile<<itr->second;
}
	/*close file*/
	outfile.close();
	
}
