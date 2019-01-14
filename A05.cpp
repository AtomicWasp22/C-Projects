#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

unsigned int getDayOfYear();

int main() {

	//Array Definition
	char months[12][12];
	int daysPerMonth[12];

		
	//open file for input
	ifstream inFile;
	inFile.open("cal.txt");

	
	int k;
	k = 0;
	
	//Read from file into arrays
	while (!inFile.eof()) {
		k++;
		if (k <= 12) {
			inFile >> months[k - 1];
		}
		else {
			inFile >> daysPerMonth[k - 13];
		}
	}
	cout << "Welcome to the Date Predictor!\n\n";
	//Asks user how many days in the future
	unsigned int numDays;
	cout << "How many days in the future is the date you wish to display? ";
	cin >> numDays;
	cout << endl;
	
	//returns current day
	int today;
	today = getDayOfYear();

	//Total days this year
	int daysInFuture;
	daysInFuture = today + numDays;
	daysInFuture %= 365;

	int month;
	
	//Finds future date
	for (month = 0; daysInFuture > daysPerMonth[month]; month++) {
		daysInFuture -= daysPerMonth[month];
	}

	cout << "The date would be " << months[month] << " " << daysInFuture;

	return 0;
}




// returns the  current day of the year
unsigned int getDayOfYear() 
{
	time_t t;
	struct tm timeinfo; 

	time(&t);
#ifdef _WIN32
	localtime_s(&timeinfo, &t);
#else
	localtime_r(&t, &timeinfo)
#endif
	return timeinfo.tm_yday;
}
