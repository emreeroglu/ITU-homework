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
		if (N > 0 && M > 0 && !cin.fail() )
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
		checker = true;
	}
	
	cout << "\nNumber of tries/simulations (S):\t";
	cin >> tries;
	
	return 0;
}
