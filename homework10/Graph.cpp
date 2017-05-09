// file Graph.cpp

#include "Graph.h"
#include <algorithm>
#include <utility>
#include <iterator>
#include <stack>

using namespace std;

Graph::Graph(int numV,int numE){
	numberofEdges=numE;
	char v;
	cout<<"Enter the "<<numV<<" Vertices"<<endl;

	for(int i=0;i<numV;i++){
		cin>>v;
		vertices.push_back(v);
	} 
	

	adjacencyMatrix.resize(numV, vector<int>(numV, 0));
	/*for(int i=0;i<numV;i++){
		for(int j=0;j<numV;j++){
			adjacencyMatrix[i][j]=false;
	
		}
	}*/
		
	char e1,e2;
	int index1,index2;
	for(int i=0;i<numE;i++){
		cout<<"Enter the edges "<<endl;
		cin>>e1;
		cin>>e2;
		for(int j=0;j<numV;j++){
			if(e1==vertices.at(j)) index1=j;
			if(e2==vertices.at(j)) index2=j;
		}
	adjacencyMatrix[index1][index2]=true;
	adjacencyMatrix[index2][index1]=true;
	
	}
		
	
}

void Graph::addVertex(char v){

	vertices.push_back(v);
	adjacencyMatrix.resize(vertices.size() , vector<int>(vertices.size() ));
		
	for(int i=0; i<vertices.size() ; i++){
		
		for(int j=0;j<vertices.size() ; j++){
			if(i==vertices.size()-1){
				adjacencyMatrix[i][j]=false;
			}
		}
	
	
	}

}

void Graph::addEdge(char v1,char v2){
	
	int index1,index2;
	for(int i=0;i<vertices.size();i++){
		if(v1==vertices.at(i)) index1=i;
		if(v2==vertices.at(i)) index2=i;
	}
	adjacencyMatrix[index1][index2]=true;
	adjacencyMatrix[index2][index1]=true;	
	numberofEdges++;
	
}

bool Graph::isVertex(char v){ 
	for(int i=0;i<vertices.size();i++){
		if(v==vertices.at(i)){
			return true;
		}	
	}
	return false;
}

bool Graph::isEdge(char v1,char v2){
	
	int index1,index2;
	for(int i=0;i<vertices.size();i++){
		if(v1==vertices.at(i)) index1=i;
		if(v2==vertices.at(i)) index2=i;
	}
	
	if(	adjacencyMatrix[index1][index2]==true && adjacencyMatrix[index2][index1]==true ) return true;
	else	return false;
	
	
}

int Graph::numVertices() {
	return vertices.size();
}

 int Graph::numEdges(){
	 return numberofEdges;
	 
 }

 void Graph::display(){
	// displays (using cout) each vertex followed by it adjacent vertices (display the name, not the number, of a vertex)  
	 cout<<endl<<"--- Displaying each vertex followed by it adjacent vertices ---"<<endl;
	for(int i=0;i<vertices.size();i++){
		cout<<vertices.at(i)<<" -> ";
		for(int j=0;j<vertices.size();j++){
			if(adjacencyMatrix[i][j]==1){
				cout<<vertices.at(j)<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
 }
 

 vector<char> Graph::depthFirstTraversal(char v){
  	vector<char> visitedList;
 	stack<char> myStack;
 	
 	char topV;
	

 	myStack.push(v);
	
	
 	while(!myStack.empty()){
 		topV = myStack.top();
 		myStack.pop();
 		int idx;		
 		if(find(visitedList.begin(), visitedList.end(), topV) == visitedList.end()) {
 			visitedList.push_back(topV);
 		}			
 		for(int i=0;i<vertices.size();i++){
 			if(topV==vertices.at(i)){
 				idx=i;
 			}
 		}
	
		vector<char> adjacents;
		
 		for(int i=0;i<vertices.size();i++){
 			if(adjacencyMatrix[idx][i]==1){
 				adjacents.push_back(vertices.at(i));
 			}
 		}
	
 		
 			for(int j=0;j<adjacents.size();j++){
 				if(find(visitedList.begin(),visitedList.end(),adjacents.at(j))==visitedList.end()){
 					myStack.push(adjacents.at(j));
					
 				}
 			}
 		}
 	int counter=0;
 	for(int i=0;i<vertices.size();i++){
		
 		if(find(visitedList.begin(),visitedList.end(),vertices.at(i))==visitedList.end()){
 			visitedList.push_back(vertices.at(i));
 		}
	
 	}
 	return visitedList;
	
	
 }
 
 

 
 vector<char> Graph::breadthFirstTraversal(char v){
	 	vector<char> visitedList;
		stack<char> myStack;
		
		char topV;
		
		
		visitedList.push_back(v);
		myStack.push(v);
		
		
		while(!myStack.empty()){
			topV = myStack.top();
			myStack.pop();
			int idx;					
			for(int i=0;i<vertices.size();i++){
				if(topV==vertices.at(i)){
					idx=i;
				}
			}
		
			vector<char> adjacents;
		
			for(int i=0;i<vertices.size();i++){
				if(adjacencyMatrix[idx][i]==1){
					adjacents.push_back(vertices.at(i));
				}
			}
		
				for(int j=0;j<adjacents.size();j++){
					if(find(visitedList.begin(),visitedList.end(),adjacents.at(j))==visitedList.end()){
						visitedList.push_back(adjacents.at(j));
						myStack.push(adjacents.at(j));
						
					}
				}
			
			}
		int counter=0;
		for(int i=0;i<vertices.size();i++){
			
			if(find(visitedList.begin(),visitedList.end(),vertices.at(i))==visitedList.end()){
				visitedList.push_back(vertices.at(i));
			}
		
		}
		return visitedList;
 }




