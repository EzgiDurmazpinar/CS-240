#include <iostream>
#include <vector>
#include "Graph.cpp"
using namespace std;

int main(){

	 int numV,numE;
	 cout<<"Enter the number of Vertices : ";
	 cin>>numV;
	 cout<<"Enter the number of Edges : ";
	 cin>>numE;
	

	 Graph myGraph = Graph(numV,numE); 	//Create the Graph
	 myGraph.display();
	
	
	 cout<<"Testing adding Vertex and adding Edge..."<<endl;
	 cout<<"h , i ,j vertices added to my Graph! "<<endl;
	 myGraph.addVertex('h');
	 myGraph.addVertex('i');
	 myGraph.addVertex('j');
	 cout<<"a-i and d-h edges added to my Graph! "<<endl;
	 myGraph.addEdge('a','i');  // add edge (v1, v2) to the graph
	 myGraph.addEdge('d','h');  // add edge (v1, v2) to the graph
	 myGraph.display();
	  /*V = [a, b, c, d, e, f, g, h, i, j]
        E = [(a,b), (b,c), (c,d), (d,h), (d,g), (g,e), (e,c), (e,b), (g,f), (f,a), (a,i)]
	  */
	  
	  
	  bool result;  
	cout<<"Is Z is a vertex of my Graph? (expected false)"<<endl;
	result=myGraph.isVertex('Z');
	cout<<result<<endl;
   
   
	cout<<"Is a-b is a edge in my Graph? (expected true)"<<endl;
	result=myGraph.isEdge('a','b');
	cout<<result<<endl;
   
   
   
   	cout<<"Number of vertices in my Graph = "<<myGraph.numVertices()<<endl;
    
	cout<<"Number of edges in my Graph = "<<myGraph.numEdges() << endl;
	
	cout<<endl<<"-- Starting traversal with a --"<<endl;

	cout<<"Testing breadthFirstTraversal ..."<<endl;
	vector<char> visited = myGraph.breadthFirstTraversal('a');
	for(int i=0;i<visited.size();i++){
		cout<<visited.at(i)<<" ";
	}	
	cout<<endl;
	

	cout<<"Testing depthFirstTraversal ..."<<endl;
	vector<char> visited2 = myGraph.depthFirstTraversal('a');
	for(int i=0; i<visited2.size();i++){
		cout<<visited2.at(i)<<" ";
	}	
	cout<<endl;
	
	
	
	cout<<endl<<"-- Starting traversal with e --"<<endl;

	cout<<"Testing breadthFirstTraversal ..."<<endl;
	vector<char> visited3 = myGraph.breadthFirstTraversal('e');
	for(int i=0;i<visited3.size();i++){
		cout<<visited3.at(i)<<" ";
	}	
	cout<<endl;
	

	cout<<"Testing depthFirstTraversal ..."<<endl;
	vector<char> visited4 = myGraph.depthFirstTraversal('e');
	for(int i=0; i<visited4.size();i++){
		cout<<visited4.at(i)<<" ";
	}	
	cout<<endl;
	
	
	
	cout<<endl<<"-- Starting traversal with i --"<<endl;

	cout<<"Testing breadthFirstTraversal ..."<<endl;
	vector<char> visited5 = myGraph.breadthFirstTraversal('i');
	for(int i=0;i<visited5.size();i++){
		cout<<visited5.at(i)<<" ";
	}	
	cout<<endl;
	

	cout<<"Testing depthFirstTraversal ..."<<endl;
	vector<char> visited6 = myGraph.depthFirstTraversal('i');
	for(int i=0; i<visited6.size();i++){
		cout<<visited6.at(i)<<" ";
	}	
	cout<<endl;


	cout<<endl<<"-- Starting traversal with j --"<<endl;

	cout<<"Testing breadthFirstTraversal ..."<<endl;
	vector<char> visited7 = myGraph.breadthFirstTraversal('j');
	for(int i=0;i<visited7.size();i++){
		cout<<visited7.at(i)<<" ";
	}	
	cout<<endl;
	

	cout<<"Testing depthFirstTraversal ..."<<endl;
	vector<char> visited8 = myGraph.depthFirstTraversal('j');
	for(int i=0; i<visited8.size();i++){
		cout<<visited8.at(i)<<" ";
	}	
	cout<<endl;


	return 0;
}