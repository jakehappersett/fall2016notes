#include <iostream>
#include <cstring>
#include <stdio.h>
//#include <term.h> 
#include <fstream>

using namespace std;
\
/////////////////////////some functions////////////////////////////////////////
void clearscreen()
//dont judge me 
{
	int n;
        for (n = 0; n < 5; n++)
	printf( "\n\n\n\n\n\n\n\n\n\n" );
}

void clearcin()
{
	cin.ignore(); 
	cin.clear(); }

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
	friend class phonebook;
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
	int listnum = 0;
	entry **pb;
	int check();
public:
	phonebook();
	~phonebook();
	int getcount();
	void add( entry *e);
	void show();
	int save();
	void read();
	void setfilename(char f[]);
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
	check();
}
int phonebook::check()
{
	if (listnum==0)
	{
		listnum++;	
	}
	else 
	{
		for (int i=0; (i < listnum); i++)
		{
			if (strcmp(pb[i]->number,pb[listnum]->number) == 0)
			{
				cout << "already did that" << endl;
				listnum--;
				break;
			}
		}
		listnum++;
	}
}
void phonebook::show()
{
	/////work on this tommorrow 
	//// only showing 4 instead of 5
	//because it is incrementing when you do the cin.ignore 
	int count = 0;
	for (int i=0; i < listnum; i++) {
		if(i%5 == 0 && i !=0) 
		{
			cin.ignore();
			cout << i+1 << ". ";
			pb[i]->display();
		}
		else
		{
			clearscreen();
			cout << i+1 << ". ";
			pb[i]->display();
		
		}
	}
}
void phonebook::setfilename(char f[])
{
	strcpy(filename, f);
}
int phonebook::save()
{
	ofstream file(filename);
	if (!file)
	{
		cout << "try again" << endl;
		return -1;
	}
	for (int i=0; i < listnum; i++)
	{
		file << pb[i]->firstname << "|";
		file << pb[i]->lastname<< "|";
		file << pb[i]->number<< "|";
	}
}
void phonebook::read()
{
	ifstream infile(filename);
	if (!infile)
	{
		return;
	}
	while (!infile.eof())
	{
		entry *p;
		char nme[50];
		char lnme[50];
		char number[50];
		
		infile.getline(nme, 50, '|');
		if (strlen(nme))
		{
			infile.getline(lnme, 50, '|');
			infile.getline(number, 50, '|');
			p = new entry();
			p->setEntry(nme,lnme,number);
			add(p);
		}
	}
	infile.close();
}


/////////////////////////////////////////main//////////////////////////////////////
int main()
{
//	entry *dude = new entry();
//	entry *ent = new entry();
//	dude->setEntry("jake","happ","804");
//	phonebook *mypb = new phonebook();
//	mypb->setfilename("/home/jake/test.txt");
//	mypb->read();
//	mypb->add(ent);
//	mypb->show();
//	mypb->save(); 
//	return 0; 

	char name[50];
	char lastname[50];
	char number[50];
	char f[50];

	phonebook *pbr = new phonebook();
	cout << "enter path and filename" << endl;
	cin.getline(f,50);
	pbr->setfilename(f);
	pbr->read();
	clearscreen();
	if (pbr->getcount()!=0)
	{
	cout << "there is " <<pbr->getcount()<< " entries in your phonebook" << endl;
	cin.ignore();
	clearscreen();
	}
	do {
	char opt;
		clearscreen();
		cout << "what do you want to do" << endl;
		cout << "----------------------" << endl;
		cout << " add new contact --> a" << endl;
		cout << " display contacs --> d" << endl;
		cout << " quit            --> q" << endl;
		cin >> opt;
		cin.ignore();
		if (opt == 'a'|| opt == 'A')
		{
			clearscreen();
			if (pbr->getcount() < 100)
			{
				cout << "enter first name" << endl;
				cin.getline(name, 50);
				cout << "enter last name" << endl;
				cin.getline(lastname, 50);
				cout << "enter number" << endl;
				cin.getline(number, 50);
				clearscreen();
				
				entry *person = new entry();
				person->setEntry(name,lastname,number);
				pbr->add(person);
				
			}
			else
			{
				cout << "its full, get less friends" << endl;
			}
		}
		else if (opt =='d')
		{
			clearscreen();
			pbr->show();
			clearcin();

		}
		else if (opt == 'q')
		{
			pbr->save();
			break;
		}
	} while (1==1);


	cout << "that worked" << endl;
	return 0;
	

}
