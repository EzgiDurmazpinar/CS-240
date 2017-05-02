//file program.cpp
#include "ShoppingCart.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int takeRequest();/*
	input: -
	side effect: display tha user the menu and ask the request
	return type: returns user's choice
*/
void removeMain(ShoppingCart & cart);/*
	input:  a reference variable which is Shopping Cart object
	side effect: ask user to which item that he/she wants to remove and then calls the Remove function
	return type: -

*/
void totalIdxMain(ShoppingCart & cart);/*
	input:  a reference variable which is Shopping Cart object
	side effect: ask user to which item that he/she wants learn about the total cost of it and then calls the getCostIdx function
	return type: -

*/
void addMain(ShoppingCart & cart);/*
	input:  a reference variable which is Shopping Cart object
	side effect: ask user to enter the cost, quantity and description of an item and then calls the add function for adding it to the list
	return type:-
	
*/

int main() {
    ifstream inFS;     // Input file stream
    ShoppingCart cart;
	int request;
	
   	inFS.open("input.txt");
   	if(!inFS.is_open()){
	   	cout<<"Couldn't open the file!"<<endl;
   	}
   	else{
	   	string item;
	   	double cost;
	  	int quantity;
	 	
	   string line; 
	
	   while(getline(inFS,line)){
		   
		   istringstream inSS(line);
		   inSS >> cost;
		   inSS >> quantity;
		   inSS >> item;
		   CartItem obj(item,cost,quantity);
		   cart.add(obj); 
	 }
	 
	   cart.display(); 
	   while((request=takeRequest())!=4){
		   	
	   	 	switch(request){
		   	 	case 1:
					removeMain(cart);
					break;
		  		case 2:
					totalIdxMain(cart);
					break;
		  		case 3:
					addMain(cart);
					break; 
					
				case 4: break;
						
				default:
						cout<<"You Entered non-valid request please enter again : ";
						break;
			
	   	     }
			 
			cout<<endl<<"Your current Shopping Cart : "<<endl;
			cart.display();		
	   }
	   		int total;
	   		total=cart.getCost();
     		cout<<endl<<"Total cost of your shopping cart is = "<<total<<endl<<endl;	
   }
   return 0;
}


int takeRequest(){
   int request;
   cout<<"Enter 1 to remove the item at a given position"<<endl;
   cout<<"Enter 2 to find out the total cost for an item at a given position"<<endl;
   cout<<"Enter 3 to add an item to the cart "<<endl;
   cout<<"Enter 4 to complete purchase"<<endl;
   cin>>request;
   
   return request;
}
void removeMain(ShoppingCart & cart){
	int idx;
	cout<<"Enter to index : ";
	cin>>idx;
	cart.Remove(idx);
}
void totalIdxMain(ShoppingCart & cart){
	int idx1;
	int result;
	cout<<"Enter to index : ";
	cin>>idx1;
	result=cart.getCostIdx(idx1);
	cout<<"Total cost for #"<<idx1<<" item is = "<<result<<endl;
}
void addMain(ShoppingCart & cart){
	string i;
	double c;
	int q;
	cout<<endl<<"Enter the cost, quantity and item for adding"<<endl;
	cin>>c>>q>>i;
	CartItem obj1(i,c,q);
	cart.add(obj1);
}
/*
Output for "input.txt"
Ezgis-MacBook-Pro:homework7 ezgidurmazpinar$ g++ -c -std=c++11 program.cpp
Ezgis-MacBook-Pro:homework7 ezgidurmazpinar$ g++ program.o
Ezgis-MacBook-Pro:homework7 ezgidurmazpinar$ ./a.out
#  |ITEM      |QANTITY   |COST      |
------------------------------------|
1  |book      |9         |63        |
2  |bag       |3         |450       |
3  |ugg       |2         |360       |

Enter 1 to remove the item at a given position
Enter 2 to find out the total cost for an item at a given position
Enter 3 to add an item to the cart 
Enter 4 to complete purchase
5
You Entered non-valid request please enter again : 
Your current Shopping Cart : 
#  |ITEM      |QANTITY   |COST      |
------------------------------------|
1  |book      |9         |63        |
2  |bag       |3         |450       |
3  |ugg       |2         |360       |

Enter 1 to remove the item at a given position
Enter 2 to find out the total cost for an item at a given position
Enter 3 to add an item to the cart 
Enter 4 to complete purchase
1
Enter to index : 1

Your current Shopping Cart : 
#  |ITEM      |QANTITY   |COST      |
------------------------------------|
1  |bag       |3         |450       |
2  |ugg       |2         |360       |

Enter 1 to remove the item at a given position
Enter 2 to find out the total cost for an item at a given position
Enter 3 to add an item to the cart 
Enter 4 to complete purchase
1
Enter to index : 2

Your current Shopping Cart : 
#  |ITEM      |QANTITY   |COST      |
------------------------------------|
1  |bag       |3         |450       |

Enter 1 to remove the item at a given position
Enter 2 to find out the total cost for an item at a given position
Enter 3 to add an item to the cart 
Enter 4 to complete purchase
1
Enter to index : 1

Your current Shopping Cart : 
#  |ITEM      |QANTITY   |COST      |
------------------------------------|

Enter 1 to remove the item at a given position
Enter 2 to find out the total cost for an item at a given position
Enter 3 to add an item to the cart 
Enter 4 to complete purchase
1
Enter to index : 2
Your Cart is empty!

Your current Shopping Cart : 
#  |ITEM      |QANTITY   |COST      |
------------------------------------|

Enter 1 to remove the item at a given position
Enter 2 to find out the total cost for an item at a given position
Enter 3 to add an item to the cart 
Enter 4 to complete purchase
2
Enter to index : 1
Your Cart is empty!
Total cost for #1 item is = 0

Your current Shopping Cart : 
#  |ITEM      |QANTITY   |COST      |
------------------------------------|

Enter 1 to remove the item at a given position
Enter 2 to find out the total cost for an item at a given position
Enter 3 to add an item to the cart 
Enter 4 to complete purchase
3

Enter the cost, quantity and item for adding
850 1 iphone7

Your current Shopping Cart : 
#  |ITEM      |QANTITY   |COST      |
------------------------------------|
1  |iphone7   |1         |850       |

Enter 1 to remove the item at a given position
Enter 2 to find out the total cost for an item at a given position
Enter 3 to add an item to the cart 
Enter 4 to complete purchase
3

Enter the cost, quantity and item for adding
63 6 shoe

Your current Shopping Cart : 
#  |ITEM      |QANTITY   |COST      |
------------------------------------|
1  |iphone7   |1         |850       |
2  |shoe      |6         |63        |

Enter 1 to remove the item at a given position
Enter 2 to find out the total cost for an item at a given position
Enter 3 to add an item to the cart 
Enter 4 to complete purchase
2
Enter to index : 2
Total cost for #2 item is = 378

Your current Shopping Cart : 
#  |ITEM      |QANTITY   |COST      |
------------------------------------|
1  |iphone7   |1         |850       |
2  |shoe      |6         |63        |

Enter 1 to remove the item at a given position
Enter 2 to find out the total cost for an item at a given position
Enter 3 to add an item to the cart 
Enter 4 to complete purchase
4

Total cost of your shopping cart is = 1228

Destructor Called !
Ezgis-MacBook-Pro:homework7 ezgidurmazpinar$ 
*/
