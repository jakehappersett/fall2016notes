#include <iostream>
using namespace std;

int main ()
{
	int celsius = 0;
	double farenheit = 0;
	while(celsius < 101)
	{
		farenheit = celsius *1.8 +32;
		//cout << celsius << farenheit << endl;
		printf("celsius is %dfarenheit is %f",celsius,farenheit);
		celsius++;
	}
	
	return 0;
}

