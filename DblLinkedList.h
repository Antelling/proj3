/*!	\file DblLinkedList.h
 *	\brief Header for custom Doubly Linked List implementation.
 *	\author Anthony Dellinger
 *
 *	Contains definition and implementation of doubly linked
 *	list and doubly linked list iterator for project 2.
 */
/************************************************************/
/*   Major: Computer Science	*/
/*   Creation Date: Oct 5 2019	*/
/*   Due Date: Oct 18 2019	*/
/*   Course: CSC237	*/
/*   Professor Name: Dr. Spiegel	*/
/*   Assignment: #2a	*/
/************************************************************/

#ifndef _LinkedList_
#define _LinkedList_

#include <iostream>
#include "Node.h"

using namespace std;

/*!
 *   \class DblLink
 *   \brief A doubly linked list, holding data of type eltType, null terminated at start and end.
 *
 *   The Doubly Linked List is made up of Nodes, where each Node has a pointer to its 
 *   preceding node, successive node, and contains data of any type, as long as it is
 *   consistent within every Node. 
 */
template<typename eltType>
class DblLink {
public:
	/*!
	 * \brief Constructor for empty doubly linked list
 	*/
	DblLink();

	/*!
	 * \brief Constructor for deep copy of passed linked list
 	*/
	DblLink(DblLink &); // deep copy constructor

	/*!
	 * \brief Destructor for linked list
 	*/
	~DblLink(); //destructor

	/*!
	 * \brief deep copies right hand side of assignment to left hand side
 	*/
	DblLink &operator=(const DblLink &); //deep copy during assignment

	/*!
	 * \brief Determines if linked list is empty.
	 * \returns bool true if list is empty
 	*/
	bool empty(); //is empty?

	/*!
	 * \brief determines if passed element is in linked list
	 * \param eltType element to search for
	 * \returns bool true if linked list contains element
 	*/
	bool find(eltType); //does linked list contain element?

	/*! 
	 * \brief Insert element into linked list in sorted position.
	 * \param eltType element to insert
	 *
	 * Assumes < and > operators are implemented and consistent for eltType
	 */
	void insert(eltType); //ordered insert

	/*!
	 * \brief Remove an element from the linked list
	 * \param eltType element to remove
	 *
	 * Element to be removed must be within list.
 	*/
	void remove(eltType); //removes element

private:
	/*!
	 * \brief pointer to the first node of the linked list
	 */
	Node<eltType> *head;

	/*!
	 * \brief creates deep copy of passed link list and returns pointer to copy
	 * \param Node<eltType>* pointer to first node to copy - input
	 * \return Node<eltType>* pointer to first node   */
	Node<eltType> *copy(Node<eltType> *);

	/*!
	 * \brief destroys node and all successive nodes
	 * \param Node<eltType>* pointer to first node to destroy
	 *
	 * Function is used by destructor.
 	*/
	void destroy(Node<eltType> *);

	/*!
	 * \brief allow iterator to modify private values of the linked list
	 */
	friend class DblLinkItr<eltType>;
};

/*!
 * \class DblLinkItr
 * \brief An iterator over the elements of a DblLink instance
 * @tparam eltType
 */
template<typename eltType>
class DblLinkItr {
public:
	DblLinkItr(const DblLink<eltType> &list); //constructor

	// Set current to point at the first node of ListRef
	void start(); //initialize $current pointer to point at first element
	bool isLastNode(); //does $current point at the last node
	bool isFirstNode(); //does $current point at the first node
	void operator++(int); //postincrement operator
	void operator--(int); //postdecrement operator
	eltType operator()(); //returns value of current node
private:
	const DblLink<eltType> &ListRef; //reference to linked list being iterated over
	Node<eltType> *current; //pointer to current node
};

/*************************************************************************/
/*   \fn   DblLink<eltType>()	*/
/*   \brief   constructs empty linked list
/*************************************************************************/
template<typename eltType>
DblLink<eltType>::DblLink() : head(NULL) {}

/*************************************************************************/
/*   Function name:   DblLink<eltType>(DblLink<eltType>)	*/
/*   Description:   creates shallow copy of linked list
/*   Parameters:    DblLink<eltType> &cl - linked list to be copied */
/*************************************************************************/
template<typename eltType>
DblLink<eltType>::DblLink(DblLink<eltType> &cl) { head = copy(cl.head); }

/*************************************************************************/
/*   Function name:   ~DblLink<eltType>()	*/
/*   Description:   destroys all nodes associated with linked list
/*   Parameters:    none */
/*************************************************************************/
template<typename eltType>
DblLink<eltType>::~DblLink() { destroy(head); }

/*************************************************************************/
/*   Function name:   &DblLink<eltType>::operator =	*/
/*   Description:   assigns a shallow copy
/*   Parameters:    none */
/*************************************************************************/
template<typename eltType>
DblLink<eltType>
&DblLink<eltType>::operator=(const DblLink<eltType> &cl) {
	if (this != &cl) {
		destroy(head);
		head = copy(cl.head);
	}
	return *this;
}

/*************************************************************************/
/*   Function name:   insert	*/
/*   Description:   insert item into list.
/*   Parameters:    eltType x - value to input - input */
/*************************************************************************/
template<typename eltType>
void DblLink<eltType>::insert(eltType x) {
	if (empty() || x > head->data) {
		Node<eltType> *nn;
		nn = new Node<eltType>(x, 0, head);
		if (head) {
			head->prev = nn;
		}
		head = nn;
	} else   // start at 2nd node...already checked first node
	{
		Node<eltType> *p = head->next; // head;
		Node<eltType> *trailp = head;         // NULL;
		while (p != NULL && x < p->data) {
			trailp = p;
			p = p->next;
		}
		Node<eltType> *newNode = new Node<eltType>(x, trailp, p);
		trailp->next = newNode;
		if (p) { //p might be null
			p->prev = newNode;
		}
	}
}

/*************************************************************************/
/*   Function name:   find	*/
/*   Description:   determines if passed value is in linked list.
/*   Parameters:    eltType x - value to search for - input */
/*   Return Value:  bool - does the linked list contain the value  */
/*************************************************************************/
template<typename eltType>
bool DblLink<eltType>::find(eltType x) {
	Node<eltType> *p = head;
	while (p != NULL && !(p->data == x))
		p = p->next;
	return (p != NULL && p->data == x);
}

/*************************************************************************/
/*   Function name:   empty	*/
/*   Description:   determines if linked list is empty
/*   Parameters:    none */
/*   Return Value:  bool - is the linked list empty  */
/*************************************************************************/
template<typename eltType>
inline bool DblLink<eltType>::empty() { return (head == NULL); }

/*************************************************************************/
/*   Function name:   remove	*/
/*   Description:   removes passed value from the linked list.
/*   Precondition:  passed value is in list
/*   Parameters:    eltType x - value to remove - input */
/*   Return Value:  void - linked list is modified in place  */
/*************************************************************************/
template<typename eltType>
void DblLink<eltType>::remove(eltType x) {
	Node<eltType> *p = head;
	Node<eltType> *trailp = NULL;
	while (p != NULL && !(p->data == x)) {
		trailp = p;
		p = p->next;
	}
	if (p == head) {
		head = head->next;
		if (head) { //head may now be null
			head->prev = NULL;
		}
	} else {
		trailp->next = p->next;
		if (p->next) {
			p->next->prev = trailp;
		}
	}
	delete p;
}

/*************************************************************************/
/*   Function name:   destroy	*/
/*   Description:   destroys node and all following nodes
/*   Parameters:    Node<eltType>* listPtr - pointer to node to delete - input/output */
/*   Return Value:  void - modifies in place  */
/*************************************************************************/
template<class eltType>
void DblLink<eltType>::destroy(Node<eltType> *listPtr) {
	while (listPtr != NULL) {
		Node<eltType> *doomed = listPtr;
		listPtr = listPtr->next;
		delete doomed;
	}
}

/*************************************************************************/
/*   Function name:   copy	*/
/*   Description:   deep copy - constructs a new linked list with duplicate values
/*   Parameters:    Node<eltType> *listPtr - pointer to first node to copy - input */
/*   Return Value:  Node<eltType>* - pointer to first node   */
/*************************************************************************/
template<typename eltType>
Node<eltType> *DblLink<eltType>::copy(Node<eltType> *listPtr) {
	if (listPtr != NULL) {
		Node<eltType> *first = NULL; // ptr to beginning of copy
		Node<eltType> *last = NULL;  // ptr to last item in the copy
		first = last = new Node<eltType>(listPtr->data, NULL, NULL);
		for (Node<eltType> *source = listPtr->next; source != NULL;
			 source = source->next, last = last->next) {
			last->next = new Node<eltType>(source->data, last, NULL);
		}
		return first;
	}
	return NULL;
}


//region list iterators

/*************************************************************************/
/*   Function name:   constructor	*/
/*   Description:   construct a list iterator. Consists of a reference to a linked
 * 					list object and a pointer to a node of the list.
/*   Parameters:    const DblLink<eltType> &list - list to make iterator for */
/*   Return Value:  DblLinkItr<eltType> - iterator instance   */
/*************************************************************************/
template<typename eltType>
DblLinkItr<eltType>::DblLinkItr(const DblLink<eltType> &list):
		ListRef(list), current(NULL) {}


/*************************************************************************/
/*   Function name:   start	*/
/*   Description:   set current to point at list head
/*   Parameters:    none */
/*   Return Value:  none   */
/*************************************************************************/
template<typename eltType>
void DblLinkItr<eltType>::start(void) { current = ListRef.head; }


/*************************************************************************/
/*   Function name:   isLastNode	*/
/*   Description:   determines if current node points to last node in the list
/*   Parameters:    none */
/*   Return Value:  bool - is last node?   */
/*************************************************************************/
template<typename eltType>
bool DblLinkItr<eltType>::isLastNode(void) { return current->next == NULL; }

/*************************************************************************/
/*   Function name:   isFirstNode	*/
/*   Description:   determines if current node points to first node in the list
/*   Parameters:    none */
/*   Return Value:  bool - is first node?   */
/*************************************************************************/
template<typename eltType>
bool DblLinkItr<eltType>::isFirstNode(void) { return current->prev == NULL; }

/*************************************************************************/
/*   Function name:   postincrement	*/
/*   Description:   moves current to next node in list
/*   Precondition: is not last node
/*   Parameters:    none */
/*   Return Value:  none   */
/*************************************************************************/
template<typename eltType>
void DblLinkItr<eltType>::operator++(int) {
	current = current->next;
}

/*************************************************************************/
/*   Function name:   postdecrement	*/
/*   Description:   moves current to previous node in list */
/*   Precondition: is not first node */
/*   Parameters:    none */
/*   Return Value:  none   */
/*************************************************************************/
template<typename eltType>
void DblLinkItr<eltType>::operator--(int) {
	current = current->prev;
}

/*************************************************************************/
/*   Function name:   operator()	*/
/*   Description:   gets value of current node */
/*   Parameters:    none */
/*   Return Value:  eltType - current node's value   */
/*************************************************************************/
template<typename eltType>
eltType DblLinkItr<eltType>::operator()() {
	return current->data;
}

//endregion
#endif
