// file linkedStack.h

#ifndef LINKED_STACK_
#define LINKED_STACK_

#include "StackInterface.h"

template<class ItemType>
class linkedStack : public StackInterface<ItemType>
{
private:
    class Node{
	public:
		ItemType data;
		Node *next;
    };
	Node * head;

public:
	 linkedStack();             // Default constructor
	 bool isEmpty() const;
	 bool push(const ItemType& newEntry);
	 bool pop();
	 ItemType peek() const;	
};

#include "linkedStack.cpp"
#endif
