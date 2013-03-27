/***************************************************************************
* Homework: 2                                                              *
* Crossing the Bridge                                                      *
* Emin Mastizada | 150120914                                               *
***************************************************************************/
/***			No Any Special Notes for now            				***/

#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
	int N, M, tries;
	double alc;
	bool checker;
	
	cout << "Enter bridge size (N and M):\t";
	checker = false;
	while (checker == false)
	{
		cin >> N >> M;
<<<<<<< HEAD
		if (cin.fail()) { cout << "\nERROR!!!\n\nInvalid symbol for size. Enter number!\n\n"; return 1; }
		if (N > 0 && M > 0 )
=======
		if (N > 0 && M > 0 && !cin.fail() )
>>>>>>> afdfd6fbb2a4e39dde8abc674f8c64d8b4a8ac6e
		{
			if (N % 2 != 0)
			{ checker = true; }
			else { cout << "\nN must be odd!!!\nPlease, Enter bridge size again (N and M):\t"; }
		} else { cout << "\nPlease, enter natural number for size:\t"; }
	} checker = false;
	
	cout << "\nEnter the alcohol level ([0-1]):\t";
	while (checker == false)
	{
		cin >> alc;
<<<<<<< HEAD
		if (cin.fail()) { cout << "\nERROR!!!\n\nInvalid symbol for alcohol level. Enter number!\n\n"; return 1; }
		if (alc >= 0 && alc <= 1)
		{ checker = true; }
		else { cout << "\nPlease, enter number between 0 and 1:\t"; }
	} checker = false;
	
	cout << "\nNumber of tries/simulations (S):\t";
		while (checker == false)
	{
		cin >> tries;
		if (cin.fail()) { cout << "\nERROR!!!\n\nInvalid symbol for tries. Enter number!\n\n"; return 1; }
		if (tries > 0)
		{ checker = true; }
		else { cout << "\nPlease, enter natural number for tries:\t"; }
	} checker = false;
=======
		checker = true;
	}
	
	cout << "\nNumber of tries/simulations (S):\t";
	cin >> tries;
>>>>>>> afdfd6fbb2a4e39dde8abc674f8c64d8b4a8ac6e
	
	return 0;
}
