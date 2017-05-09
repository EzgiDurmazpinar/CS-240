// testMap.cpp

#include "Map.cpp"
#include<iostream>
#include <string>

int main(){
	
	Map myMap;
	
	cout << "size should be 0 " << "size is: "
	     <<  myMap.size() << endl;
	     
	cout << "is the Map empty? " << endl;
	if(myMap.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;	
			     
	myMap.add(make_pair(222, new string("abc")));
	myMap.add(make_pair(333, new string("def")));
	myMap.add(make_pair(444, new string("ghi")));
	myMap.add(make_pair(222, new string("jkl")));
	
	cout << "size should be 3 " << "size is: "
	     <<  myMap.size() << endl;
	     
	cout << "is the Map empty? " << endl;
	if(myMap.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	
	cout<<"Testing find.. Expected True"<<endl;
	if(myMap.find(333) == true) cout<<"True"<<endl;
	else{ 
		cout <<false<<endl;
	} 
	cout<<"expected value type for 333 = def "<<endl;
	cout<<*(myMap.retrieve(333))<<endl;
	cout<<"Testing remove ...."<<endl;
	myMap.remove(333);
	
	cout << "size should be 2 " << "size is: "
	     <<  myMap.size() << endl;
	
	cout<<"Is removed element found? "<<endl;
	if(myMap.find(333) == true) cout<<"True"<<endl;
	else{ cout <<"false"<<endl;
	} 
	
	cout<<"height of a tree is "<<myMap.height()<<endl;
	cout<<"level of 444 is "<<myMap.levelOf(444)<<endl;
	
	
	
	
	myMap.display();
}	     
	     
