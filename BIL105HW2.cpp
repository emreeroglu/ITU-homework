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

void Calculate(int N, int M, double alc, int tries)
{
	double x, y, z;	///Counting Chance to know in which way we will move
	int start,position,i, a;
	int fall = 0;
	int success = 0;
	int center = (N+1) / 2;
	int mcenter = -1 * center;
	position = 0;	///Our Position - 0 is center
	
	for (i = 1; i <= tries; i++)
	{
		for(start = 1; start <= M; start++)
		{
			if (position == 0)		///We are in Center
			{
				x = 1 - 2 * alc / 3;	///straight step
				y = alc / 3;			///Shifting side
				if (x < y) {		///Move left or right
					srand(time(NULL));
					a = rand() % 2;
					switch(a) {
						case 0: position--; break;
						case 1: position++; break;
					}
				}
			} else {	///Not Center
				x = (5 - 3 * alc) / 6;	///straight step
				y = (1 + alc) / 6;		///Shifting to center
				z = alc / 3;			///Shifting against of center
				if (y > x && y > z)
				{
					if (position > 0) { position--; }
					else if (position < 0) { position++; }
				}
				if (z > y && z > x)
				{
					if (position > 0) { position++; }
					else if (position < 0) { position--; }
				}
			}
			if ( position > center || position < mcenter)	///Fall
			{
				start = 1;	///Return back to start
				i++;	/// 1 try loosed
				fall++;	///Falling counter
			}
		}
		success++;	///Success counter
	}
	cout << "\nTries: " << tries << "\nSuccess: " << success << "\nFalled: " << fall;
	cout << "\nTries - Falled = Success: " << tries << " - " << fall << " = " << tries - fall <<endl;
}

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
		if (cin.fail()) { cout << "\nERROR!!!\n\nInvalid symbol for size. Enter number!\n\n"; return 1; }
		if (N > 0 && M > 0 )
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
	}
	Calculate(N, M, alc,tries);
	
	return 0;
}
