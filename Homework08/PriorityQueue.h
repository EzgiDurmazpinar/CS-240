// file: PriorityQueue.h
#include "PriorityQueueInterface.h"
#ifndef PQUEUE_
#define PQUEUE_
#include <vector>
using namespace std;

// change the typedef statement in PriorityQueueInterface.h
// to the type of the items to be stored in the priority queue

class PriorityQueue : public PriorityQueueInterface
{
public: 

   PriorityQueue();

   bool isEmpty() const;
   
   int length() const;
   
   bool enqueue(const ItemType & newEntry);

   bool dequeue();

   ItemType front() const;
   
private:

	vector<ItemType> heap;
	
};
#endif
