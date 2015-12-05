#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{	
	int decimals = 0;
	double total = 0.0;
	int previousNum = 0;
	int termNum = 1;
	int matchesInARow = 1;

	do {
	cout << "Insert the number of decimal places from 1 to 6: ";
	cin >> decimals;
	} while ((decimals<1)||(decimals>6));
	
	cout.setf(ios::fixed);
	cout.precision(12);

	while (matchesInARow < 3){
	
		// Generates terms
		for (int n = 1; n <= termNum; n++)
		{
			if (n % 2==0)
				total -= (4.0/(n*2-1));
			else
				total += (4.0/(n*2-1));
		}
	
		cout << termNum << "\t" << total << endl;
	
		// The variable num is used only to compare the numbers
		// of decimal places indicated by the user
		int num = floor(total*pow(10,decimals));
	
		// Checking for matching decimal places
		if (num == previousNum)
			matchesInARow++;
		else
			matchesInARow=1;
			
	// previousNum is needed for comparison with the next term
	// termNum is increased and total is set to 0 to generate the next term
	previousNum = num;
	termNum++;
	total = 0;
	}
}
