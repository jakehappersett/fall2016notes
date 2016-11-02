#include <iostream>
#include <fstream>

using namespace std;

int main()
{
//	ofstream output("~/test.txt");
//	output << "hey hi hello";
//	output.close();

	ofstream myfile("/home/jake/file.txt");
	myfile << "writing \n";
	myfile.close();

	return 0;
}
