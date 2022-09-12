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












int main()
{
	
	Bank b;
	Cl_Accounts acc;
	int option, input, PASSWORD = 1234;
	string fname,lname;
	long account_no;
	float blnced;
	float amnts;
	int j=0;
	cout<<"***Bank Management System***"<<endl;
do
{ 

        cout<<"\n\tSelect One Option Below ";
		cout<<"\n\t1 ADMIN MODE";
		cout<<"\n\t2 USER MODE";
		cout<<"\n\t0 Quit";
	
	    cin>>input;

switch(input)
{ 





	case 1:
	    cout<<"\n\tENTER YOUR PASSWORD: ";
		cin>>PASSWORD;
		if(PASSWORD==1234){
		cout<<"\n\tSelect One Option Below ";
		cout<<"\n\t1 Open an Account";
		cout<<"\n\t2 Balance Enquiry";
		cout<<"\n\t3 Deposit";
		cout<<"\n\t4 Withdrawal";
		cout<<"\n\t5 Close an Account";
		cout<<"\n\t6 Show All Accounts";
		cout<<"\n\t7 Quit";
		cout<<"\nEnter your choice: ";
		cin>>option;
	

switch(option)
{
	
case 1:
	cout<<"Enter First Name: ";
	cin>>fname;
	cout<<"Enter Last Name: ";
	cin>>lname;
	cout<<"Enter Initial Balance: ";
	cin>>blnced;
	acc=b.Cl_Open_Account(fname,lname,blnced);
	cout<<endl<<"Congratulations Account is Created"<<endl;
	cout<<acc;
break;

case 2:
	cout<<"Enter Account Number:";
	cin>>account_no;
	acc=b.Cl_Balance_Enquiry(account_no);
	cout<<endl<<"Your Account Details"<<endl;
	cout<<acc;
break;

case 3:
	cout<<"Enter Account Number:";
	cin>>account_no;
	cout<<"Enter Balance:";
	cin>>amnts;
	acc=b.Deposit(account_no, amnts);
	cout<<endl<<"Amount is Deposited"<<endl;
	cout<<acc;
break;

case 4:
	cout<<"Enter Account Number:";
	cin>>account_no;
	cout<<"Enter Balance:";
	cin>>amnts;
	acc=b.Withdraw(account_no, amnts);
	cout<<endl<<"Amount Withdrawn"<<endl;
	cout<<acc;
break;

case 5:
	cout<<"Enter Account Number:";
	cin>>account_no;
	b.CloseAccount(account_no);
	cout<<endl<<"Account is Closed"<<endl;
	cout<<acc;
	break;
case 6:
	b.ShowAllAccounts();
	break;
	
case 7: 	break;

default:
	cout<<"\nEnter corret choice";
	exit(0);
}


}else{
	while (PASSWORD!=1234){
	cout<<"\nWrong PASSWORD";
	cout<<"\nEnter corret PASSWORD";
	++j;
	cin>>PASSWORD;
	if(j==3){
		cout<<"\nWrong PASSWORD for Three Times";
		cout<<"\nEXIT";
		j=0;
		break;
		exit(0);
		
	}
	
	}
	}
	break;
	case 2 :
	    cout<<"\n\tSelect One Option Below ";
	    cout<<"\n\t2 Balance Enquiry";
		cout<<"\n\t3 Deposit";
		cout<<"\n\t4 Withdrawal";
		cin>>option;
		switch(option)
        {
			
			
		case 2:
			cout<<"Enter Account Number:";
			cin>>account_no;
			acc=b.Cl_Balance_Enquiry(account_no);
			cout<<endl<<"Your Account Details"<<endl;
			cout<<acc;
			break;
	
	     case 3:
			cout<<"Enter Account Number:";
			cin>>account_no;
			cout<<"Enter Balance:";
			cin>>amnts;
			acc=b.Deposit(account_no, amnts);
			cout<<endl<<"Amount is Deposited"<<endl;
			cout<<acc;
			break;

		case 4:
			cout<<"Enter Account Number:";
			cin>>account_no;
			cout<<"Enter Balance:";
			cin>>amnts;
			acc=b.Withdraw(account_no, amnts);
			cout<<endl<<"Amount Withdrawn"<<endl;
			cout<<acc;
			break;
	
	
	
	
	
	
        }
	
	
	break;
	
	default:
	cout<<"\nEnter corret choice";
	exit(0);
}
}while(option!=7);


	return 0;
}






