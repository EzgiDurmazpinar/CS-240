#include "linkedStack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//Input: String from line of the input file
//output: result of a postfix expression of that line 
//take line which is string and returns the result of a postfix expression of a line untill the end of string stream object
double evaluate(string line);


int main(){
	
	ifstream inFS;     // Input file stream
	ofstream outFS; 
	outFS.open("outfile.txt");
	
	string filename;
	cout<<"Enter the filnemane : ";
	cin>>filename;
	
    inFS.open(filename);
	
    if (!inFS.is_open()) {
       cout << "Could not open file myfile.txt." << endl;
       return -1; // -1 indicates error
    }
	
	string line;
    while (!inFS.eof()) {
       getline(inFS,line);
	   outFS <<"The result of evaluating: ";
	   outFS << line;
	   outFS << " is ";
	   outFS << evaluate(line);
	   outFS<<endl;
		 }
	
	inFS.close();
	outFS.close();
	return 0;	 
}

double evaluate(string line){
	istringstream inSS(line);
	linkedStack<string> myList;
	double result;
	
	string a;
	while(inSS >> a){
		
		if(a != "+" && a != "-" && a!="*" && a!="/") {
			myList.push(a);
		}
		
		else {
			string x = myList.peek();
			double i = atof(x.c_str());
			myList.pop();
			string y = myList.peek();
			double j = atof(y.c_str());
			myList.pop();
				 
			if(a=="+"){
				result =j+i;
				myList.push(to_string(result));	
			}
			else if(a=="-"){
				result=j-i;
				myList.push(to_string(result));	
			}
			else if(a=="*"){
				result=j*i;
				myList.push(to_string(result));	
			}
			else if(a=="/"){
				result=j/i;
				myList.push(to_string(result));	
			}
		}	
		
	}
	
	
	string final1 = myList.peek();
	double final = atof(final1.c_str());
	return final;
}

/* Content of the "outfile.txt" for "hw05.txt"

"hw05.txt" :

23.8  4 * 19.5  2 - + 
6.8  10.5 - 
36 6 /


"outfile.txt" :

The result of evaluating: 23.8  4 * 19.5  2 - +  is 112.7
The result of evaluating: 6.8  10.5 -  is -3.7
The result of evaluating: 36 6 / is 6
	
*/