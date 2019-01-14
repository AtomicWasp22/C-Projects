/*i'm sorry for the terrible code and will make a much more valiant effort to complete projects well before the deadline in future especially when dealing with complex things such as passoing by referenc*/



#include <iostream>
#include <cmath>

using namespace std;


void sum1(double&, unsigned int);
double sum2(unsigned int);
unsigned int getValidPositiveInteger();

int main()
{
	cout << "This program approximates the value of the series by calculating the partial sum to a user-specified degree\n";
	
	cout << "Enter the number of terms in the portion of the series (first trial): ";
	unsigned int n1 = getValidPositiveInteger(), n2;
	double estimate1;
	estimate1 = 0;

	//Calls sum1 passing the variable to which the partial sum will be saved and the number of trials in he partial sum
	sum1(estimate1, n1);
	cout << "Estimate: ";
	cout << estimate1;
	
	cout << "\nEnter the number of terms in the portion of the series (second trial): ";
	n2 = getValidPositiveInteger();

	double estimate2;
	estimate2 = sum2(n2);
	cout << "Estimate: ";
	cout << estimate2;

	//if the outcome of the second estimation is equivalent to that of the first:
	if (estimate2 == estimate1) {
		cout << "\n\nThe results are the same.";
	}
	else {
		cout << "\n\nThe results are different.";
	}
	
	cout << endl;
	cout << system("pause");
	return 0;
}

void sum1(double& sum, unsigned int n)
{
	sum = 0;
	for (int i = 2; i <= n; i++) {
		//Sum equals itself plus the ith term of the pertial series
		sum += 1 / (pow(i, 2) - 1);
	}
}

double sum2(unsigned int n)
{
	int sum;
	sum = 0;

	for (int i = 2; i <= n; i++) {
		//Sum equals itself plus the ith term of the partial series
		sum += 1 / (pow(i, 2) - 1);
	}
	return sum;
}

// Get a valid integer from the user
unsigned int getValidPositiveInteger() {
	int userInput;

	cin >> userInput;

	while (cin.fail() || userInput < 0) {
		cin.clear();
		cin.ignore();
		cout << "Please enter a positive integer only\n";
		cin >> userInput;
	}

	return userInput;
}