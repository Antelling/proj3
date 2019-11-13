/*! \file Node.h
 * \brief Header and implementation of Node used in Dbl
 * \author Dr. Speigel
 *
 * Definition and implementation of Node class used by doubly linked list.
 */
/****************************************************************/
/*   Course:         CSC237                                     */
/*   Filename:       Node.h                                     */
/****************************************************************/

#ifndef NODE_H
#define NODE_H

//using namespace std;

// Need to prototype template classes if they are to be friends
template <class eltType> class DblLink;
template <class eltType> class DblLinkItr;


/*!
 * @class Node
 * @tparam eltType datatype to store in Linked List
 * \brief the Node used in DblLinkedList, has a forward and reverse pointer
 */
template <class eltType> class Node
{	private:
		/*!
		 * \brief Constructor for Node
		 * @param info data to store
		 * @param pLink link to previous Node in linked list
		 * @param rLink link to next Node in linked list
		 */
		Node(eltType info, Node *pLink = 0, Node *rLink=0) 
				   : data(info), prev(pLink), next(rLink) {};

		/*!
		 * \brief internal storage of data Node is meant to hold
		 */
		eltType data;

		/*!
		 * \brief pointer to previous node
		 */
		Node*	prev;

		/*!
		 * \brief pointer to next node
		 */
		Node*	next;

	/*!
	 * \brief allow DblLink to get internal data and modify values
	 */
	friend class DblLink<eltType>;

	/*!
	 * \brief allow DblLinkItr to reference data of Node
	 */
	friend class DblLinkItr<eltType>;
};

#endif

