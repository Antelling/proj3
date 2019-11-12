/************************************************************/
/*   Author: Anthony Dellinger */
/*   Major: Computer Science	*/
/*   Creation Date: Oct 5 2019	*/
/*   Due Date: Oct 18 2019	*/
/*   Course: CSC237	*/
/*   Professor Name: Dr. Spiegel	*/
/*   Assignment: #2a	*/
/*   Filename: testLL.cpp	*/
/*   Purpose: Driver program for doubly linked list implementation.	*/
/*   Provides option to add an element, remove an element, display the	*/
/*   list forwards, display the list backwards, or quit.	*/
/************************************************************/

#include "DblLinkedList.h"
using namespace std;

/*************************************************************************/
/*   Function name:   getMenuOptions	*/
/*   Description:   Displays option to add, remove, print forwards, print backwards, or quit to user. */
/*   Parameters:    none */
/*   Return Value:  int - value of what menu item the user selected:
 * 		1 - insert
 * 		2 - remove
 * 		3 - print forwards
 * 		4 - print backwards
 * 		any other value - quit*/
/*************************************************************************/
int getMenuOptions();

/*************************************************************************/
/*   Function name:   insertCase	*/
/*   Description:   Called when the user chooses the insertion case. Prompts for a value and inserts
 * 					into the passed link list. */
/*   Parameters:    &llist - reference to the linked list to modify - input/output */
/*   Return Value:  void */
/*************************************************************************/
void insertCase(DblLink<int> &llist);

/*************************************************************************/
/*   Function name:   removeCase	*/
/*   Description:   Called when the user chooses the removal case. Prompts for a value,
 * 					and if the value is in the list, removes the value.
/*   Parameters:    &llist - reference to the linked list to modify - input/output */
/*   Return Value:  void */
/*************************************************************************/
void removeCase(DblLink<int> &llist);

/*************************************************************************/
/*   Function name:   printForward	*/
/*   Description:   Prints the passed link list in order of the elements.
/*   Parameters:    &llist - reference to the linked list to print - input */
/*   Return Value:  void */
/*************************************************************************/
void printForward(DblLink<int> &llist);

/*************************************************************************/
/*   Function name:   printForward	*/
/*   Description:   Prints the passed link list in reverse order of the elements.
/*   Parameters:    &llist - reference to the linked list to print - input */
/*   Return Value:  void */
/*************************************************************************/
void printBackward(DblLink<int> &llist);

/*************************************************************************/
/*   Function name:   main	*/
/*   Description:   Continually prompts user for action, and then dispatches action on  linked list.
/*   Parameters:    none */
/*   Return Value:  int - status flag, returns 0 on intended exit.  */
/*************************************************************************/
int main() {
	bool cont = true;
	DblLink<int> llist;
	while (cont) {
		int option = getMenuOptions();
		switch (option) {
			case 1:
				insertCase(llist);
				break;
			case 2:
				removeCase(llist);
				break;
			case 3:
				printForward(llist);
				break;
			case 4:
				printBackward(llist);
				break;
			default:
				cont = false;
		}
	}
	return 0;
}

int getMenuOptions() {
	cout << "==========================\n"
			"1:  Insert    \n"
			"2:  Remove    \n"
			"3:  Print forward\n"
			"4:  Print backward\n"
			"5:  Exit      \n"
			"==========================\n"
			"Enter Selection: ";
	int choice;
	cin >> choice;
	return choice;
}

void insertCase(DblLink<int> &llist) {
	cout << "Insert what? ";
	int insert;
	cin >> insert;
	llist.insert(insert);
};

void removeCase(DblLink<int> &llist) {
	cout << "Remove what?: ";
	int remove;
	cin >> remove;
	if(!llist.find(remove)) {
		cout << "That isn't in the list. \n";
	} else {
		llist.remove(remove);
	}
};

void printForward(DblLink<int> &llist) {
	if(llist.empty()) {
		cout << "The list is empty.\n";
		return;
	}
	DblLinkItr<int> itr = DblLinkItr<int>(llist);
	itr.start();
	while(true) {
		cout << itr() << " ";
		if(itr.isLastNode()) break;
		itr++;
	}
	cout << "\n";
};

void printBackward(DblLink<int> &llist) {
	if(llist.empty()) {
		cout << "The list is empty.\n";
		return;
	}
	DblLinkItr<int> itr = DblLinkItr<int>(llist);
	itr.start();
	while(!itr.isLastNode()) {
		itr++;
	}
	while(true) {
		cout << itr() << " ";
		if(itr.isFirstNode()) break;
		itr--;
	}
	cout << "\n";
};