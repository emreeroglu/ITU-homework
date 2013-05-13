/***************************************************************************
* Homework: 4                                                              *
* Silhouette Puzzle	                                                       *
* Emin Mastizada | 150120914                                               *
***************************************************************************/
/*     Example: http://web.itu.edu.tr/~mastizada/bil105e/hw4/bina.php	  */

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>

using namespace std;

/* Global Variables */
int M, N;
string vp;

	int M2 = M + 15;	/// Don't know why, but it works :)
	int N2 = N + 15;	/// M+1 not working!!!
	int *map = new int[M2*N2];	///Allocate memory
	int *map2 = new int[M2*N2];	///Allocate memory
	int *result = new int[M2*N2];	///Will it ever end?
	int *high = new int[M2*N2];		///AAAHHHKKKHHHKH

void GetSize()
{
	bool check = false;
	while(!check)
	{
		cin >> M;
		if(!cin.fail()) {
			cin >> N;
			if(!cin.fail()) {
				cin >> vp;
				if(!cin.fail()) {
					if(vp=="N" || vp=="S" || vp=="E" || vp=="W") {check=true;}
					else {cout << "Error for view point!!!\nPlease, enter one of this selections: [N, S, E, W]\n\nEnter dimensions of block and view point: ";}
				} else {cin.clear(); cin.ignore(7777,'\n'); cout << "Input Error!!!\nTry Again\n\nEnter dimensions of block and view point: ";}
			} else {cin.clear(); cin.ignore(7777,'\n'); cout << "Input Error!!!\nTry Again\n\nEnter dimensions of block and view point: ";}
		} else {cin.clear(); cin.ignore(7777,'\n'); cout << "Input Error!!!\nTry Again\n\nEnter dimensions of block and view point: ";}
	}
}

bool in_array(int search, int j) {
	for(int i=1; i<=M; i++) {
		if(*(result + (j*N + i)) == search) {
		return true;
		}
	}
	return false;
}

int main()
{
	int i, j, got;
	
	cout << "Enter dimensions of the city block and view point [N, S, E, W] : ";
	GetSize();

	cout << "Enter heights of the buildings: ";
	
	for(i=1; i<=M; i++) {
		for(j=1; j<=N; j++) {
			bool check = false;
			while(!check)
			{
				cin >> got;
				if(!cin.fail()){
					if(got >= 0) {check = true;}
					else {cin.clear(); cin.ignore(7777,'\n'); cout << "\nError, height can be positive or zero\n";}
				} else {cin.clear(); cin.ignore(7777,'\n'); cout << "\nError, height must be shown with numbers!!!\n";}
			}
			*(map + (i*N + j)) = got;
		}
	}
	cout << "\n";
	if(vp=="N") {		/// North ViewPoint
		for(i=1; i<=M; i++) {
			for(j=1; j<=N; j++) {
				*(map2 + (i*N + j)) = *(map + (i*N + j));
			}
		}
	}
	else if(vp=="S") {
		for(i=1; i<=M; i++) {
			for(j=0; j<N; j++) {
				*(map2 + ((j+1)*N + i)) = *(map + ((N-j) * N + i));
			}
		}
	}
	else if(vp=="W") {
		for(i=0; i<=M; i++) {
			for(j=0; j<N; j++) {
				*(map2 + ((i+1) * N + (j+1))) = *(map + ((N-j) * N + (i+1)));
			}
		}
	}
	else if(vp=="E") {
		for(i=0; i<=M; i++) {
			for(j=0; j<N; j++) {
				*(map2 + ((i+1) * N + (j+1))) = *(map + ((j+1) * N + (M-i)));
			}
		}
	}

	int total=0;
	int num=0;
	int highest = 0;
	int now;
	for(j=1; j<=N; j++) {
		*(high +j)=0;
		for(i=1; i<=M; i++) {
			now = *(map2 + (i*N + j));
			if(now > highest) {highest=now;}
			if(now > *(high +j)) {*(high + j)=now; *(result + (j*N + i))=now; total+= *(map2 + (i*N+j)); num++;}
		}
	}
	
	for(i=highest; i>0; i--){	/// Lets Print owr Buildings :)
		for(j=1; j<=N; j++) {
			if(i > *(high + j)) {
				cout << " ";
			} else if(in_array(i, j)) {cout << "^";}
			else {cout << "#";}
			cout << "\t";
		} cout << "\n";
	}

	cout << "\n";
	cout.setf(ios::fixed);
	cout << "Average height: " << setprecision(3) << (double) total/num << endl;
	/* Debugging:
	cout << "\n\n\n";
	for(i=1; i<=M; i++){
		for(j=1; j<=N; j++){
			cout << *(map2 + (i*N +j));
		} cout << "\n";
	} */

	delete[] map;
	map = NULL;
	delete[] map2;
	map2 = NULL;
	delete[] result;
	result = NULL;
	delete[] high;
	high = NULL;

	return 0;
}
