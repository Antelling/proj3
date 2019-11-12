/****************************************************************/
/*   Author:         Dr. Spiegel (with thanks to Adam Tal)      */
/*   					modified by Anthony Dellinger           */
/*   Course:         CIS237                                     */
/*   Filename:       app.cpp                                    */
/*   Purpose:        This Example inputs a file name and demon- */
/*                   strates how to store it using a subclass   */
/*                   of an abstract base class that incorporates*/
/*                   virtual functions to enable polymorphism   */
/*                   If a file name is                          */
/*                   input through the command line all of the  */
/*                   options will be done automatically         */
/****************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "TermList.h"
#include "TermDblList.h"
#include "TermArrayList.h"
#include "TermVectorList.h"
// #include "WordData.h"        app only knows about the lists!

using namespace std;


/*********************************************************************/
/*   Function Name: displayFunctionMenu()                            */
/*                                                                   */
/*   Description: Displays the data structure functions on screen    */
/*********************************************************************/
void displayFunctionMenu();

/*********************************************************************/
/*   Function Name: displayDSMenu()                                  */
/*                                                                   */
/*   Description: Displays the data structure menu on the screen.    */
/*********************************************************************/
void displayDSMenu();

/*********************************************************************/
/*   Function Name: printEverything                                  */
/*                                                                   */
/*   Description: Takes in a filename and xValue and tests every     */
/*                function of the datastructure                      */
/*                                                                   */
/*   Parameters:  string fileName - file name sent to every function, input */
/*                TermList ThePoly - pointer to TermList, will be           */
/*                		replaced by datastructures, input                   */
/*                double evalX - x value to evaluate polynomials for, input */
/*********************************************************************/
void printEverything(const string &fileName, TermList *ThePoly, double evalX);

/*********************************************************************/
/*   Function Name: evalPoly                                         */
/*                                                                   */
/*   Description: Computes P(x) for variable x, supplied by the user.*/
/*                                                                   */
/*   Parameters:  TermArrayList *ThePoly - The TermList object, input*/
/*********************************************************************/
void evalPoly(TermList *ThePoly);


/*********************************************************************/
/*   Function Name: main                                               */
/*                                                                     */
/*   Description: Determines if program should be run interactively or */
/* 			in batch mode, then runs the data structures accordingly   */
/*                                                                     */
/*   Parameters:  int argc - the amount of command line args, input    */
/*                char *argv[] - list of command line arguments, input */
/*********************************************************************/
int main(int argc, char *argv[]) {
	fstream file;
	TermList *ThePoly;
	if (argc > 1) { //if there was an input on the command line
		double evalX = atof(argv[2]);
		file.open(argv[1]); //try and open the file
		if (file.fail()) {       //if the file does not open, terminate
			cout << "Sorry, the file failed to open." << endl;
			return 0;
		}
		file.close();
		string fName(argv[1]);
		printEverything(fName, ThePoly, evalX);
		return 0;
	}
	string filename;
	cout << "Enter the name of the file to read: ";
	getline(cin, filename);
	file.open(filename.c_str()); //try and open the file
	if (file.fail())       //if the file does not open, terminate
	{
		cout << "Sorry, the file failed to open." << endl;
		return 0;
	}
	file.close();

	char functionSelection;
	char DSSelection;

	while (true) {
		bool error = true;
		while (error) {
			displayDSMenu();
			cin >> DSSelection;
			// ThePoly is a pointer to a TermList that is pointed at a TermList subclass
			switch (DSSelection) {
				case '1':
					ThePoly = new TermArrayList;
					error = false;
					break;
				case '2':
					ThePoly = new TermDblList;
					error = false;
					break;
				case '3':
					ThePoly = new TermVectorList;
					error = false;
					break;
				case '4':
					cout << "Goodbye" << endl;
					return 0;
				default:
					cout << "I cannot understand " << DSSelection << ".  Try again." << endl;
					break;
			}
		}


		ThePoly->readIntoList(filename);  // Apply polymorphism
		bool cont = true;
		while (cont) {
			displayFunctionMenu();
			cin >> functionSelection;
			switch (functionSelection) {
				case '1':
					ThePoly->printIteratively();
					evalPoly(ThePoly);
					break;
				case '2':
					ThePoly->printPtr();
					evalPoly(ThePoly);
					break;
				case '3':
					ThePoly->printRecursively();
					evalPoly(ThePoly);
					break;
				case '4':
					evalPoly(ThePoly);
					break;
				case '5':
					cont = false;
					break;
				default:
					cout << "I cannot understand " << functionSelection << ".  Try again." << endl;
					break;
			}
		}
	}
}

// Displays the menu on the screen
void displayFunctionMenu() {
	cout << "------------------------------------------------\n"
			"|  Choose A Function to Execute                |\n"
			"------------------------------------------------\n"
			"1. Iterative Print\n"
			"2. Object Array Pointer Print\n"
			"3. Recursive Print\n"
			"4. Evaluate the Polynomial\n"
			"5. Return to Main Menu\n\n"
			"Choice: ";

}

// Displays the menu on the screen
void displayDSMenu() {
	cout << endl;
	cout << "------------------------------------------------\n"
			"|  Choose A Data Type to Use                   |\n"
			"------------------------------------------------\n"
			"1. Object Array\n"
			"2. Double Linked List\n"
			"3. Vector\n"
			"4. Exit\n\n"
			"Choice: ";

}

// Takes in a sentence and sends it through every parsing and printing function
void printEverything(const string &filename, TermList *ThePoly, double evalX) {
	ThePoly = new TermArrayList;
	ThePoly->readIntoList(filename);
	ThePoly->printIteratively();
	ThePoly->printPtr();
	cout << "P(" << evalX << ")=" << (*ThePoly)(evalX) << endl;

	ThePoly = new TermVectorList;
	ThePoly->readIntoList(filename);
	ThePoly->printIteratively();
	ThePoly->printPtr();
	cout << "P(" << evalX << ")=" << (*ThePoly)(evalX) << endl;

	ThePoly = new TermDblList;
	ThePoly->readIntoList(filename);
	ThePoly->printIteratively();
	ThePoly->printPtr();
	cout << "P(" << evalX << ")=" << (*ThePoly)(evalX) << endl;
}

// Computes P(x) for variable x, supplied by the user
void evalPoly(TermList *ThePoly) {
	double x;
	cout << "Enter a value x for P(x) >";
	cin >> x;
	cout << "P(" << x << ")=" << (*ThePoly)(x) << endl;
}  
