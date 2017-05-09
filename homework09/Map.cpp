// Map.cpp

#include"Map.h"
#include<iostream>

// implement the constructor
Map::Map(){
SIZE=0;
root=NULL;
}

Map::~Map(){
	
	cout<<"Destructor Called!"<<endl;
	
	Node* save;
    for (Node* ptr= root; ptr != 0; ptr = save) {
           if (ptr->leftChild == NULL) {
               save = ptr->rightChild;
               delete ptr;
           }
           else {
               
               save = ptr->leftChild;
               ptr->leftChild = save->rightChild;
               save->rightChild = ptr;
           }
       }
   	
	}

//implement the empty, size and add methods
bool Map::empty() const{
	if(size()==0){
		return true;
	}
	else{
		return false;
	}
}
	 
int Map::size() const{
	return SIZE;
}

bool Map::add(ElementType e){
	Node* entry = new Node();
			entry->leftChild=0;
			entry->rightChild=0;
			entry->key=e;
	
		
    if (root == 0){
       root = entry;
       entry->leftChild = 0;
       entry->rightChild = 0;
	   SIZE++;
	   return true;
   }
     else{
       Node* cur = root;
       while (cur != 0) {
		   
           if (entry->key.first < cur->key.first){
              if (cur->leftChild == 0){
                  cur->leftChild = entry;
                  cur = 0;
		   	   SIZE++;
		   	   return true;
              }
                
              else{
              	cur = cur->leftChild;
              }
             } 
			 
			 else if(entry->key.first == cur->key.first){
				 delete entry;
				 return false;
			 }
			 
           else {
              if (cur->rightChild == 0){
                cur->rightChild = entry;
                cur = 0;
		 	   SIZE++;
		 	   return true;
  		 	 }
              else{
                cur = cur->rightChild;
  			  }     
  			  }
       }
          
       entry->leftChild = 0;
       entry->rightChild = 0;
   }
   return false;

}

// stubs for methods to be implemented later


bool Map::find(KeyType key) const {
	Node* ptr=root;

	while(ptr!=0){
		if(key == ptr->key.first){
			return true;
		}
		else if(key < ptr->key.first){
			ptr=ptr->leftChild;
		}
		else ptr=ptr->rightChild;
	}
	return false;
}
		 	
ValueType Map::retrieve(KeyType key) const{
	
	Node* ptr=root;
	while(ptr!=0){
		if(key == ptr->key.first){
			return ptr->key.second;
		}
		else if(key < ptr->key.first){
			ptr=ptr->leftChild;
		}
		else ptr=ptr->rightChild;
	}
	return nullptr;
}

bool Map::remove(KeyType key){
	
	Node* ptr=root;

	while(ptr!=0){
		if(key == ptr->key.first){
			break;
		}
		else if(key < ptr->key.first){
			ptr=ptr->leftChild;
		}
		else ptr=ptr->rightChild;
	}
	

	if(root!=NULL) {
		
		Node* parent = root;
		while(parent->leftChild!=ptr && parent->rightChild!=ptr){
			if(parent->key.first < ptr->key.first){
				parent=parent->leftChild;
			}
			else {
				parent=parent->rightChild;
			}	
		
		}
		
		if(ptr->rightChild==0 && ptr->leftChild==0){	//if it is a leaf node
			
			if(ptr==root){
				root=NULL;
					 SIZE--;
				return true;
		
			}
			
			if(parent->leftChild==ptr) {
				parent->leftChild=0;
				 SIZE--;
				return true;
			}
			
			else{
				 parent->rightChild=0;
				 SIZE--;
				 return true;
			 }
			 
			 
		}
	
		
		else if((ptr->rightChild==0 && ptr->leftChild!=0)  || (ptr->leftChild==0 && ptr->rightChild!=0)){		//if its a internal node with one child
			int left=0,right=0;	
			
			if(ptr==root){ 
			 if(ptr->rightChild!=0) root =ptr->rightChild;
			 else root = ptr->leftChild ;
			}
			 
			 if(ptr->rightChild!=0){
				 if(parent->rightChild==ptr) parent->rightChild = ptr->rightChild;
			 	 else parent->leftChild = ptr->rightChild;
				 	 SIZE--;
				return true;
			 }
			 else {
				 if(parent->rightChild==ptr) parent->rightChild = ptr->leftChild;
			 	 else parent->leftChild = ptr->leftChild;	
				 SIZE--;
				return true;
			 }
		
				 
		}

		else{											// Removing internal node with two children.
			Node* suc=ptr;
			suc = suc->rightChild;
			while(suc->leftChild!=0){
				suc= suc->leftChild;
			}
																		
			ptr = suc;
		
			Node* sucParent = root;
			while(sucParent->leftChild!=ptr && sucParent->rightChild!=ptr){
				if(sucParent->key.first < ptr->key.first){
					sucParent=sucParent->leftChild;
				}
				else {
					sucParent=sucParent->rightChild;
				}	
		
			}	
		
			
			sucParent->leftChild=0;
			SIZE--;
			return true;
	}

}


	return false;
}



int Map::height()const{
	int i=0;
	int tmp=SIZE,ctr=0;
	while(tmp>0){
		tmp=tmp/2;
		ctr++;
	}
	return ctr;
}

int Map::levelOf(KeyType key)const{
    if(find(key)==true){
	Node* ptr=root;
	int ctr=0;
	while(ptr!=0){
		if(key == ptr->key.first){
			break;
		}
		else if(key < ptr->key.first){
			ptr=ptr->leftChild;
		}
		else ptr=ptr->rightChild;
		
		ctr++;
	}
	return ctr;
    }
    else{
        return -1;
    }
}

void Map::display()const{		// display on the screen the key value pairs in order of their keys (smallest to largest)
	
	

	if(root==NULL){
		cout<<"Empty!"<<endl;
	}
	else{
		if(root->leftChild!=0){

			Node* mostLeft=root;					//en solu bul
			while(mostLeft!=0){
				mostLeft = mostLeft->leftChild;
			}
	
	
			while(mostLeft!=root){

				cout<<mostLeft->key.first<<" "<<*(mostLeft->key.second)<<endl;
		
				Node* parent = root;					//ailesini bul
				while(parent->leftChild!=mostLeft && parent->rightChild!=mostLeft){
					if(parent->key.first < mostLeft->key.first){
						parent=parent->leftChild;
					}
					else {
						parent=parent->rightChild;
					}	
			
				}
				cout<<parent->key.first<<" "<<*(parent->key.second)<<endl;
				cout<<parent->rightChild->key.first<<" "<<*(parent->rightChild->key.second)<<endl;
		
		
				mostLeft=parent;
	
				}
		
		}
	    if(root->rightChild!=0){
			Node* mostRight=root;					//en sagi bul
			while(mostRight!=0){
				mostRight = mostRight->leftChild;
			}
		
			while(mostRight!=root){

				cout<<mostRight->key.first<<" "<<*(mostRight->key.second)<<endl;
		
				Node* parent = root;					//ailesini bul
				while(parent->leftChild!=mostRight && parent->rightChild!=mostRight){
					if(parent->key.first < mostRight->key.first){
						parent=parent->leftChild;
					}
					else {
						parent=parent->rightChild;
					}	
			
				}
				cout<<parent->key.first<<" "<<*(parent->key.second)<<endl;
				cout<<parent->leftChild->key.first<<" "<<*(parent->leftChild->key.second)<<endl;
		
		
				mostRight=parent;
	
				}
			
		}
		
	}

						
	
}











	
