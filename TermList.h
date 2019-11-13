/****************************************************************/
/*   Author:         Dr. Spiegel                                     */
/*   Course:         CSC237                                          */
/*   Filename:       TermList.h                                      */
/*   Purpose:        Abstract base class for containers of Terms     */
/*   Known subclasses:   TermArrayList, TermVectorList, TermDblList  */
/****************************************************************/
// File: TermList.h
// Abstract base class for containers of Terms
// Known subclasses:
//      TermArray
// Coming soon: ParallelArrayTermList, TermVectorList, ...

#ifndef TERMLIST_H
#define TERMLIST_H

#include <fstream>
#include <string>

using namespace std;

class TermList {
public:

  // Place the line of text into the data structure
  virtual void readIntoList(string filename)=0;
  //
    /*!
     * \brief prints the polynomial by iteratively looping over it
     */
  virtual void printIteratively()=0;

  // Print the data recursively
  virtual void printRecursively()=0;

  // Print the data Iteratively with a pointer
  /*!
   * \brief prints the polynomial by looping using pointer arithmetic
   *
   * Only available in subclasses that represent data with pointers.
   */
  virtual void printPtr() {}

  // Evaluate the Polynomial
  virtual double operator()(double x) const=0;
    
};
  
#endif
