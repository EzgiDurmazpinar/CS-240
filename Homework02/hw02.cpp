#include <iostream>
#include <string>
    
#include <fstream>

#include <cstdlib>     // Enables use of rand()
#include <ctime>       // Enables use of time()    

using namespace std;

void encrypt(string& characters, int k);	//prototypes
void decrypt(string& characters, int k);

int main(){


	int userGuess=0;
	string STRING;
	string line;

	srand (time(0));	
	int k=0;	
	k= rand()%4+3;						//generate a random number between 3 and 6

	
	ifstream input;    	 // Input file stream
	input.open("HW2testcase.txt");	//try to open 

	if(!input.is_open()){				//check if its opened
		cout<<"Couldn’t	open the file!"<<endl;	
	}
	
	
	ofstream output;		//ofstream output for writing to outputfile
	output.open("output.txt");	//try to open 
	
	if(!output.is_open()){				//check if its opened
		cout<<"Couldn’t	open the file!"<<endl;	
	}
	
	while(!input.eof()){		
		getline(input,STRING);		//read
		encrypt(STRING,k);	//change string
		output<<STRING<<endl;	//write to output.txt
		
	}
	
	input.close(); // we are done with inputfile
	output.close();		//close the file and open it for reading 
	  
	  
	  
  	ifstream readoutput;    	 // Input file stream for read
  	readoutput.open("output.txt");	//try to open 
	
	
	if(!readoutput.is_open()){				//check if its opened
		cout<<"Couldn’t	open the file!"<<endl;	
	}
	
	cout<<"this is the original encrypted file:"<<endl;
	while(!readoutput.eof()){		//display user encrypted file
		getline (readoutput,line);
		cout<<line<<endl;
	}

	cout<<"Enter<'stop' to terminate> your guess :) —>" ;	//take user's guess
	cin>>userGuess;
	
	readoutput.clear();
	readoutput.seekg(0);
	
	while(cin.good() ){
		cout<<"This is your guess's result :"<<endl;
		while(!readoutput.eof()){		
			getline(readoutput,STRING);		//read
			decrypt(STRING,userGuess);	//change by user guess
			cout<<STRING<<endl;	//display
		}	
		readoutput.clear();
		readoutput.seekg(0);
		
		cout<<"Enter<'stop' to terminate> your guess :) —>" ;	//take user's guess
		cin>>userGuess;
	}
	
	return 0;

}
/*
	return type: void
	input:string reference variable
	output: nothing
*/

void encrypt(string& characters, int k){
	char c;
	for(int i=0;i<characters.size();i++){	
		if(isalpha(characters.at(i))){	
			c=characters.at(i);
			if(c+k<=122 || c+k<=90 ){	//boundaries
			characters.at(i)+=k;
			}
			else if(c+k>122 || c+k>90 ){	
				if(c+k>122){
					int x= ((c+k) % 122) + 96;
					characters.at(i) = char(x);	
				}
				else if(c+k>90 && c+k<97 ){
					int x= ((c+k) % 90) + 65;
					characters.at(i) = char(x);	
				}
			}
			
			}
	}
	return ;
}

/*
	return type: void
	input: string reference variable
	output: nothing
*/


void decrypt(string& characters, int k){
	char c;
	for(int i=0;i<characters.size();i++){	
		if(isalpha(characters.at(i))){	
			c=characters.at(i);
			if((c-k>=65 || c-k>=97) && isalpha(char(c-k))){	 //boundaries
			characters.at(i)-=k;
			}
			
			else if(c-k<97 || c-k<65 ){	
				if(c-k<97 && c-k>90){
					int x=123-(97%(c-k));
					characters.at(i) =char(x);	
				}
				else if(c-k<65 ){
					int x=90-(65%(c-k));
					characters.at(i) =char(x);	
				}
			}

			
			}
	}
	
	
	return ;
}

