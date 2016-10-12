#include <iostream> 

using namespace std; 

class account
{
	public:
	char *accountNum = new char[50];
	double interest;
	double bal;

	int display();
	virtual int deposit(double d);
	virtual int withdraw(double w);
};


int account::display()
{
	//display
	cout << "account number: " << accountNum << endl;
	cout << "interest: " << interest << '%' << endl;
	cout << "balance: " << bal << endl;

}
int account::deposit(double d)
{
	//deposit
	//double d; cout << "how much do you want to deposit" << endl; 
	//cin >> d;
	if (d < 0)
	{
		cout << "cant do that" << endl;
		return (-1);
	}
	else
	{
		bal+=d;
		return (0);
	}

}

int account::withdraw(double w)
{
	//withdraw
	//cout << "how much do you wnat to withdraw" << endl;
	//cin >> w;
	if (bal-w < 0)
	{
		cout << "get more money" << endl;
		return(-1);
	}
	else 
	{
		bal-=w;
		return(0);
	}
}

/*  PUT ALL SAVINGS SHIT HERE */
class savings: public account
{
	public:
	void checkaccount()
	{
		if (bal >= 10000)
		{
			interest = 2;
		}
		else 
		{
			interest = 1;
		}
	}
	void compound(int day)
	{
		if (day == 1)
		{
			bal = bal * (interest/100);
		}
	}
	virtual int withdraw(int w)
	{
		if (bal-w < 0)
		{
			cout << "get more money" << endl;
			return(-1);
		}
		else 
		{
			bal-=w;
			bal = bal - 2.0;
			return(0);
		}

	}
};
/*  CHEKCING SHIT */
class checking: public account
{
	//
};

/*THE OTHER ONE */
class cd: public account
{
	//
};

int main()
{
	savings mysave;
	mysave.bal = 23;
	cout << "initial";
	mysave.display();
	mysave.checkaccount();
	cout << "after check account";
	mysave.display();
	mysave.withdraw(5);
	cout << "after withdraw";
	mysave.display();

	
	/*
	account myAccount;
	myAccount.accountNum = "abcd";
	myAccount.bal = 5;
	myAccount.interest = 8;
	myAccount.display();
	myAccount.deposit();
	myAccount.display();
	myAccount.withdraw();
	myAccount.display();
	*/

}
