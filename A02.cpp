// A02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int startWeight, feet, inches, weeks, totalInches;
	float change, startBMI, endBMI, endWeight;
	
	cout << "BMI Calculator\n---------------\nWhat is your current weight in pounds (lbs)?";
	cout << endl;
	cin >> startWeight;
	
	cout << "What is your height in feet and inches, formatted with a space between (e.g. 5 11)?";
	cout << endl;
	cin >> feet;
	cin >> inches;
	
	cout << "What is your goal weight change per week (lbs)?";
	cout << endl;
	cin >> change;
	
	cout << "How many weeks do you plan to continue this trend?";
	cout << endl;
	cin >> weeks;

	totalInches = (feet * 12) + inches;
	startBMI = (startWeight * 703) / pow(totalInches, 2);

	endWeight = startWeight - (weeks * change);
	endBMI = (endWeight * 703) / pow(totalInches, 2);

	startBMI = round(startBMI * 100.0) / 100.0;
	endBMI = round(endBMI * 100.0) / 100.0;

	cout << "If you follow through with your plan:";
	cout << endl;
	cout << "      " << setw(6) << "Weight" << " " << setw(6) << left << "BMI";
	cout << endl; 
	cout << "------------------------";
	cout << endl;
	cout << setw(6) << left << "Start" << setw(6) << startWeight << " " << setw(6) << startBMI;
	cout << endl; 
	cout << setw(6) << "End" << setw(6) << endWeight << " " << setw(6) << endBMI;
	cout << endl;
	cout << "\n";
	cout << endl;
	system("pause");
	return 0;
}