#include <iostream>
#include <cmath>
using namespace std;

const string DIRECTIONS[] = {" ","1: ENE","2: NE","3: NNE","4: N","5: NNW","6: NW","7: WNW","8: W","9: WSW","10: SW","11: SWS","12: S","13: SSE","14: SE","15: ESE","16: E"};

double input(double& cruisingSpeed, double& windSpeed, double& distance, int& windDirection, int& choice);
double heading(double cruisingSpeed, double windSpeed, double angleOriginal);
double adjustment(double cruisingSpeed, double angleHeading, double angleOriginal);
double time(double distance, double groundSpeed);
void output(double angleHeading, double flightTime);

int main()
{
	double cruisingSpeed = 0.0, windSpeed = 0.0, distance = 0.0;
	int windDirection = 0, choice = 0;
	
	// Calculates and displays the flight time and adjusted heading given the cruising speed, wind speed, distance, wind direction from the user
	double angleOriginal = input(cruisingSpeed,windSpeed,distance,windDirection,choice);
	double angleHeading = heading(cruisingSpeed,windSpeed,angleOriginal);
	double groundSpeed = adjustment(cruisingSpeed,angleHeading,angleOriginal);
	double flightTime = time(distance, groundSpeed);
	output(angleHeading, flightTime);

	return 0;
}

double input(double& cruisingSpeed, double& windSpeed, double& distance, int& windDirection, int& choice)
{	
	//Get user input for cruisingSpeed, windSpeed and windDirection
	cout << "This program will compute the necessary heading adjustment for your flight, and provide the estimated flight time." << endl << endl
		 << "Enter the aircraft cruising speed in still air (in km/h): ";
	cin >> cruisingSpeed;
	cout << "\tcruising speed = " << cruisingSpeed << "km/h" << endl << endl
		 << "Enter the wind speed (in km/h): ";
	cin >> windSpeed;
	cout << "\twind speed = " << windSpeed << "km/h" << endl << endl;
	
	do {
	cout << "Enter 1 if the wind is blowing from the West or -1 if wind is blowing from the" << endl << "East: ";
	cin >> windDirection;
	
	if (windDirection == 1)
		cout << "\tThe wind is blowing from the West." << endl << endl;
	else if (windDirection == -1)
	{
		cout << "\tThe wind is blowing from the East." << endl << endl;
		windSpeed *=-1;
	}
	else
		cout << "That is not a valid direction. Please Try again." << endl << endl;
	} while ((windDirection!=1)&&(windDirection!=-1));

	// Get user input for distance 
	cout << "Enter the distance between the originating and destination cities (in km): ";
	cin >> distance;
	cout << "\tflight distance = " << distance << "km" << endl << endl
		 << "Enter the compass direction of the destination city, relative to the" << endl
		 << "originating city, using the following values:" << endl << endl;
		 
	for (int index = 0; index <= 16; index++)
	{
		cout << DIRECTIONS[index] << endl;
	}

	// Get user input for angle choice 
	cin >> choice;
	double angle = 22.5*choice;
	cout << "\tflight direction = " << DIRECTIONS[choice] << endl
		 << "\toriginal flight heading = " << angle << " degrees";
		 
return angle;
}

double heading(double cruisingSpeed, double windSpeed, double angleOriginal)
{
	double angleRad = angleOriginal*M_PI/180;
	return angleRad+asin((windSpeed/cruisingSpeed)*sin(angleRad));
}

double adjustment(double cruisingSpeed, double angleHeading, double angleOriginal)
{
	double angleRad = angleOriginal*M_PI/180;
	return cruisingSpeed*sin(angleHeading)/sin(angleRad);
}

double time(double distance, double groundSpeed)
{
	return distance/groundSpeed;
}

void output(double angleHeading, double flightTime)
{
	// Calculates adjusted flight heading (converting back to degrees)
	double adjustedHeading = angleHeading*180/M_PI;
	cout << endl << endl
		 << "Your adjusted flight heading is: " << adjustedHeading << " degrees." << endl
		 << "Your estimated flight time is: " <<flightTime << " hours.";
}
