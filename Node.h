/*!
 * \brief Header and implementation of Node used in Dbl
 */

/****************************************************************/
/*   Author:         Dr. Spiegel                                */
/*   Course:         CSC237                                     */
/*   Filename:       Node.h                                     */
/*   Purpose:        Definition and implementation of Node class
 * 					 used by doubly linked list                 */
/****************************************************************/

#ifndef NODE_H
#define NODE_H

//using namespace std;

// Need to prototype template classes if they are to be friends
template <class eltType> class DblLink;
template <class eltType> class DblLinkItr;

template <class eltType> class Node
{	private:
		Node(eltType info, Node *pLink = 0, Node *rLink=0) 
				   : data(info), prev(pLink), next(rLink) {};
		eltType data;
		Node*	prev; 
		Node*	next;
	friend class DblLink<eltType>;
	friend class DblLinkItr<eltType>;
};

#endif

