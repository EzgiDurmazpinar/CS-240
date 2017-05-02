#include "Fraction.h"
#include <iostream>
Fraction::Fraction(){ 		
	
	num=1;
	denom=1;
	
}	

Fraction::Fraction(int initNumerator, int initDenominator){ 	
	
	num=initNumerator;
	denom=initDenominator;
	
}

int Fraction::getDenominator()const{
	
	return denom;
	
}

int Fraction::getNumerator()const{
	
	return num;
	
}

double Fraction::getFloatValue()const{
	
	return (double) num/denom;
	
}

Fraction Fraction::operator+ (const Fraction & rhsOperand) const{
	
		int sumNum = (num * rhsOperand.denom) + (denom * rhsOperand.num);
		int sumDenom = denom * rhsOperand.denom;
		return Fraction(sumNum, sumDenom);
	
}


std::ostream & operator<< (std::ostream & out, const Fraction & f) {
	
	out << f.num << "/" << f.denom;
	return out;
	
} 

Fraction Fraction::operator* (const Fraction & rhsOperand) const{			
	int multiplyNum = num * rhsOperand.num;
	int multiplyDenom = denom * rhsOperand.denom;
	return Fraction(multiplyNum, multiplyDenom);
	
}

Fraction Fraction::operator- (const Fraction & rhsOperand) const{
	
	int subtractNum = (num * rhsOperand.denom) - (denom * rhsOperand.num);
	int subtractDenom = denom * rhsOperand.denom;
	return Fraction(subtractNum, subtractDenom );
	
}

 std::istream& operator>> (std::istream & in, Fraction & f){
 
    in >> f.num >> f.denom;
           return in;

}

void Fraction::invert(){
	int tmp=0;
	tmp = denom; 
	denom= num;
	num=tmp;
	
}






