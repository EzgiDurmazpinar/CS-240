//file CartItem.cpp

#include "CartItem.h"
#include <iostream>

using namespace std;

CartItem::CartItem() {
	item ="";
	cost=0.00;
	quantity=0;
}

CartItem::CartItem(string i,double c,int q) {
	item =i;
	cost=c;
	quantity=q;
}

//string getItem();
string CartItem::getItem() {
	return item;
}
//double getCost();
double CartItem::getCost(){
	return cost;
}
//int getQuantity();
int CartItem::getQuantity(){
	return quantity;
}
//double totalPrice();
double CartItem::totalPrice(){
	return quantity*cost;
}