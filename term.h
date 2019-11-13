/*!
 * \file term.h
 * \author Dr. Spiegel
 * \brief A Term holds one term of a polynomial. A term can be created, evaluated, compared, and printed.
 */

#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

/*!
 * \class Term
 * \brief Class that holds a singly polynomial term.
 *
 * Will store the coefficient and exponent, and has functions to compare two terms.
 */
class Term
{
public:
	/*!
	 * \brief Constructor for Term
	 * \param double coefficient to store in term, defaults to 0
	 * \param int exponent to store in term, defaults to 0
	 */
	Term(double=0, int=0);

	//Gets (No sets in immutable object)
	/*!
	 * \brief get the coefficient of the Term
	 * \returns value of coefficient
	 */
	double getCoefficient() const;

	/*!
	 * \brief get the exponent of the Term
	 * @return value of the exponent
	 */
	int getExponent() const;

	/*!
	 * \brief evaluate Term for x value
	 * @param x value to evaluate for
	 * @return value of result of Term evaluation
	 */
	double operator()(double x) const; 	// evaluation of term

	/*!
	 * \brief does exponent match the int parameter?
	 * @param int value to compare with Term exponent
	 * @return bool true if match else false
	 */
	bool operator==(int value);

	/*!
	 * \brief does exponent of Term parameter match this exponent?
	 * @param right Term to compare
	 * @return bool true if match else false
	 */
	bool operator==(const Term &right);

	/*!
	 * \brief is this Term's exponent less than the rights?
	 * @param right Term to compare exponent to
	 * @return bool true if this Term's exponent is less than right Term's exponent
	 */
	bool operator<(Term &right);

	/*!
	 * \brief is this Term's exponent less than right?
	 * @param right int to compare exponent to
	 * @return bool true if the Term's exponent is less than the passed int
	 */
	bool operator<(int right);

	/*!
	 * \brief is this Term's exponent greater than right's?
	 * @param right Term to compare exponent to
	 * @return bool true if this Term's exponent is greater than right Term's exponent
	 */
	bool operator>(Term &right);


	/*!
	 * \brief is this Term's exponent less than right?
	 * @param right int to compare exponent to
	 * @return bool true if the Term's exponent is greater than the passed int
	 */
	bool operator>(int right);

private:
	/*!
	 * \brief holds the coefficient value
	 */
	double coefficient;

	/*!
	 * \brief holds the exponent value
	 */
	int exponent;

};

/*!
 * \brief overide stream insert to pretty format Term
 * @param output stream to insert values to
 * @param Term to pretty format
 * @return output, to enable cascading
 */
ostream &operator<<(ostream &output,const Term &term);
#endif
