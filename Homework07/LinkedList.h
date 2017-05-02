// file LinkedList.h

#ifndef LINKED_LIST_
#define  LINKED_LIST_

#include "ListInterface.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    class Node{
	public:
		ItemType data;
		Node *next;
		Node *prev;
		
    };

	Node * head;
	Node * tail;
	Node *curr;
	int size;
	
public:
	 
	 bool isEmpty() const;
     int getLength() const;
     bool insert(int newPos, const ItemType & newEntry);
     bool remove(int pos);
	 ItemType retrieve(int position) const;
	 bool append(const ItemType & newEntry) ;
	 ~LinkedList();
	 LinkedList();
	 LinkedList(const LinkedList & myObj);
	 LinkedList<ItemType> operator=(const LinkedList &myObj);
	 void moveToStart();
	 // sets current position to beginning of the list
	 void next();
	 // sets current position to the next element in the list
	 bool pastTheEnd() const;
	 // returns true if current position is after the last element; else returns false
	 ItemType getCurrentItem() const;
	 // returns element at the current position
	 // precondition: pastTheEnd() is false
	 
  
};

#include "LinkedList.cpp"
#endif
