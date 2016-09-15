#include <iostream> 
#include <cmath>

using namespace std;
const double PI = 3.14;

double getCirc(double radius);
double getArea(double radius);
	
int main()
{

	int radius = 5;
	bool answer= true;
	char response;
	
	do 
	{
		cout << "what's the radius of your circle" << endl;
		cin >> radius;
		cout << getArea(radius) << endl;	
		cout << getCirc(radius) << endl;
		cout << "would you like to continue (y,n)" << endl;
		cin >> response; 
		while (response != 'Y' && response != 'y' && response != 'n' && response !='N')
			{
			cout << "please enter a valid response";
			cin >> response;
			}
		if ((response == 'y')||(response == 'Y'))
			answer = true;
		else
			answer = false;
	} 
	
	while ( answer ); 
	return 0; 
} 
double getCirc(double radius)
{
	return (2 * PI * radius);
}
double getArea(double radius)
{
	return PI * pow(radius,2);
}
