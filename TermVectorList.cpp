/****************************************************************/
/*   Author:         Anthony Dellinger                          */
/*   Course:         CSC237                                     */
/*   Filename:       TermVectorList.cpp                         */
/*   Purpose:        This implementation of the TermList        */
/*                   abstract class uses a stl vector with      */
/*                   Term instances to store the polynomial.    */
/****************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include "TermVectorList.h"
#include <algorithm>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;

/*********************************************************************
	*   Function name:  TermVectorList
	*   Description:   TermVectorList constructor
	*********************************************************************/
TermVectorList::TermVectorList() {}


/*********************************************************************
	*   Function name:  compareVectorTerms
	*   Description:   determines if first term has a greater expn
 *   					than second term. Used by <algorithm> sort
	*   Parameters:  Term a - first term, input
 *   				 Term b - second term, input
	*
	*   Return Value: bool - is a > b
	*********************************************************************/
bool compareVectorTerms(Term a, Term b) {
	return a > b;
}

/*********************************************************************
	*   Function name:  readIntoList
	*   Description:   fills in polynomial based on filename
	*   Parameters:  string filename - file to parse
	*********************************************************************/
void TermVectorList::readIntoList(string filename) {
	ifstream source(filename.c_str());
	double coeff;
	int expn;
	while (source >> coeff >> expn)  {
		bool unique = true;
		for(vector<Term>::iterator it = polyVec.begin(); it != polyVec.end(); it++) {
			if (expn == it->getExponent()) {
				Term T(coeff + it->getCoefficient(), expn);
				*it = T;
				unique = false;
				break;
			}
		}
		if (unique) {
			Term T(coeff, expn);
			polyVec.push_back(T);
		}
	}
	source.close();
	source.clear();

	//now we must sort the polynomial
	sort(polyVec.begin(), polyVec.end(), compareVectorTerms); //compareTerms allows for descending order
}

/*********************************************************************
	*   Function name:  printIteratively
	*   Description:   prints every term of the polynomial using an iterator
	*********************************************************************/
void TermVectorList::printIteratively() {
	auto begin = chrono::high_resolution_clock::now();

	cout<<"---------------------------------"<<endl;
	cout<<"|Object Vector Iterative         |"<<endl;
	cout<<"---------------------------------"<<endl;
	for(vector<Term>::iterator it = polyVec.begin(); it != polyVec.end()-1; it++) {
		cout << *it << " + ";
	}
	cout << polyVec.back() << "\n\n";

	auto end = chrono::high_resolution_clock::now();
	auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin);
	cout << "Time taken for printing: " << ticks.count() << " microseconds.\n";
}

//fixme make docstrings
void VectorRecursionHelper(vector<Term>::iterator current, vector<Term>::iterator last) {
	cout << *current;
	if(current != last-1) {
		cout << " + ";
		current++;
		VectorRecursionHelper(current, last);
	}
}

void TermVectorList::printRecursively(){
	auto begin = chrono::high_resolution_clock::now();

	cout<<"---------------------------------"<<endl;
	cout<<"|Object Vector Recursive         |"<<endl;
	cout<<"---------------------------------"<<endl;
	VectorRecursionHelper(polyVec.begin(), polyVec.end());
	cout << "\n\n";

	auto end = chrono::high_resolution_clock::now();
	auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin);
	cout << "Time taken for printing: " << ticks.count() << " microseconds.\n";
}

/*********************************************************************
	*   Function name:  TermDblList () operator
	*   Description:   evaluates polynomial for given x value
	*   Parameters:  double x - value to fill in, input
	*
	*   Return Value: double - result of evaluation
	*********************************************************************/
double TermVectorList::operator()(double x) const {
	double result=0.0;
	for(vector<Term>::const_iterator it = polyVec.begin(); it != polyVec.end(); it++) {
		result += (*it)(x);
	}
	return result;
}

