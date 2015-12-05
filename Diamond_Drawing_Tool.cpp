#include <iostream>

using namespace std;
int main()

{
	int noOfRows = 0;
	int noOfStars = 0;
	int noOfSpaces = 0;
	
	do {
	cout <<  "Please insert a positive, odd number of rows between 3-19\nthat you would like in your diamond: ";
	cin >> noOfRows;
	} while ((noOfRows > 19)||(noOfRows < 3)||(noOfRows%2==0));
	
	// Calculate the number of spaces before the asterisk in the first row
	int firstRowSpace  = noOfRows/2;
	
	// For each row, print out number of stars and spaces
	for (int row = 1; row <= noOfRows; row++) {

		// Checks whether the code is working with the top or bottom half of the diamond
		if (row <= noOfRows/2+1){
		 	noOfStars = (row*2)-1;
			noOfSpaces = firstRowSpace - (row-1);
		}
		else {
			noOfStars -=2;
			noOfSpaces ++;
		}
		
		// Outputs spaces
		for (int spaces = noOfSpaces; spaces > 0; spaces--)
			cout << " ";
		
		// Output stars
		for (int stars = noOfStars; stars >0; stars--)	
			cout << "*";
		
		cout << endl;		
	}
	
return 0;

}
