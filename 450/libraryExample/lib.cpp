#include <iostream>
#include <stdio.h>
#include <cstring> 

using namespace std;

class Publication 
{
	protected: 
		char title [50];
		char author [50];
		char ISBN [50];
		double price;
	public: 
		Publication()
		{ 
			price=0;
		}
		virtual void display() = 0;
		virtual void get_info() = 0;
};

class Book : public Publication
{
	int numPages;
	public:
	void display()
	{
		printf("title %s author %s ISBN %s Price %.2d pages %d", title, author, ISBN, price, numPages);
	}
	void get_info()
	{
		cout << "enter title ";
		cin.getline(title, 50);
		cout << "enter author ";
		cin.getline(author, 50);
		cout << "enter Price ";
		cin >> price;
		cout << "enter pages ";
		cin >> numPages;
	cin >> numberPubs;
	cin.clear();

	}
};
int main (){
	Publication **bptr;
	int numberPubs = 0;
	char answer[2];
	cout << "how many publications? ";
	cin >> numberPubs;
	cin.clear();
	cin.ignore();
	bptr = new Publication *[numberPubs]; 
	for (int i = 0; i < numberPubs; i++)
	{
		cout << "enter something" << endl;
		cin.getline(answer);
		if (strcmp(answer, "b")==0)
		{
			bptr[i] = new Book();
			bptr[i]->get_info();
		}
		else if (strcmp(answer, "a")==0)
		{
			bptr[i] = new Book();
			bptr[i]->get_info();
		}
		else
		{
			cout "fuck you" << endl;
			--i;
		}
	}
	for (int i = 0; i < numberPubs; i++)
	{
		bptr[i]->display();	
	}
	for (int i=0; i < numberPubs; i++)
	{
	}

	return 0;
}
