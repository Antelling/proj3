/*!
 * \file TermArrayList.h
 * \author Dr. Spiegel
 * \brief TermList subclass that uses C++ Array
 *
 * This subclass of the TermList abstract class uses a c++ array filled with Term instances to store the polynomial.
 */

#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <fstream>
#include <string>
#include "TermList.h"
#include "term.h"

using namespace std;

/*!
 * \class TermArrayList
 * \brief TermList subclass that uses C++ Array
 *
 * Has a maximum capacity of 10 elements.
 */
class TermArrayList : public TermList {
public:

	/*!
	 * \brief Constructor for empty TermArrayList
	 */
	TermArrayList();

	/*!
	 * \brief reads and parses a file containing a polynomial instance, and stores the polynomial in TermArrayList
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
	 * Print the data by looping using pointer arithmetic.
	 */
	void printPtr();

	/*!
	 * \brief evaluate the polynomial for a value
	 * @param x value to evaluate for
	 * @return value of result of evaluation
	 */
	virtual double operator()(double x) const;

private:
	/*!
	 * \brief internal storage array
	 */
	Term ThePoly[10];

	/*!
	 * \brief internal storage of current length of Term array
	 */
	int numTerms;

};

#endif
