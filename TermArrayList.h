/****************************************************************/
/*   Author:         Dr. Spiegel                                */
/*   Course:         CSC237                                     */
/*   Filename:       TermArrayList.h                            */
/*   Purpose:        This subclass of the TermList              */
/*                   abstract class uses a c++ array filled with*/
/*                   Term instances to store the polynomial.    */
/****************************************************************/


#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <fstream>
#include <string>
#include "TermList.h"
#include "term.h"

using namespace std;

class TermArrayList : public TermList {
public:

  TermArrayList();

  // Put a string of strings into the list object
  //void readIntoList(ifstream &source);
  void readIntoList(string filename);

  // Print the data iteratively
  void printIteratively();

    // Print the data recursively
    void printRecursively();
  
  // Print the data recursively with a pointer
  void printPtr();

  // Evaluate the Polynomial
  virtual double operator()(double x) const;

private:
  Term ThePoly[10];
  int numTerms;
  
};
  
#endif
