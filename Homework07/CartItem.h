//file CartItem.h


#ifndef CART_ITEM_
#define CART_ITEM_
#include <string>
using namespace std;

class CartItem
{
private:
	string item;
	double cost;
	int quantity;
	
public:
    CartItem();
	CartItem(string i,double c,int q);
	string getItem();
	double getCost();
	int getQuantity();
	double totalPrice();
	
};
#endif


