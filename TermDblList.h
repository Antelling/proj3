/*!
 * \file TermDblList.h
 * \author Anthony Dellinger
 *
 * \brief Header file for TermList subclass that uses doubly linked list.
 *
 * This subclass of the TermList abstract class uses a doubly linked list filled with Term instances to store the polynomial.
 */


#ifndef TERMDBLLIST_H
#define TERMDBLLIST_H

#include <fstream>
#include <string>
#include "TermList.h"
#include "term.h"
#include "DblLinkedList.h"

using namespace std;

/*!
 * \class TermDblList
 * \brief TermList subclass that uses doubly linked list
 */
class TermDblList : public TermList {
public:

	/*!
	 * Constructor for empty TermDblList
	 */
	TermDblList();

	/*!
	 * \brief reads and parses a file containing a polynomial instance, and stores the polynomial in this TermDblList
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
	 * \brief The linked list used for internal storage.
	 */
	DblLink<Term> llist;
};

#endif
