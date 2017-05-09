//EZGI	DURMAZPINAR	

#include <iostream>
#include <vector>
using namespace std;

class Graph{
	
	
	private:
		vector<char> vertices;
		vector<vector<int>> adjacencyMatrix;
		int numberofEdges;
	
	public: 
	
		Graph(int numV,int numE);	//constructor
	    void addVertex(char v);  // add  vertex v to the graph
	    void addEdge(char v1,char v2);  // add edge (v1, v2) to the graph
	    bool isVertex(char v);  // return true if v is a vertex; else false
	    bool isEdge(char v1,char v2);  // return true if (v1, v2) is an edge; else false
	    int numVertices();  // return number of vertices
	    int numEdges();  // return number of edges	
		void display();		//  displays (using cout) each vertex followed by it adjacent vertices (display the name, not the number, of a vertex)  
		vector<char> breadthFirstTraversal(char v);//  return a list containing a breadth first traversal of the graph starting from v
		vector<char> depthFirstTraversal(char v);  //return a list containing a depth first traversal of the graph starting from v
		
	
};	
