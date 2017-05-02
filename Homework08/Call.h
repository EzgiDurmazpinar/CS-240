//EZGI	DURMAZPINAR	

#include <iostream>

using namespace std;

class Call{
	
	
	private:
		int arrivingTime;	
		int priority;
		int talkingTime; 
		
	
	
	
	public: 
	
		Call();			
		//Constructor
	
		bool operator <(const Call & rhsOperand) const;
   	 	// operator overloading function that tells compiler to how to compare call class	
   	 	
		bool operator >(const Call & rhsOperand) const;
		// operator overloading function that tells compiler to how to compare call class
	
		bool operator ==(const Call & rhsOperand) const;
		// operator overloading function that tells compiler to how to compare call class
	
		int getArrivingTime();
		// a method to get arrivingTime member .It provides to get arrivingTime of a call in the main
		//Input: none
		//Output: returns the arrivingTime
	
		int getPriority();
		// a method to get priority member .It provides to get priority of a call in the main
		//Input: none
		//Output: returns the priority
	
		int getTalkingTime();
		// a method to get talkingTime member .It provides to get talkingTime of a call in the main
		//Input: none
		//Output: returns to talkingTime
	
		void setArrivingTime(int x);
		// a method to set arrivingTime member .It provides to set arrivingTime of a call in the main
		//Input: a value for set to arrivingTime
		//Output: none
	
};	
