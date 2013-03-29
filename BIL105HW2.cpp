/***************************************************************************
* Homework: 2                                                              *
* Crossing the Bridge                                                      *
* Emin Mastizada | 150120914                                               *
***************************************************************************/

#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

/** Global Variables: **/
int x, y;
double c_straight, s_straight, c_side, s_center;	///Moves

bool passed(double p, int center, int M, int N)
{
	if (y >= (M - 1))	///Passed
		return true;
    if (x >= N || x < 0)
		return false;	///Falled
	double a = ((double) rand() / (RAND_MAX));
	/** Debug: cout << a << endl; **/
	if (x == center)	///On Center
	{
		if (a <= c_side) {y++;}	///Straight Step
		else if (a <= c_side) {x--; y++;}	///Left Turn
		else {x++; y++;}	///Right Move
	} else {	///On Side
		if (a <= s_center)	///Move to Center
		{
			if (x < center) {x++; y++;}
			else {x--; y++;}
		}
		else if (a <= s_straight) {y++;}
		else {
			if (x < center) {x--; y++;}
			else {x++; y++;}
		}
	}
	return true;
}

void Calculate(int N, int M, double p, int tries)	///getting alc as p
{
	int fall = 0;	///We falled
	int i,e;
	const int center = (N - 1) / 2;		///Center Point
	/** Move Probability **/
	/** Center **/
	c_straight = 1 - 2 * p / 3;
	c_side = c_straight + p / 3;
	/** Side **/
	s_center = (5 - 3 * p) / 6;
	s_straight = s_center + (1 + p) / 6;
	
	for (i=0; i < tries; i++)
	{
		x = center;	///Center
		y = 0;		///Start Point
		for (e=0; e < M; e++)
		{
			if (!passed(p, center, M, N))	///Not Passed - Falled
			{ fall++; break; }
		}
	}
	cout << tries - fall << " out of " << tries << " tries was successful at crossing the bridge\n";
	cout << "Probability = " << (tries - fall) * 1.0 / tries << endl;	/// *1.0 is for converting from integer to double
}

int main()
{
	int N, M, tries;
	double alc;
	bool checker;
	srand(time(NULL));
	
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
