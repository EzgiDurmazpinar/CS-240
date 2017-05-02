#include <iostream>
using namespace std;

 /* Goal:Compute the coin numbers with regard to inputs and also update to amountLeft
    Return type: int
    Input: coin (quarter,dimes;nickels or pennies) and amountLeft
    Output: returns numbers of coins 
     */
int computeCoin(int coin, int & amountLeft){

	int amount=amountLeft;
	int ctr=amount/coin;
		
	amountLeft=amountLeft-ctr*coin;
	return ctr;
}



/*Goal: Display all the updated variables at the same time 
  Return type: void
  Input: integer variables
  Output: print customer change using the fewest coins possible
     */
void display(int quarter,int dime,int nickel,int pennie, int amount){
	cout<<amount << " = " << quarter <<" quarters "<< dime<<" dimes " <<nickel<< " nickels and " <<pennie<<" pennies."<<endl;
	return;
}



 /* Goal: take an amount from user. Also with the help of input type(reference varibale) I didn't write any "cin" statement in main function
    Return type: void
    Input: amountLeft
    Output: prints a prompt screen for user
     */

void userInput(int& amountLeft){
	cout<<"Enter <-1 to exit> the amount please: ";
	cin>>amountLeft;
	if(!cin.good()){
		amountLeft=-1;
		cout<<"You entered none integer"<<endl;
		cout<<"Terminating…"<<endl;
	}
	return;
}


int main(){

		int quarters=25;
		int dimes=10;
		int nickels=5;
		int pennies=1;
		int amountLeft=0;
		
	userInput(amountLeft);

	while(amountLeft!=-1 && amountLeft<100){
		int nickel=0;
		int dime=0;
		int quarter=0;
		int pennie=0;

			
		
		int originalAmount=amountLeft; //(for protect the original )for the Display function
			
		while(amountLeft>0){
			
			if(amountLeft>=25){
			quarter = computeCoin(quarters,amountLeft);
			}
					
			else if(amountLeft>=10){
				dime = computeCoin(dimes,amountLeft);
			}

			else if(amountLeft>=5){
				nickel = computeCoin(nickels,amountLeft);
			}

			else if(amountLeft>=1){
				pennie = computeCoin(pennies,amountLeft);
			}
					
				
				}
	   	    display(quarter,dime,nickel,pennie,originalAmount);	
			userInput(amountLeft);		
		}
	
return 0;			
}