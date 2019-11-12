/****************************************************************/
/*   Author:         Anthony Dellinger                          */
/*   Course:         CSC237                                     */
/*   Filename:       TermDblList.cpp                            */
/*   Purpose:        This implementation of the TermList        */
/*                   abstract class uses doubly linked list with*/
/*                   Term instances to store the polynomial.    */
/****************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include "TermDblList.h"
#include <chrono>
#include <cmath>

using namespace std;

/*********************************************************************
	*   Function name:  TermDblList
	*   Description:   TermDblList constructor
	*********************************************************************/
TermDblList::TermDblList() {}

/*********************************************************************
	*   Function name:  readIntoList
	*   Description:   fills in polynomial based on filename
	*   Parameters:  string filename - file to parse
	*********************************************************************/
void TermDblList::readIntoList(string filename) {
	ifstream source(filename.c_str());
	double coeff;
	int expn;
	while (source >> coeff >> expn)  {
		bool unique = true;
		DblLinkItr<Term> it = DblLinkItr<Term>(llist);
		it.start();
		while(!llist.empty()) {
			if (expn == (it()).getExponent()) {
				Term T(coeff + (it()).getCoefficient(), expn);
				llist.remove(T);
				llist.insert(T);
				unique = false;
				break;
			}
			if(it.isLastNode()) break;
			it++;
		}
		if (unique) {
			Term T(coeff, expn);
			llist.insert(T);
		}
	}
	source.close();
	source.clear();
}

/*********************************************************************
	*   Function name:  printIteratively
	*   Description:   prints every term of the polynomial using a list iterator
	*********************************************************************/
void TermDblList::printIteratively() {
	auto begin = chrono::high_resolution_clock::now();

	cout<<"---------------------------------"<<endl;
	cout<<"|Object Linked List Iterative   |"<<endl;
	cout<<"---------------------------------"<<endl;

	if(llist.empty()) {
		cout << "The list is empty.\n";
		return;
	}
	DblLinkItr<Term> itr = DblLinkItr<Term>(llist);
	itr.start();
	while(true) {
		cout << itr();
		if(itr.isLastNode()) { break; }
		else { cout << " + "; }
		itr++;
	}
	cout << "\n\n";

	auto end = chrono::high_resolution_clock::now();
	auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin);
	cout << "Time taken for printing: " << ticks.count() << " microseconds.\n";
}

//FIXME:make docstrings
void DLLRecursionHelper(DblLinkItr<Term> itr) {
	cout << itr();
	if(itr.isLastNode()) { return; }
	else { cout << " + "; }
	itr++;
	DLLRecursionHelper(itr);
}

/*********************************************************************
	*   Function name:  printRecursively
	*   Description:   prints every term of the polynomial using recursion
	*********************************************************************/
void TermDblList::printRecursively() {
	auto begin = chrono::high_resolution_clock::now();

	cout<<"---------------------------------"<<endl;
	cout<<"|Object Linked List Recursive   |"<<endl;
	cout<<"---------------------------------"<<endl;

	if(llist.empty()) {
		cout << "The list is empty.\n";
		return;
	}
	DblLinkItr<Term> itr = DblLinkItr<Term>(llist);
	itr.start();
	DLLRecursionHelper(itr);
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
double TermDblList::operator()(double x) const {
	double result=0.0;
	DblLinkItr<Term> itr = DblLinkItr<Term>(llist);
	itr.start();
	while(true) {
		result += itr()(x);
		if(itr.isLastNode()) { break; };
		itr++;
	}
	return result;
}