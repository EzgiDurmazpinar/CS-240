#include <iostream>
#include "Fraction.h"
using namespace std;

int main(){
	
	Fraction defaultObj;
	Fraction Obj1(3,7);
	Fraction Obj2(7,15);
	Fraction sumObj; 
	Fraction subsObj;
	Fraction multplyObj; 
	Fraction newObj; 
	
	cout<<endl;
	cout<<"defaultObj's num = " << defaultObj.getNumerator()<<"  defaultObj's denom = " << defaultObj.getDenominator() << endl;
	cout<<"Obj1's num = " << Obj1.getNumerator()<<"  Obj1's denom = " << Obj1.getDenominator() << endl;
	cout<<"Obj2's num = " << Obj2.getNumerator()<<"  Obj2's denom = " << Obj2.getDenominator() << endl<<endl;
	
	cout<< "Obj1 = "<<Obj1<<endl<<"Obj1's float value ="<<Obj1.getFloatValue() <<endl;
	cout<< "Obj2 = "<<Obj2<<endl<<"Obj2's float value ="<<Obj1.getFloatValue() <<endl<<endl;
	
	
	sumObj=Obj1+Obj2;
	cout<< "sumObj(obj1+obj2) = "<< sumObj<<endl;
	cout<<"sumObj's num = " << sumObj.getNumerator()<<"  sumObj's denom = " << sumObj.getDenominator() <<endl;
	cout<< "sumObj(float) = "<< sumObj.getFloatValue() <<endl<<endl;
	
	
	subsObj=Obj1-Obj2;
	cout<< "subsObj(obj1-obj2) = "<< subsObj<<endl;
	cout<<"subsObj's num : " << subsObj.getNumerator()<<"  subsObj's denom : " << subsObj.getDenominator() << endl;
	cout<< "subsObj(obj1-obj2) = "<< subsObj.getFloatValue() <<endl<<endl;
	
	
	multplyObj=Obj1*Obj2;
	cout<< "multplyObj(obj1*obj2) = "<< multplyObj<<endl;
	cout<<"multplyObj's num = " << multplyObj.getNumerator()<<"  multplyObj's denom = " << multplyObj.getDenominator() << endl;
	cout<< "multplyObj(obj1*obj2) = "<< multplyObj.getFloatValue() <<endl<<endl;
	
	
	cout<<"Testing the insertion operation..Expected= 3/7 "<<endl;
	cout<<Obj1<<endl<<endl;
	
	
	cout<<"Testing the extraction operation..Expected= first user input/second user input"<<endl;
	cin>>newObj;
	cout<<"new Obj = "<<newObj<<endl;
	newObj.invert(); 
	cout<<"inverted form of new Obj= "<<newObj<<endl<<endl;
	
}