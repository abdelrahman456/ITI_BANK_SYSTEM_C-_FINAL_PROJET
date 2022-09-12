#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include "Account.h"
using namespace std;
#define MIN_BALANCE 100
class deficient_funds{};
long Cl_Accounts::Nxt_Accnt_No=0;

Cl_Accounts::Cl_Accounts(string fname,string lname,float client_balance)
{
	Nxt_Accnt_No++;
	Accnt_No=Nxt_Accnt_No;
	client_fname=fname;
	client_lname=lname;
	this->client_balance=client_balance;
}

void Cl_Accounts::Deposit(float amt)
{
	client_balance+=amt;
}


void Cl_Accounts::Withdraw(float amt)
{
	if(client_balance-amt<MIN_BALANCE)
		throw deficient_funds();
		client_balance-=amt;
}

void Cl_Accounts::setLstAccntNo(long Accnt_No)
{
	Nxt_Accnt_No=Accnt_No;
}


long Cl_Accounts::getLstAccntNo()
{
  return Nxt_Accnt_No;
}


ofstream & operator<<(ofstream &ofs,Cl_Accounts &acc)
{
	ofs<<acc.Accnt_No<<endl;
	ofs<<acc.client_fname<<endl;
	ofs<<acc.client_lname<<endl;
	ofs<<acc.client_balance<<endl;
	return ofs;
}


ifstream & operator>>(ifstream &ifs,Cl_Accounts &acc)
{
   ifs>>acc.Accnt_No;
   ifs>>acc.client_fname;
   ifs>>acc.client_lname;
   ifs>>acc.client_balance;
   return ifs;
}


ostream & operator<<(ostream &os,Cl_Accounts &acc)
{
   os<<"First Name:"<<acc.getFName()<<endl;
   os<<"Last Name:"<<acc.getLName()<<endl;
   os<<"Account Number:"<<acc.getAccNo()<<endl;
   os<<"Balance:"<<acc.getBlnce()<<endl;
   return os;
}