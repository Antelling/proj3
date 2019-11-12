/****************************************************************/
/*   Author:         Anthony Dellinger, modified from Dr. Spiegel's template */
/*   Course:         CSC237                                       */
/*   Filename:       TermDblList.h                                */
/*   Purpose:        This subclass of the TermList                */
/*                   abstract class uses a double linked list with*/
/*                   Term instances to store the polynomial.      */
/****************************************************************/


#ifndef TERMDBLLIST_H
#define TERMDBLLIST_H

#include <fstream>
#include <string>
#include "TermList.h"
#include "term.h"
#include "DblLinkedList.h"

using namespace std;

class TermDblList : public TermList {
public:

	TermDblList();

	// Put a string of strings into the list object
	//void readIntoList(ifstream &source);
	void readIntoList(string filename);

	// Print the data iteratively
	void printIteratively();

	//print the data recursively
	void printRecursively();

	// Evaluate the Polynomial
	virtual double operator()(double x) const;

private:
	DblLink<Term> llist;
	bool tester;
};

#endif
