/*!
 * \brief TermList abstract class
 * \author Dr. Spiegel
 *
 * Prototypes readIntoList, printIteratively, printRecursively, printPtrs, and the () operator.
 * Known sublcasses: TermArrayList, TermVectorList, TermDblList
 */

#ifndef TERMLIST_H
#define TERMLIST_H

#include <fstream>
#include <string>

using namespace std;

class TermList {
public:

	/*!
	 * \brief opens and reads a file containing a polynomial, then parses and stores the polynomial
	 * @param string filename to open
	 */
	virtual void readIntoList(string filename) = 0;

	/*!
	 * \brief prints the polynomial by iteratively looping over it
	 */
	virtual void printIteratively() = 0;

	/*!
	 * \brief prints the polynomial by recursively looping over it
	 */
	virtual void printRecursively() = 0;

	/*!
	 * \brief prints the polynomial by looping using pointer arithmetic
	 *
	 * Only available in subclasses that represent data with pointers.
	 */
	virtual void printPtr() {}

	/*!
	 * \brief evaluates the polynomial for a value
	 * @param double x value to evaluate for
	 * @return value of result of evaluation
	 */
	virtual double operator()(double x) const = 0;

};

#endif
