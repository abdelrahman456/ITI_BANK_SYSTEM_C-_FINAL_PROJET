

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
#define MIN_BALANCE 100
#ifndef _Account_H
#define _Account_H

/*Accnt_No*/



class Cl_Accounts
{
	
 private:

	long Accnt_No;
	string client_fname;
	string client_lname;
	float client_balance;
	static long Nxt_Accnt_No;

 public:

	Cl_Accounts(){}
	Cl_Accounts(string fname,string lname,float client_balance);
	long getAccNo(){return Accnt_No;}
	string getFName(){return client_fname;}
	string getLName(){return client_lname;}
	float getBlnce(){return client_balance;}
	void Deposit(float amount);
	void Withdraw(float amount);
	static void setLstAccntNo(long Accnt_No);
	static long getLstAccntNo();
	friend ofstream & operator<<(ofstream &ofs,Cl_Accounts &acc);
	friend ifstream & operator>>(ifstream &ifs,Cl_Accounts &acc);
	friend ostream & operator<<(ostream &os,Cl_Accounts &acc);
	
};


#endif