#include <iostream> 
#include <cstring>
using namespace std;

char word[100];

char reverser(char *word);

int main()
	{

	cout << "enter some words: ";
	cin.getline(word,100);

	reverser(word);
	
	return 0;

	}

char reverser(char word[])
{
	int i = strlen(word);
	for (word[i]; i != -1; i--)
	{
		cout << word[i];
	}
	cout << endl;
}
