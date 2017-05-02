//file ShoppingCart.h


#ifndef SHOPPING_CART_
#define SHOPPING_CART_

#include "CartItem.h"
#include "LinkedList.h"

class ShoppingCart
{
	
private:
	LinkedList<CartItem> cart;
	

public:
	void add(const CartItem & newItem);
	void display();
	void Remove(int pos);
	double getCostIdx(int pos);
	double getCost(); 

	
};
#include "CartItem.cpp"
#endif



