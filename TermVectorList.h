/****************************************************************/
/*   Author:         Anthony Dellinger, modified from Dr. Spiegel's template */
/*   Course:         CSC237                                       */
/*   Filename:       TermVectorList.h                             */
/*   Purpose:        This subclass of the TermList                */
/*                   abstract class uses an stl vector with       */
/*                   Term instances to store the polynomial.      */
/****************************************************************/


#ifndef TERMVECTORLIST_H
#define TERMVECTORLIST_H

#include <fstream>
#include <string>
#include <vector>
#include "TermList.h"
#include "term.h"

using namespace std;

class TermVectorList : public TermList {
public:

  TermVectorList();

  // Put a string of strings into the list object
  //void readIntoList(ifstream &source);
  void readIntoList(string filename);

  // Print the data iteratively
  void printIteratively();

    // Print the data recursively
    void printRecursively();

  // Evaluate the Polynomial
  virtual double operator()(double x) const;

private:
  vector<Term> polyVec;
};
  
#endif
