#include <iostream>
#include <iomanip>

using namespace std;

void readInGrades (int gradesArray[]);
void printHistogram (int gradesArray[]);

string rangeArray [6] = {"0-49: ","50-59: ", "60-69: ", "70-79: ", "80-89: " ,"90-100: "};
double total = 0.0;

int main ()
{
	// 0 = 0-49%, 1  = 50-59%, 2 = 60-69%, 3 = 70-79%, 4 = 80-89%, 5 = 90-100%
	int gradesArray [6] = {0};
	readInGrades(gradesArray);
	cout << endl << "Histogram:" << endl;
	printHistogram(gradesArray);
}

void readInGrades (int gradesArray[])
{
	double grade = 0.0;
	do
	{
	cout << "Please enter a grade or enter -1 to exit and display your histogram: ";
	cin >> grade;
	
	// error-checking
	// grades must be between 0% and 100%
	if ((grade >= 0)&&(grade <= 100))
	{
		total += grade;
		
		// firstDigit was calculated to determine which range the grade falls under
		int firstDigit = static_cast<int>(grade)/10;
	 	if (firstDigit < 5)
	 		gradesArray[0]++;
	 	else if (firstDigit == 5)
	 		gradesArray[1]++;
	 	else if (firstDigit == 6)
	 		gradesArray[2]++;
	 	else if (firstDigit == 7)
	 		gradesArray[3]++;
	 	else if (firstDigit == 8)
	 		gradesArray[4]++;
	 	else if (firstDigit >= 9)
	 		gradesArray[5]++;
	}
	else if (grade == -1)
		cout << endl << "You have entered all of your grades!\n";
	else
		cout << "That is not a valid grade.\n";
	}while (grade != -1);
}

void printHistogram (int gradesArray[])
{
	int totalStudents = 0;
	for (int index = 0; index < 6; index++)
	{
		cout << setw(8) << rangeArray[index];
		
		// gradesArray[index] is equivalent to the number of students within each range
		// stars increases for each range while totalStudents increases for the entire gradesArray
		for (int stars = 1; stars <= gradesArray[index]; stars++)
		{
			cout << "*";
			totalStudents++;
		}
		cout << endl;
	}
	cout << endl << "The class average is: " << total/totalStudents << "%";
}

