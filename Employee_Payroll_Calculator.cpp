#include <iostream>
#include <iomanip>
using namespace std;

double managerPay();
double hourlyWorkerPay();
double commissionWorkerPay();
double pieceworkerPay();

int main()
{
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

	enum TypeOfWorker {MANAGER=1, HOURLY, COMMISSION, PIECEWORKER, EXIT};		 
	int choice = 0;
	int managerCount = 0, hourlyWorkerCount = 0, commissionWorkerCount = 0, pieceworkerCount = 0;
	double totalManagerPay = 0, totalHourlyWorkerPay = 0, totalCommissionWorkerPay = 0, totalPieceworkerPay = 0;
	
	cout << "Welcome to the payroll calculator!\n";
	
	// While there are more employees to enter 
	while (choice!=EXIT)
	{
		cout  << endl << "To calculate payroll, please type\n"
		 << "\"1\" for managers,\n" << "\"2\" for hourly workers,\n" << "\"3\" for commission workers,\n" << "\"4\" for pieceworkers: \n" << "\"5\" to output the table of salaries:\n";
		
		// Choice and error checking
		do{
			cin >> choice;
			switch (choice)
			{
				case MANAGER:
					totalManagerPay += managerPay();
					managerCount++;
					break;
				case HOURLY:
					totalHourlyWorkerPay += hourlyWorkerPay();
					hourlyWorkerCount++;
					break;
				case COMMISSION:
					totalCommissionWorkerPay += commissionWorkerPay();	
					commissionWorkerCount++;
					break;
				case PIECEWORKER:
					totalPieceworkerPay += pieceworkerPay();
					pieceworkerCount++;
					break;
				case EXIT:
					break;
				default:
					cout << endl << "Sorry that is not a valid choice. Please try again: ";
			}
		} while ((choice>5)||(choice<1));
	}	

// Outputting Table of Pay
cout << endl
	 << "Number of Employees\t|\tSalary per Position\t|\tOverall Total\n"
	 << "\t" << managerCount << "\t\t|\t\t$" << totalManagerPay << "\t\t|\t$" << totalManagerPay+totalHourlyWorkerPay+totalCommissionWorkerPay+totalPieceworkerPay << endl
	 << "\t" << hourlyWorkerCount << "\t\t|\t\t$" << totalHourlyWorkerPay << "\t\t|\t\t" << endl	
	 << "\t" << commissionWorkerCount << "\t\t|\t\t$" << totalCommissionWorkerPay << "\t\t|\t\t" << endl
	 << "\t" << pieceworkerCount << "\t\t|\t\t$" << totalPieceworkerPay << "\t\t|\t\t" << endl;
	
return 0;
}

double managerPay(){
	double salary = 0.0;
	cout << endl << "You have chosen a manager.\nWhat is the manager's weekly salary? ";
	cin >> salary;	
	return salary;
}

double hourlyWorkerPay(){
	double hours = 0.0;
	double wage = 0.0;
	cout << endl << "You have chosen an hourly worker.\nHow many hours did the hourly worker work this week? ";
	cin >> hours;
	cout << "How much is the hourly worker's hourly wage? ";
	cin >> wage;
	cout << "You worked " << hours << " hours this week and your hourly wage is " << "$" << wage << "/hour." << endl;
	
	if (hours<=40)
		return hours*wage;
	else
		return 40*wage + (hours-40)*(1.5*wage);
}

double commissionWorkerPay(){
	double grossSales =0.0;
	cout << endl << "You have chosen a commission worker.\nWhat is the commission worker's gross weekly sales?: ";
	cin >> grossSales;
	return 200+(0.066*grossSales);
}

double pieceworkerPay(){
	int noOfItems = 0;
	int payPerItem = 0;
	cout << endl << "You have chosen a pieceworker.\nHow many items did the pieceworker make?: ";
	cin >> noOfItems;
	cout << "How much money did the pieceworker get from each item made?: ";
	cin >> payPerItem;
	return noOfItems*payPerItem;
}
