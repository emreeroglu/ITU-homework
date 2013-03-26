/***************************************************************************
* March 2013                                                               *
* Homework: 1                                                              *
* Little Calculator                                                        *
* Emin Mastizada | 150120914                                               *
***************************************************************************/

#include <iostream>
#include <cmath>
#include <cfloat>
#include <stdio.h>
#include <cstdlib>

using namespace std;

#define PI 3.1415

double EnterNum()
{
	bool valid = false;
	double num;
	while (!valid) {
	valid = true; ///Stop if input is correct
	cin >> num;
	if (cin.fail()) {	///Stream is false
		cin.clear();	///Correcting stream
		cin.ignore();	///Skipping the left over stream data
		cout << "\nPlease, enter number!!!\nCharacters and letters are not allowed\n\n";
		valid = false; ///Going back to loop
	}
	}
	return num;
}
void TotalCount(double x, double y, string method)	///This will do all calculations:
{
	double total;
	if (method == "+") {
		total = x + y;
	}
	else if (method == "-") {
		total = x - y;
	} else if (method == "*") {
		total = x * y;
	} else if (method == "/") {
		if (y==0) {
			cout << "unknown, because you cannot divide by 0\n"; exit(0);
		} else {
			total = x / y;
		}
	} else if (method == "log") {
		if (x==0 || x < 0) {cout << "undefined, it's variable can be only > 0\n"; exit(0); }
		total = log(x);
	} else if (method == "c-area") {
		total = 2 * PI * x;
	} else {
		cout << "unknown. It can't be calculated\n";	///Don't know if this error is possible :D
	}
					///	Checking result for limit:
	if (total > DBL_MAX) { cout << "bigger than double's limit\n\n\n"; exit(0); }
	else if (total < DBL_MIN && total != 0 && total > -DBL_MIN && total < -DBL_MAX) { cout << "smaller than double's limit\n\n\n"; exit(0); }
		/// Time to print result:
	cout << total <<endl;
}

int main() {
	double x, y, total;
	string method;
	string again;
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWelcome. Please,";
	METHOD:
	cout << " Choose which operation you want?\n( 1.add, 2.subtract, 3.multiply, 4.divide, 5.log, 6.circle-area)\n\n\n";
	cin >> method;
	
	if (method == "add" || method == "1" || method == "+")
	{
		cout << "Enter 2 numbers for addition:\n\n";
		x = EnterNum();
		y = EnterNum();
		cout << "Addition result is ";

		TotalCount(x, y, "+");

		cout << "Do you want to try again? (Y/N)\n";
		cin >> again;
		if (again == "Y" || again == "YES" || again == "Yes" || again == "yes" || again == "y") { goto METHOD; }
		else { return 0; }
	}
			if (method == "subtract" || method == "2" || method == "-")
	{
		cout << "Enter 2 numbers for subtraction:\n\n";
		x = EnterNum();
		y = EnterNum();
		cout << "Subtraction result is ";
		TotalCount(x, y, "-");
		cout << "Do you want to try again? (Y/N)\n";
		cin >> again;
		if (again == "Y" || again == "YES" || again == "Yes" || again == "yes" || again == "y") { goto METHOD; }
		else { return 0; }
	}
		if (method == "multiply" || method == "3" || method == "*")
	{
		cout << "Enter 2 numbers for multiplication:\n\n";
		x = EnterNum();
		y = EnterNum();
		cout << "Multiplication result is ";
		TotalCount(x, y, "*");
		cout << "Do you want to try again? (Y/N)\n";
		cin >> again;
		if (again == "Y" || again == "YES" || again == "Yes" || again == "yes" || again == "y") { goto METHOD; }
		else { return 0; }
	}
		if (method == "divide" || method == "4" || method == "/")
	{
		cout << "Enter 2 numbers for division:\n\n";
		x = EnterNum();
		y = EnterNum();
		cout << "Division result is ";
		TotalCount(x, y, "/");
		cout << "Do you want to try again? (Y/N)\n";
		cin >> again;
		if (again == "Y" || again == "YES" || again == "Yes" || again == "yes" || again == "y") { goto METHOD; }
		else { return 0; }
	}
		if (method == "log" || method == "5")
	{
		cout << "Enter number for logarithm:\n\n";
		x = EnterNum();
		y = 1;
		cout << "log(" << x << ") = ";
		TotalCount(x, y, "log");
		cout << "Do you want to try again? (Y/N)\n";
		cin >> again;
		if (again == "Y" || again == "YES" || again == "Yes" || again == "yes" || again == "y") { goto METHOD; }
		else { return 0; }
	}
	if (method == "circle-area" || method == "6")
	{
		cout << "Enter the radius of circle:\n\n";
		x = EnterNum();
		y = 1;
		cout << "Your circle's area is ";
		TotalCount(x, y, "c-area");
		cout << "Do you want to try again? (Y/N)\n";
		cin >> again;
		if (again == "Y" || again == "YES" || again == "Yes" || again == "yes" || again == "y") { goto METHOD; }
		else { return 0; }
	}
	return 0;
}
