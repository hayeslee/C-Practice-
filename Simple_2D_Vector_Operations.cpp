#include <iostream>
using namespace std;
int main()

{
	int xu1 = 0, yu1 = 0,
		xu2 = 0, yu2 = 0,
		xv1 = 0, yv1 = 0,
		xv2 = 0, yv2 = 0;
		
	// Ask for input 	
	cout << "2-Dimensional Vector Operations\n"
		 << "Vector u has components U1 and U2.\n"
		 << "Vector v has components V1 and V2.\n"
		 << endl
		 << "Please enter the components for u.\n"
		 << "First enter U1 as two integers: ";
	cin >> xu1 >> yu1;
	cout << "Now enter U2 as two integers: ";
	cin >> xu2 >> yu2;
	cout << endl
		 << "\nPlease enter the components for v.\n"
		 << "First enter V1 as two integers: ";
	cin >> xv1 >> yv1;
	cout << "Now enter V2 as two integers: ";
	cin >> xv2 >> yv2;
	cout << endl // Echo the input
		 << "\nYou have entered:\n"
		 << "U1 = (" << xu1 << "," << yu1 << ")\n"
		 << "U2 = (" << xu2 << "," << yu2 << ")\n"
		 << "V1 = (" << xv1 << "," << yv1 << ")\n"
		 << "V2 = (" << xv2 << "," << yv2 << ")\n" << endl;
		 
	// Calculate vectors u and v and their components
	int ui = xu2 - xu1;
	int uj = yu2 - yu1;
	int vi = xv2 - xv1;
	int vj = yv2 - yv1;

	// Properly displaying cases where components are negative
	if ((uj > 0)&&(vj >0))
		cout << "The vectors u and v are:\n"
			 << "u = " << ui << "*i + " << uj << "*j\n"
			 << "v = " << vi << "*i + " << vj << "*j\n"
			 << endl;
	else if ((uj < 0)&&(vj > 0))
		cout << "The vectors u and v are:\n"
			 << "u = " << ui << "*i " << uj << "*j\n"
			 << "v = " << vi << "*i + " << vj << "*j\n"
			 << endl;
	else if ((uj > 0)&&(vj < 0))
		cout << "The vectors u and v are:\n"
			 << "u = " << ui << "*i + " << uj << "*j\n"
			 << "v = " << vi << "*i " << vj << "*j\n"
			 << endl;
	else
		cout << "The vectors u and v are:\n"
			 << "u = " << ui << "*i " << uj << "*j\n"
			 << "v = " << vi << "*i " << vj << "*j\n"
			 << endl;
	
	int option = 0;
	while (option !=-1) // Present the options of vector addition, dot product, or cross product
						// Repeat questions until -1 is inputted to exit the loop
	{
		cout << "Select a vector operation to perform: \n"
			 << "1: u + v (addition)\n"
			 << "2: u x v (cross product)\n"
			 << "3: u . v (dot product)\n"
			 << "Enter 1-3 from the menu above, or -1 to exit\n";
		cin >> option;
		
		switch(option)
		{
			case 1:
				{
				int sumi = ui + vi;
				int sumj = uj + vj;
					// Properly displaying cases where components are negative
					if (sumj > 0) 
						cout << "\nu + v = " << sumi << "*i + " << sumj << "*j\n" << endl;
					else
						cout << "\nu + v = " << sumi << "*i " << sumj << "*j\n" << endl;
				break;
				}
			case 2:
				{
				int crossProduct = ui*vj - vi*uj;
				cout << "\nu x v = " << crossProduct << endl << endl;
				break;
				}
			case 3:
				{
				int dotProduct = ui*vi + uj*vj;
				cout << "\nu . v = " << dotProduct <<endl << endl;
				break;
				}
			case -1:
				{
				cout << "You have exited the program.";
				break;
				}
			default:
				cout << "That is not a valid option.\n" << endl;
		}
	}

	return 0;
}
