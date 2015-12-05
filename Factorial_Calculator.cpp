#include <iostream>
using namespace std;

int main()
{
	int number = 0;
	int factorial = 1;
	
	// Ask for input of an integer greater than or equal to zero 
	do 
	{
		cout << "Please insert an integer greater than or equal to zero.\n";
		cin >> number;
	}		
	while (number < 0);
	
	// Calculate factorial of inputted integer 
	for (int count = number; count > 0; count--)
	{
		factorial = factorial*count;
	}

	cout << number << "! = " << factorial;
	
	
}
