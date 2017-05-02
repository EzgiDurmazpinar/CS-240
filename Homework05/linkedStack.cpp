// file: linkedStack.cpp
#include <cassert>    // for assert function   
#include "linkedStack.h"  

template<class ItemType>
linkedStack<ItemType>::linkedStack() {
	
	head = NULL;

}
 
template<class ItemType>
bool linkedStack<ItemType>::push(const ItemType& newEntry) {
	
	
	Node* p = new Node;
	p->data = newEntry;
	p->next = head;
	head = p;


	return true;
}

template<class ItemType>
bool linkedStack<ItemType>::isEmpty() const {
	if(head == NULL){
		return true;
	}
	else{
		return false;
	}
} 

template<class ItemType>
bool linkedStack<ItemType>::pop(){
	
	if(head==NULL){
		return false;
	}
	else{
		if(head->next == NULL){
			delete head;
			head=NULL;
			
		}
		else{
			Node *tmp=new Node;
			tmp=head->next;
			delete head;
			head=tmp;
		}
		return true;
	}
	
} 

template<class ItemType> 
ItemType linkedStack<ItemType>::peek() const{
	return head->data;
} 
