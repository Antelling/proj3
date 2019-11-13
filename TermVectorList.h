/*!
 * \file TermVectorList.h
 * \author Anthony Dellinger
 * \brief Header file for TermList subclass that uses an stl vector of Terms
 */


#ifndef TERMVECTORLIST_H
#define TERMVECTORLIST_H

#include <fstream>
#include <string>
#include <vector>
#include "TermList.h"
#include "term.h"

using namespace std;

/*!
 * \class TermVectorList
 * \brief TermList subclass that uses an stl vector
 */
class TermVectorList : public TermList {
public:

	/*!
	 * Constructor for empty TermVectorList
	 */
	TermVectorList();

	/*!
	 * \brief reads and parses a file containing a polynomial instance, and stores the polynomial in this TermVectorList
	 * @param string filename file to read
	 */
	void readIntoList(string filename);

	/*!
	 * \brief prints the polynomial by iteratively looping over it
	 */
	void printIteratively();

	/*!
	 * \brief prints the polynomial by recursively looping over it
	 */
	void printRecursively();

	/*!
	 * \brief evaluate the polynomial for a value
	 * @param x value to evaluate for
	 * @return value of result of evaluation
	 */
	virtual double operator()(double x) const;

private:
	/*!
	 * \brief the stl vector used for internal storage
	 */
	vector <Term> polyVec;
};

#endif
