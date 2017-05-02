#include "CallCenter.cpp"
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void display(int Time,int x,int y);
// a function to display current results within every 5 minutes
//Input: the time ,the current number of calls in the waiting list, completed calls untill now
//Output: none	
		

void displayresults(int sumOfcalls, int answerTime,int answered,float avg1,float avg2,float avg3,float avg4);
// a function to display results of the simulation at the end
//Input: the sum of calls, the sum of talking time, avarege waiting times according to each calls with different priorities
//Output: none	
	
int main(){
	srand (time(NULL));
	int Time;
	float ArrivalRate;


	
	int ArrTime,Talking,sumofAnswering=0;

	int Sum=0;

	
	cout<<"Please enter the system variable for the simulation <time>";
	cin>>Time;	
	cout<<"Please enter the system variable for the simulation < arrival rate>";
	cin>>ArrivalRate;

	CallCenter center = CallCenter(Time,ArrivalRate); 	//Create the Call Center


	vector<int> answeredFifth(Time+1,0);
	vector<int> callsFifth(Time+1,0);
	vector<int> Answered(Time+1,0);
	
		
	//--TAKECALLS--
	
	int y=0;
	int sumOfcalls=0;
	int firstCall=0;
	int firstCallTime;
	for(int i=1;i<=Time;i++){
		bool TrueFalse = (rand() % 100) < (ArrivalRate*100);		//determine if a new call is arrived
		if(TrueFalse==true){										//if it is
			firstCall++;
			Call call=Call();										//create
			if(firstCall==1){
				firstCallTime=i;
			}
			call.setArrivingTime(i);
			center.addtoWaitingList(call);							//sent to call center
			sumOfcalls++; 
			}
		
		if(i%5==0) {
			callsFifth.at(y)=center.getWaitlist().length(); 
			y++;
			}
		}

			
		
	//--ANSWER--	
	
	int answered=0;
	int x=0;
	float sumOfavg1=0,sumOfavg2=0,sumOfavg3=0,sumOfavg4=0;	
	int ctr1=0,ctr2=0,ctr3=0,ctr4=0;
	int AnsweredTime;
	
	Talking=0;
	
	for(int j=firstCallTime; j<Time && sumofAnswering<Time; j+=Talking){
		
		if(!(center.getWaitlist().isEmpty())){
		ArrTime = (center.takeCall()).getArrivingTime();		//keep arriving time	
		Talking = (center.takeCall()).getTalkingTime();			//keep talking time
	
		
			
		if( (center.takeCall()).getPriority()==1){
			sumOfavg1+=(j-ArrTime);
			if(sumOfavg1<0) sumOfavg1*=-1;
			ctr1++;	
		}
		else if( (center.takeCall()).getPriority()==2){
			sumOfavg2+=(j-ArrTime);
			if(sumOfavg2<0) sumOfavg2*=-1;
			ctr2++;
		}
		else if( (center.takeCall()).getPriority()==3){
			sumOfavg3+=(j-ArrTime);
			if(sumOfavg3<0) sumOfavg3*=-1;
			ctr3++;
		}
		else if( (center.takeCall()).getPriority()==4){
			sumOfavg4+=(j-ArrTime);	
			if(sumOfavg4<0) sumOfavg4*=-1;
			ctr4++;
		}
		
		
		center.answer();			//answer
		answered++;					//keep answered calls
		
		if(j+Talking<Time){
		answeredFifth.at(x)=j+Talking;		//keep finish time for answered call
		x++;
		}
		sumofAnswering += Talking;							//keep sum of answering time
		}
		
		else{
			j=Time;
		}
	}

		
	int ctr=0;	
	x=0;
	int hmFive=Time/5;					//icinde kac tane bes var bul
	for(int i=1;i<=hmFive;i++){			//her bes dk da bir olmasi icin kac eleman tutmali
		ctr=0;
		for(int k=0;k<Time;k++){
			if(answeredFifth.at(k)<=(5*i) && answeredFifth.at(k)!=0){
				ctr++;
			}
		}
		Answered.at(i-1)=ctr;				//such as in the 0'th element keep all the calls completed untill the fifth minute 
	}


	


	cout<<endl<<endl;
	//DISPLAY--		
	int c=0;
	
	for(int k=1; k<=Time;k++){
		if(k%5==0){			//display results in every five minutes	
			display(k,callsFifth.at(c)-Answered.at(c),Answered.at(c));
			c++;
		}
	
	}
	float avg1=0,avg2=0,avg3=0,avg4=0;
	
	if(ctr1!=0)  avg1= (sumOfavg1/ctr1);
	if(ctr2!=0)  avg2= (sumOfavg2/ctr2);
	if(ctr3!=0)  avg1= (sumOfavg3/ctr3);
	if(ctr4!=0)  avg1= (sumOfavg4/ctr4);;
	
	cout<<endl<<endl;
	cout<<"--RESULTS--"<<endl<<endl;
	displayresults(sumOfcalls,sumofAnswering,answered,avg1,avg2,avg3,avg4);
	return 0;
	
	
}


void display(int Time,int x,int y){
	cout<<"Time = "<<Time<<endl;
	cout<<"Number of calls in the waiting list = "<<x<<endl;
	cout<<"number of calls completed = "<<y<<endl;
	
}


void displayresults(int sumOfcalls, int answerTime,int answered,float avg1,float avg2,float avg3,float avg4){
	int sum=0;
	cout<<"Number of calls entered = "<<sumOfcalls<<" and answered = "<<answered<<endl;
	cout<<"Total time taken to answer all calls "<<answerTime<<endl;
	cout<<"Average wait time for a call to be answered for priority 1= "<<avg1<<endl;
	cout<<"Average wait time for a call to be answered for priority 2= "<<avg2<<endl;
	cout<<"Average wait time for a call to be answered for priority 3= "<<avg3<<endl;
	cout<<"Average wait time for a call to be answered for priority 4= "<<avg4<<endl;
}








