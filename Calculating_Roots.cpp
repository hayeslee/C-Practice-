#include <iostream>
#include <cmath>

using namespace std;

void inputCoefficients ();
void calculateRoots (double &a, double &b, double &c);
void displayRealRoots (double &root1, double &root2);
void displayComplexRoots (double &realRoot, double &imaginaryRoot);

int main ()
{
	inputCoefficients();
	return 0;
}

void inputCoefficients()
{
	double a = 0.0, b = 0.0, c = 0.0;
	cout << "Input a value for a: ";
	cin >> a;
	cout << "Input a value for b: ";
	cin >> b;
	cout << "Input a value for c: ";
	cin >> c;
	
	calculateRoots (a, b, c);
}

void calculateRoots (double &a, double &b, double &c)
{
	double discriminant = b*b-4*a*c;
	
	// determines whether the roots are real or complex numbers
	// depending on the value of the discriminant
	if (discriminant >= 0){
	
	double root1 = (-b+sqrt(b*b-4*a*c))/(2*a);
	double root2 = (-b-sqrt(b*b-4*a*c))/(2*a);
	
	displayRealRoots (root1, root2);
	}
	else {
	
	double realRoot = (-b)/(2*a);
	double imaginaryRoot = sqrt((discriminant*-1))/(2*a);
	
	displayComplexRoots (realRoot, imaginaryRoot);
	}
}

void displayRealRoots (double &root1, double &root2)
{
	cout << "The roots are: x=" << root1 << " and x=" << root2;
}

void displayComplexRoots (double &realRoot, double &imaginaryRoot)
{
	cout << "\nThe roots are: x=" << realRoot << "+" << imaginaryRoot << "i and x="
		 << realRoot << "-" << imaginaryRoot << "i";
}
