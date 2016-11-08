// FavoriteThing.cpp : Defines the entry point for the console application.
//

//strcpy unix
//get_s unix

//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

enum beertype { LAGER, STOUT, IPA, CIDER };

class beer
{
	char brewery[50];
	char beername[50];
	int beertype;
	double rating;
	double alcoholContent;
public:
	beer();
	void setBeer(char b1[], char b2[], int btype, double r, double a);
	void display();
	friend class beerlist; //now beerlist has access to beers private stuff

};



beer::beer()
{
	strcpy(brewery, "");
	strcpy(beername, "");
	beertype = IPA;
	rating = 0.0;
	alcoholContent = 0.0;
	
}



void beer::setBeer(char b1[], char b2[], int btype, double r, double a)
{
	strcpy(brewery, b1);
	strcpy(beername, b2);
	beertype = btype;
	rating = r;
	alcoholContent = a;
}

void beer::display()
{
	printf("----------------------------------------\n");
	printf("Brewery: %s  Beer: %s Type: ", brewery, beername);
	switch (beertype)
	{
	case LAGER: cout << "Lager" << endl;
		break;
	case STOUT:
		cout << "Stout" << endl;
		break;
	case IPA:
		cout << "IPA" << endl;
		break;
	case CIDER:
		cout << "Cider" << endl;
		break;
	default:
		cout << "unknown" << endl;
	};
	printf("Rating: %3.2f  Alcohol Content: %1.2f\n", rating, alcoholContent);
	printf("----------------------------------------\n");
}

class beerlist
{
	char filename[100];
	int beerCount;
	beer **mylist;
public:
	beerlist();
	~beerlist();
	void setFilename(char f[]);
	int getCount();
	void beerlist::addToList(beer *b);
	void beerlist::showList();
	int saveList();
	void readList();
};

beerlist::beerlist()
{
	mylist = new beer*[100];
	beerCount = 0;
}

beerlist::~beerlist() {
	delete mylist;
}

void beerlist::setFilename(char f[])
{
	strcpy_s(filename, f);
}

void beerlist::addToList(beer *b)
{
	mylist[beerCount] = b;
	beerCount++;;
}

int beerlist::getCount()
{
	return beerCount;
}

void beerlist::showList()
{
	for (int i = 0; i < beerCount; i++)
	{
		mylist[i]->display();		
	}
}

int beerlist::saveList()
{
	ofstream output(filename);
	if (!output)
	{
		cout "fail" <<endl;
		return -1;
	}
	for (int i=0; i < beerCount; i++)
	{
		output << mylist[i]->brewery << ",";
		output << mylist[i]->beername<< ",";
		output << mylist[i]->beertype<< ",";
		output << mylist[i]->rating<< ",";
		output << mylist[i]->alchoholContent << endl; } output.close();
	return 0;
	
}


void beerlist::readList()
{
	//TBD
}


int main()
{
	char answer = 'y';
	char beername[50];
	char brewery[50];
	int beertype;
	double rating;
	double alcohol;
	char filename[50];

	// create a new beerlist object
	beerlist *bList = new beerlist();

	// now get and set filename
	cout << "please enter full path filename" << endl;
	gets_s(filename);
	bList->setFilename(filename);

	// Read in any existing file
		bList->readList();
	if (bList->getCount()==0)
	{
		cout << "your list is empty!  Start recording!! " << endl;
	}
	else
	{
		cout << "You have " << bList->getCount() << " in your list." << endl;
	}

	cout << "Would you like to enter new beer? enter Y to add; any other key to quit" << endl;
	cin >> answer;

	while (answer == 'Y' || answer == 'y')
	{
		cin.ignore();
		cin.clear();

		cout << "enter beer" << endl;
		gets_s(beername);
		cout << "enter brewery" << endl;
		gets_s(brewery);
		cout << "enter type 0: LARGER, 1:STOUT, 2:IPA, 3:CIDER " << endl;
		cin >> beertype;
		cin.ignore();
		cin.clear();
		cout << "enter rating 1.0-5.0" << endl;
		cin >> rating;
		cout << "enter alcohol content" << endl;
		cin >> alcohol;

		beer *mybeer = new beer();
		mybeer->setBeer(brewery, beername, beertype, rating, alcohol);
		bList->addToList(mybeer);
		

		cout << "Another ? - Enter Y to add; any other key to quit"  << endl;
		cin >> answer;
	}		

	
	// show list 
	bList->showList();
	bList->saveList();
	
    return 0;
}

