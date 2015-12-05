#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
	// Seed the random number
	srand(time(0));

	int response = 0;
	int	num1 = rand()%10;
	int	num2 = rand()%10;
	
	// Ask question and get response from user 
	cout << "Type \"-1\" at any point to exit the program.\n" << endl
		 << "How much is " << num1 << " times " << num2 << "? ";	
	cin >> response;
	int numOfTries = 1; // Keeps track of number of tries per question 
	int firstTries = 0; // Keeps track of number of questions answered correctly on the first try 
	int totalQuestions = 0; // Keeps track of total number of questions answered correctly 
		
	while (response != -1) 	
	{
	// Ask another question if response is correct
	if (response == num1*num2)
		{
			if (numOfTries == 1)
				firstTries++;
			
			numOfTries = 1;
			
			cout << "Congrats! You got the answer right!\n\n";
			
			totalQuestions++;
			num1 = rand()%10;
			num2 = rand()%10;
			cout << "How much is " << num1 << " times " << num2 << "? ";
		}
	// Ask question again if response is incorrect until it is answered correctly 
	else 
		{
			numOfTries++;
			cout << "How much is " << num1 << " times " << num2 << "? ";
		}
		
		cin >> response;
		
	} 
	
	cout << endl << firstTries << " questions were answered correctly on the first try out of " << totalQuestions << " questions total.";
	
	
	
}
