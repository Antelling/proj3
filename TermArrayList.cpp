/****************************************************************/
/*   Author:         Dr. Spiegel                                */
/*   					modified by Anthony Dellinger           */
/*   Course:         CIS237                                     */
/*   Filename:       TermArrayList.cpp                          */
/*   Purpose:        This implementation of the TermList        */
/*                   abstract class uses a c++ array filled with*/
/*                   Term instances to store the polynomial.    */
/****************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include "TermArrayList.h"
#include <algorithm>
#include <chrono>
#include <cmath>

using namespace std;

/*********************************************************************
	*   Function name:  TermArrayList
	*   Description:   TermArrayList constructor
	*********************************************************************/
TermArrayList::TermArrayList()
{ numTerms=0; }

/*********************************************************************
	*   Function name:  compareTerms
	*   Description:   determines if first term has a greater expn
 *   					than second term. Used by <algorithm> sort
	*   Parameters:  Term a - first term, input
 *   				 Term b - second term, input
	*
	*   Return Value: bool - is a > b
	*********************************************************************/
bool compareTerms(Term a, Term b) {
	return a > b;
}

/*********************************************************************
	*   Function name:  readIntoList
	*   Description:   fills in polynomial based on filename
 *   					will only fill in first 10 elements due to array size restriction
	*   Parameters:  string filename - file to parse
	*********************************************************************/
void TermArrayList::readIntoList(string filename) {
	ifstream source(filename.c_str());
	double coeff;
	int expn;
	while (source >> coeff >> expn)  {
		bool unique = true;
		for(int i = 0; i < numTerms; i++) {
			if (expn == ThePoly[i].getExponent()) {
				Term T(coeff + ThePoly[i].getCoefficient(), expn);
				ThePoly[i] = T;
				unique = false;
				break;
			}
		}
		if (unique) {
			if (numTerms <= 10) {
				Term T(coeff, expn);
				numTerms++;
				int temp = numTerms;
				ThePoly[numTerms] = T;
				numTerms = temp;
			} else {
				//we have run out of capacity
				break;
			}
		}
	}
	source.close();
	source.clear();

	//now we must sort the polynomial
	sort(ThePoly, ThePoly+numTerms, compareTerms); //compareTerms allows for descending order
}

/*********************************************************************
	*   Function name:  printIteratively
	*   Description:   prints every term of the polynomial using indexing
	*********************************************************************/
void TermArrayList::printIteratively() {
	auto begin = chrono::high_resolution_clock::now();

	cout<<"---------------------------------"<<endl;
	cout<<"|Object  Array  Iterative       |"<<endl;
	cout<<"---------------------------------"<<endl;
	for(int i=0; i<numTerms; i++) {
	  cout <<  ThePoly[i] << (i < numTerms-1?" + ":"");
	}
	cout << endl << endl;

	auto end = chrono::high_resolution_clock::now();
	auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin);
	cout << "Time taken for printing: " << ticks.count() << " microseconds.\n";
}

void arrayRecursionHelper(int i, Term* ThePoly, int numTerms) {
	cout <<  ThePoly[i] << (i < numTerms-1?" + ":"");
	if (i < numTerms-1){
		arrayRecursionHelper(i+1, ThePoly, numTerms);
	}
}

void TermArrayList::printRecursively() {
	auto begin = chrono::high_resolution_clock::now();

	cout<<"---------------------------------"<<endl;
	cout<<"|Object  Array  Recursive       |"<<endl;
	cout<<"---------------------------------"<<endl;
	arrayRecursionHelper(0, ThePoly, numTerms);
	cout << endl << endl;

	auto end = chrono::high_resolution_clock::now();
	auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin);
	cout << "Time taken for printing: " << ticks.count() << " microseconds.\n";
}


/*********************************************************************
	*   Function name:  printPtr
	*   Description:   prints every term of the polynomial using pointer arithmetic
	*********************************************************************/
void TermArrayList::printPtr() {
	auto begin = chrono::high_resolution_clock::now();

	cout<<"---------------------------------"<<endl;
	cout<<"|Object  Array  Pointer         |"<<endl;
	cout<<"---------------------------------"<<endl;
	Term *now=ThePoly;
	for(int i=0; i<numTerms; i++) {
		cout << " " << *(now++) << (i < numTerms - 1 ? " +" : "");
	}
	cout << endl << endl;

	auto end = chrono::high_resolution_clock::now();
	auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin);
	cout << "Time taken for printing: " << ticks.count() << " microseconds.\n";
}

/*********************************************************************
	*   Function name:  TermArrayList () operator
	*   Description:   evaluates polynomial for given x value
	*   Parameters:  double x - value to fill in, input
	*
	*   Return Value: double - result of evaluation
	*********************************************************************/
double TermArrayList::operator()(double x) const {
	double result=0.0;
	for (int idx=0; idx<numTerms; idx++) {
		result += ThePoly[idx](x);
	}
	return(result);
}

