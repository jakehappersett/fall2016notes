#include <iostream>
#include <cstring>
#include <stdio.h>
#include <fstream>

using namespace std;

///////////////////////////////////entry////////////////////////////////////
class entry 
{
	char firstname[50];
	char lastname[50];
	char number[50];
public:
	entry();
	void setEntry(char fn[], char ln[], char num[]);
	void display();
};

entry::entry()
{

	strcpy(firstname, "");
	strcpy(lastname, "");
}

void entry::setEntry(char fn[], char ln[], char num[])
{
	strcpy(firstname, fn);
	strcpy(lastname, ln);
	strcpy(number, num);
}

void entry::display()
{
	cout << "name: " << firstname << " " << lastname << endl;
	cout << "number: " << number << endl;
}

///////////////////////////////////phonebook/////////////////////////////////
class phonebook
{
	char filename[100];
	int listnum;
	entry **pb;
public:
	phonebook();
	~phonebook();
	int getcount();
	void add( entry *e);
	void show();
};

phonebook::phonebook()
{
	pb = new entry*[100];
	listnum = 0;
}

phonebook::~phonebook()
{
	delete pb;
}
int phonebook::getcount()
{
	return listnum;
}
void phonebook::add(entry *e)
{
	pb[listnum] = e;
	listnum++;
}
void phonebook::show()
{
	for (int i=0; i < listnum; i++)
	{
		pb[i]->display();
	}
}






/////////////////////////////////////////main//////////////////////////////////////
int main()
{
	entry *dude = new entry();
	dude->setEntry("jake","happ","804");

	phonebook *mypb = new phonebook();
	mypb->add(dude);
	mypb->show();
	
	return 0; 
}
