#include <iostream> 

using namespace std; 

class account
{
	public:
	int day;
	const char *accountNum = new char[50];
	const char *accountType = new char[50];
	double interest = 0 ;
	double bal = 0 ;

	void display();
	virtual int deposit(double d);
	virtual int withdraw(double w);
};


void account::display()
{
	//display
	cout << endl;
	cout << "account type: " << accountType << endl;
	cout << "account number: " << accountNum << endl;
	cout << "interest: " << interest << '%' << endl;
	cout << "balance: " << bal << endl;

}
int account::deposit(double d)
{
	//deposit
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
	savings()
	{
		accountType="savings"; }
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
			checkaccount();
		}
	}
	int deposit(double d)
	{
		account::deposit(d);
		checkaccount();
		return (0);

	}
	int withdraw(double w)
	{
		account::withdraw(w);
		checkaccount(); 
		return (0);
	}
};
/*  CHEKCING SHIT */
class checking: public account
{
	
	public:
	checking()
	{
		accountType ="checking"; 
		interest = 0;
	}
	void checkaccount()
	{
		if (bal < 500)
		{
			bal = bal - 5;
		}
	}
	void orderChecks()
	{
		bal = bal - 15;
	}
	int deposit(double d)
	{
		account::deposit(d);
		checkaccount();
		return (0);

	}
	int withdraw(double w)
	{
		account::withdraw(w);
		checkaccount(); 
		return (0);
	}
};

/*THE OTHER ONE */
class cd: public account
{
	public:
//	cd()
//	{ accountType="certificate of deposit"; }
	int t;
	void checkterm(int term)
	{
		if (term >= 5)	
			interest = 10;
		else
			interest = 5;
	}
	cd(int term)
	{
		accountType="certificate of deposit";
		checkterm(term);
		t = term;
		
	}
	void compound(int day)
	{
		if (day == 1)
		{
			bal = bal + (bal * (interest/100));
		}
	}
	void penalty(int i)
		//combinde this with withdraw
	{
		if (i == 1)
		{
			bal = (bal - (bal *(interest/100)));
		}
	}
	int deposit(double d)
	{
		account::deposit(d);
		checkterm(t);
		return (0);

	}
	int withdraw(double w, int i)
		//if i == 1 penalty
	{
		if (i == 1)
		{
			bal = (bal - (bal *(interest/100)));
		}
		account::withdraw(w);
		checkterm(t);
		return (0);
	}
};

int main()
{
	savings mysave;
	mysave.accountNum = "save";
	mysave.deposit(10000); 
	checking mycheck;
	mycheck.accountNum = "check";
	mycheck.deposit(600);
	cd mycd(3);
	mycd.deposit(10000);
	mycd.accountNum = "cd";
	mysave.display();
	mycheck.display();
	mycd.display();
	//calculate monthly interest for savings
	mysave.compound(1);
	//calculate monthly interest for the cd
	mycd.compound(1);
	mysave.display();
	mycd.display();
	//order checks
	mycheck.orderChecks();
	mycheck.withdraw(200);
	mysave.withdraw(1000);
	mycd.withdraw(2000,1);

	mysave.display();
	mycheck.display();
	mycd.display();
	
	//new savings
//	account *mysave;
//	mysave = new savings();
//	mysave->deposit(10000);
//	//new checking
//	account *mycheck;
//	mycheck = new checking();
//	mycheck->deposit(600);
//	//new cd
//	account *mycd;
//	mycd = new cd(3);
//	mycd->deposit(10000);
//	//display those 
//	mysave->display();
//	mycheck->display();
//	mycd->display();
//	//display interest
//	
//	//order checks
//	mycheck->orderChecks();
//	mycheck->withdraw(200);
//	mysave->withdraw(1000);
//	mycd->withdraw(2000,1);
//	//display those 
//	mysave->display();
//	mycheck->display();
//	mycd->display();
//
//	myaccount->bal = 23;
//	myaccount->withdraw(5);
//	myaccount->display();
//	savings mysave;
//	mysave.bal = 23;
//	cout << "initial";
//	mysave.display();
//	mysave.checkaccount();
//	cout << "after check account";
//	mysave.display();
//	mysave.withdraw(5);
//	cout << "after withdraw";
//	mysave.display();

	

}
