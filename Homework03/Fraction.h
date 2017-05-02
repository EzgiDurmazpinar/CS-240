
#ifndef _FRACTION_
#define _FRACTION_
#include <iostream>

class Fraction{
	public:
		Fraction();	/* creates a Fraction with the value 1/1
					return type : constructor
					input :	-
					output :-
			*/

		Fraction(int initNumerator, int initDenominator); /* creates a Fraction with the value initNumerator / initDenominator
					return type : constructor
					input :	-
					output : -
				
			*/
		
		int getDenominator()const;/*	returns the denominator
				return type : int
				input :	-
				output :-
		*/
		
		int getNumerator()const;/*	returns the numerator
				return type : int
				input :	-
				output :-
		*/
		
		
		double getFloatValue()const;/*	returns fraction’s float value
				return type : double
				input :	-
				output :-
		*/
		
		Fraction operator+ (const Fraction & rhsOperand) const;/*	returns the result of adding this Fraction to rhsOperand
				return type : Fraction
				input :	const Fraction & rhsOperand
				output :-
		*/
		
		friend std::ostream& operator<< (std::ostream & out, const Fraction & f);/*	 sends the value of f to out 
				return type : -
				input :	std::ostream & out, const Fraction & f
				output :-
		*/
		
		
		Fraction operator* (const Fraction & rhsOperand) const;/* returns the result of multiplying this Fraction to rhsOperand
				return type : Fraction
				input :	const Fraction & rhsOperand
				output :-
		*/
		
		
		Fraction operator- (const Fraction & rhsOperand) const;/*	returns the result of substraction this Fraction to rhsOperand
				return type : Fraction
				input :	const Fraction & rhsOperand
				output :-
		*/
		
		friend std::istream& operator>> (std::istream & in,  Fraction & f);/* take the value of f to in
				return type : -
				input :	std::ostream & out, const Fraction & f
				output : -
		*/
		
		void invert();/* invert the obj that is given
				return type : void
				input :	-
				output : -
		*/
		

	private:
		int num;
		int denom;
};
#endif

		
		
	