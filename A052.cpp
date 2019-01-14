
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;
unsigned int getDayOfYear();
unsigned int const AMOUNT_MONTHS = 12, YEAR_DAYS = 365;

int main() {
	unsigned int future_date, month_days[AMOUNT_MONTHS], counter, total_days, month_counter;
	// Using c-style strings as requested.
	char months[AMOUNT_MONTHS][AMOUNT_MONTHS] = {};


	counter = 0;
	month_counter = 0;
	//Reading from the file.
	ifstream file;
	file.open("cal.txt");

	//Putting the data from the txt file into the corresponding c-style array.
	while (!file.eof()) { // While we are not at the end of the file... do:
		counter++;
		if (counter <= AMOUNT_MONTHS) {
			file >> months[counter - 1];

		}
		else {
			file >> month_days[counter - 13];
		}
	}

	//Creating the header to the program.
	cout << "Incredible Edible Date Predictor!" << endl;
	cout << "*********************************" << endl;

	//Requesting inputs (Amount of days in the future.)
	cout << "Enter the number of days in the future you want to predict the date for: ";
	cin >> future_date;
	cout << endl;

	//Getting the current date, and adding that to future_date.
	total_days = getDayOfYear() + future_date;

	//Calculating the date.
	while (total_days > YEAR_DAYS) {
		total_days -= YEAR_DAYS;
	}

	// Now we have amount as the day of the year.
	// I can now determine to which month it belongs to.
	while (total_days > 31) {
		total_days -= month_days[month_counter];
		month_counter++;
	}

	//Outputs (The answer)
	cout << "The date you have requested is: "
		<< months[month_counter] << " " << total_days
		<< "." << endl;

	// Cleaning process. CLosing the file after having used it.
	file.close();
	return 0;
}
// returns the  current day of the year
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