#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main ()
{
	ifstream infile("/home/jake/school/450/iNFO450PhonebookREDUX/a");
	char* keyword;
	char word[50];
	char pch[50];
	char b[50];
	cin.getline(keyword, 50);
	//make a temporary file that reads in shit
	//for (int i; i<10; i++)
	//{
	infile.getline(word,50,'|');
	pch = strstr(word,keyword);
//	}
	cout << pch <<endl;
	return 0;
}
