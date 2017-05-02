//file  ShoppingCart.cpp

#include "ShoppingCart.h"
#include <iostream>
#include <ios>
#include <iomanip>

using namespace std;

void ShoppingCart::add(const CartItem & newItem){
	cart.append(newItem);
}

void ShoppingCart::display(){
	int i;
	cout<<"#  |"<<setw(10)<<left<<"ITEM"<<"|";
	cout<<setw(10)<<left<<"QANTITY"<<"|";
	cout<<setw(10)<<left<<"COST"<<"|"<<endl;
	cout<<"------------------------------------|"<<endl;
	for(i=1;i<=cart.getLength();i++){
		cout<<setw(3)<<left<<i<<"|";
		cout<<setw(10)<<left<<(cart.retrieve(i)).getItem()<<"|";
		cout<<setw(10)<<left<<(cart.retrieve(i)).getQuantity()<<"|";
		cout<<setw(10)<<left<<(cart.retrieve(i)).getCost()<<"|"<<endl;
	}
	cout<<endl;
}

void ShoppingCart::Remove(int pos){
	if(cart.getLength()>=1){
		cart.remove(pos);
	}
	else{
		cout<<"Your Cart is empty!"<<endl;
	}
	
}

double ShoppingCart::getCostIdx(int pos){
if(cart.getLength()>=1){
	int ctr=1;
	double result;
	cart.moveToStart();
	while(ctr<=cart.getLength()){
		if(ctr==pos){
			result = (cart.retrieve(ctr).getCost())*(cart.retrieve(ctr).getQuantity());
		}
		cart.next();
		ctr++;
	}
	return result;
}
else{
	cout<<"Your Cart is empty!"<<endl;
	return 0;
}
}
double ShoppingCart::getCost(){
	if(cart.getLength()>=1){
	int ctr=1;
	int sum=0;
	cart.moveToStart();
	while(ctr<=cart.getLength()){
		sum+=(cart.retrieve(ctr).getCost())*(cart.retrieve(ctr).getQuantity());
		cart.next();
		ctr++;	
	}
	return sum;
	}
	else{
		cout<<endl<<"Your Cart is empty!"<<endl;
		return 0;
	}
	
} 