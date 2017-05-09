// Map.h

#include "MapInterface.h"

class Map : public MapInterface {

	public:
	
		Map();
		// construct an empty Map
		~Map();
		 	
		bool empty() const;
		// is the Map empty?
		 
		int size() const;
		// how many elements are in the Map? 

		bool add(ElementType element);
		// add element to the Map
		 
		bool find(KeyType key) const;
		// is there there an element with key?
		 	
		ValueType retrieve(KeyType key) const;
		// return the value associated with key
		 
		bool remove(KeyType key);
		// remove the element with key
	
		
		void display()const;
		
		int height()const;
		
		int levelOf(KeyType key)const;
		
	private:
		class Node{ 
			public :
			ElementType key;
			Node *leftChild;
			Node *rightChild;	
			};


		Node* root;
		int SIZE;


		
		
		
};
		
		
		
		
		
		
		
