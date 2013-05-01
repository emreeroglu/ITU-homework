/***************************************************************************
* Homework: 3                                                              *
* Misspelled words                                                         *
* Emin Mastizada | 150120914                                               *
***************************************************************************/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

/*** Global Variables ***/
	const int del = 2;
	const int ins = 2;
	const int subn = 3;
	const int subt = 4;

bool isVowel(string l)
{
	if(l == "a" || l == "e" || l == "i" || l == "o" || l == "u")
	{ return true; }
	else { return false; }
}

int main(int argc, char* argv[])
{
	int M, N, i, j, x, y, z, a;
	string W1,W2,l1, l2;
	
	if (argc == 3)	/// Homework says we have to work with two words.
	{
		W1 = argv[1];	/// Assign 1st word to W1
		W2 = argv[2];	/// Assign 2nd word to W2
		M = W1.length();	/// Length of 1st word
		N = W2.length();	/// Length of 2nd word
		W1 = "#" + W1;
		W2 = "#" + W2;
		int CostM[M+1][N+1];
		CostM[0][0] = 0;		/// Assign CostM[0][0]
		
		for (i = 1; i <= M; i++)
		{ CostM[i][0] = CostM[i-1][0] + ins; }	/// Assign CostM[i][0]
		
		for (j = 1; j <=N; j++)
		{ CostM[0][j] = CostM[0][j-1] + del; }	/// Assign CostM[0][j]
		
		for (i = 1; i <= M; i++)
		{
			for (j = 1; j <= N; j++)
			{
					x = CostM[i-1][j] + ins;
					y = CostM[i][j-1] + del;
					l1 = W1[i];	/// Current letter
					l2 = W2[j];	/// Current letter
				
					if(l1 == l2)
					{
						z = CostM[i-1][j-1];
					}
					else if( isVowel(l1) && isVowel(l2) )	/// Both letters are vowel
					{
						z = CostM[i-1][j-1] + subn;
					} else if( !isVowel(l1) && !isVowel(l2) )	/// Both letters are consonant
					{
						z = CostM[i-1][j-1] + subn;
					} else {
						z = CostM[i-1][j-1] + subt;
					}
					
					a = min(x,y);
					CostM[i][j] = min(a,z);
			}
		}
		cout << "Minimum cost: " << CostM[M][N] << endl;
		cout << "The Matrix:" <<endl<<endl;
		for(i=0; i<=M; i++) {
			for(j=0; j <=N; j++)
			{
				l1 = W1[i];
				l2 = W2[j];
				/// Debugging: cout << i << ":" << j << " " << l1 << ":" << l2 << " ";
				cout << CostM[i][j] << "\t";
			}
			cout << endl;
		}
		
	} else {
		cout << "\nThis program can calculate only with 2 words." << endl;
	}
	
	return 0;
}
