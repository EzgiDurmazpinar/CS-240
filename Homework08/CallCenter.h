#include <iostream>
#include "PriorityQueue.cpp"

using namespace std;


class CallCenter {
	
	private:
		
		int Time;
		float arrivalRate;
		PriorityQueue waitList; 
	
	
	public:
		
		CallCenter(int process,float Rate);		
		//constructor
		
		int getTime();
		// a method to get Time member .It provides to get Time of a CallCenter in the main.
		//Input: none
		//Output: returns the Time
		
		float getArrivalRate();
		// a method to get arrivalRate member .It provides to get arrivalRate of a CallCenter in the main.
		//Input: none
		//Output: returns the arrivalRate
		
		PriorityQueue getWaitlist();
		// a method for reach to waitList of a CallCenter in the main .
		//Input: none
		//Output: returns the waitList
		
		Call takeCall();		
		// a method for reach to highest priority call in the CallCenter .
		//Input: none
		//Output: returns the Call	
		
		void answer();	
		// a method for answering calls . It is calling the dequeue function to delete it from waitList.
		//Input: none
		//Output: none	
		
		void addtoWaitingList(Call& Obj);
		// a method for adding calls to the waitList.
		//Input: Obj of a Call type 
		//Output: none	
		

};
