// file: LinkedList.cpp
#include <cassert>    // for assert function   
#include "LinkedList.h"  
#include <iostream>
using namespace std;



template<class ItemType>
LinkedList<ItemType>::LinkedList() {
	head=0;
	tail=0;
	curr=0;
	size=0;
}


template<class ItemType>
bool LinkedList<ItemType>::isEmpty()const {
	if(head == 0){
		return true;
	}
	else{
		return false;
	}
}
 
 
 
template<class ItemType>
int LinkedList<ItemType>::getLength()const {
	
	return size;
	/*Node *temp = head;
	int ctr=1;
	while(temp!=tail){
		temp=temp->next;
		ctr++;
	}
	return ctr;*/
}

template<class ItemType>
bool LinkedList<ItemType>::append(const ItemType & newEntry){
	
	Node *NewEntry= new Node();
	NewEntry->data=newEntry;
	NewEntry->next=0;
	NewEntry->prev=0;
	
	if(head==0){ 	//if it is empty
		head=NewEntry;
		tail=NewEntry;
		tail->next=0;
	}
	else{
		tail->next=NewEntry;
		NewEntry->prev=tail;
		tail=NewEntry;
	}
	size++;
	return true;	
} 

template<class ItemType>
ItemType LinkedList<ItemType>::retrieve(int position) const{
	
	Node * tmp = head;
	int ctr=1;
	assert(position>0 && position<=getLength());
	while(ctr!=position){
		tmp=tmp->next;
		ctr++;
	}
	
	return tmp->data;
	
	
} 

 template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
	cout << "Destructor Called !"<<endl;
	while(tail!=head){
		tail=tail->prev;
		delete tail->next;
	
	}
	delete tail;
}


 template<class ItemType>
void LinkedList<ItemType>::moveToStart() {
	curr=head;
}

 template<class ItemType>
void LinkedList<ItemType>::next() {
	curr=curr->next;
}

 template<class ItemType>
bool LinkedList<ItemType>::pastTheEnd() const {
	if (curr == tail->next){
		return true;
	}
	else{
		return false;
	}
}

 template<class ItemType>
ItemType LinkedList<ItemType>::getCurrentItem() const{
	assert(pastTheEnd()== false);
	return curr->data;
	
}


 template<class ItemType>
bool LinkedList<ItemType>::insert(int newPos, const ItemType & newEntry){
	
	Node *NewEntry= new Node();
	NewEntry->data=newEntry;
	NewEntry->next=0;
	NewEntry->prev=0;
	
	if(1<=newPos && newPos<=getLength()+1){
		
		if(head!=0){
			moveToStart();		//finding what is at the newPos node
			int ctr=1;
			while(ctr!=newPos){
				next();
				ctr++;
			}
		}
		
		
		if(head==0){		//if list is empty
			head=NewEntry;
			tail=NewEntry;
		}
		
		else if(curr==tail->next){	//inserting at the end of a list
			tail->next=NewEntry;
			NewEntry->prev=tail;
			tail=NewEntry;
			//tail->next=0;
			
		}	
		
		else{		       //inserting a position that in the middle
			NewEntry->next=curr;
			NewEntry->prev=curr->prev;
			curr->prev->next=NewEntry;
			curr->prev=NewEntry;		
		}
		
		size++;
		return true;	
	}
	
	else{
		return false;
	}
	
}

 template<class ItemType>
bool LinkedList<ItemType>::remove(int pos){
	if(1<=pos && pos<=getLength()){
	
		moveToStart();		//finding what is at the newPos node
		int ctr=1;
		while(ctr<pos){
			next();
			ctr++;
		}

	
		Node *sucNode;
		Node *predNode;
	
		if(getLength()==1){
			head=0;
			
		}
		
		if(curr==head){		
			head=head->next;
			head->prev=0;
		
		}
	
		else if(curr==tail){
			tail=tail->prev;
	
		}
		else{		//if trying to remove something from the middle
			sucNode = curr->next;
			predNode = curr->prev;
			sucNode->prev=predNode;
			predNode->next=sucNode;
			}
	
			size--;
		return true;
	}
	
	else{
		return false;
	}
	
}



 template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList & myObj){			// makes a deep copy of object_to_copy
	cout << "Copy constructor called!" << endl;

	int ctr=1;
	Node *p= new Node();
  	p= myObj.head;
    while(p!=0)  {
		insert(ctr, p->data);
     	p = p->next;
	    ctr++;
    }
	delete p;
	return ;
}

 template<class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator=(const LinkedList &myObj){			// makes a deep copy of object_to_copy
	cout << "Operator= called!" << endl;
 		head=0;
 		curr=0;
 		tail=0;
 		size=0;
			
 		this->~LinkedList();
		 
		int ctr=1;
		Node *p= new Node();
  		p= myObj.head;
		
   	 	while(p!=0)  {
			insert(ctr, p->data);
     		p = p->next;
	   	 	ctr++;
    	}
		
	delete p;
	return *this;
}







