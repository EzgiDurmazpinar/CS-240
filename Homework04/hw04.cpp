
#include <iostream>
#include <string>
#include <cstdlib>     
#include <ctime>
#include <vector>       
using namespace std;

void fillVector(vector<int>& vec);
void printVector(vector<int> vec); 
void selectionSort(vector<int>& vec);
void insertionSort(vector<int>& vec);
void quickSort(vector<int>& vec, int i, int k);
int Partition(vector<int>& vec, int i, int k);


int main(){
int SIZE=10;	
vector<int> myVec(SIZE);



srand (time(NULL));
 
fillVector(myVec);
vector<int> firstCopy(myVec);
vector<int> secondCopy(myVec);	


clock_t ticks;
clock_t ticks2;
clock_t ticks3;

cout<<"----Selection Sort----"<<endl;
cout<<"Vector to be sorted: "<<endl;
printVector(myVec);	
ticks=clock();		//initailize the time untill now to ticks
selectionSort(myVec);	
ticks=clock()-ticks; //substract number of ticks from now 
float seconds = (float)ticks / CLOCKS_PER_SEC;
cout<<"Seconds that Selection Sort spend : "<<fixed<<seconds<<endl;
cout<<"Sorted vector: "<<endl;
printVector(myVec);
cout<<endl;

cout<<"----Insertion Sort----"<<endl;
cout<<"Vector to be sorted: "<<endl;
printVector(firstCopy);
ticks2=clock();		//initailize the time untill now to ticks
insertionSort(firstCopy);
ticks2=clock()-ticks2; //substract number of ticks from now 
seconds = (float)ticks2 / CLOCKS_PER_SEC;
cout<<"Seconds that Insertion Sort spend : "<<fixed<<seconds<<endl;
cout<<"Sorted vector: "<<endl;
printVector(firstCopy);
cout<<endl;

cout<<"----Quick Sort----"<<endl;
cout<<"Vector to be sorted: "<<endl;
printVector(secondCopy);
ticks3=clock();		//initailize the time untill now to ticks
quickSort(secondCopy,0,secondCopy.size()-1);
ticks3=clock()-ticks3; //substract number of ticks from now 
seconds = (float)ticks3 / CLOCKS_PER_SEC;
cout<<"Seconds that Quick Sort spend : "<<fixed<<seconds<<endl;
cout<<"Sorted vector: "<<endl;
printVector(secondCopy);
cout<<endl;	


clock_t ticks4;
clock_t ticks5;
clock_t ticks6;
cout<<"-FOR SORTED VECTORS-"<<endl;

cout<<"----Selection Sort----"<<endl;
ticks4=clock();		
selectionSort(myVec);	
ticks4=clock()-ticks4; 
seconds = (float)ticks4 / CLOCKS_PER_SEC;
cout<<"Seconds that Selection Sort spend for already sorted vector : "<<fixed<<seconds<<endl;

cout<<"----Insertion Sort----"<<endl;
ticks5=clock();		
insertionSort(firstCopy);	
ticks5=clock()-ticks5; 
seconds = (float)ticks5 / CLOCKS_PER_SEC;
cout<<"Seconds that Insertion Sort spend for already sorted vector : "<<fixed<<seconds<<endl;


cout<<"----Quick Sort----"<<endl;
ticks6=clock();		
insertionSort(firstCopy);	
ticks6=clock()-ticks6; 
seconds = (float)ticks6 / CLOCKS_PER_SEC;
cout<<"Seconds that Quick Sort spend for already sorted vector : "<<fixed<<seconds<<endl;


	return 0;

}   




void selectionSort(vector<int>& vec) {
   int i = 0;
   int j = 0;
   int indexSmallest = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 0; i < vec.size() - 1; ++i) {
      
      // Find index of smallest remaining element
      indexSmallest = i;
      for (j = i + 1; j < vec.size(); ++j) {
         
         if (vec.at(j) < vec.at(indexSmallest) ) {
            indexSmallest = j;
         }
      }
      
      // Swap vec.at(i) and vec.at(indexSmallest
      temp = vec.at(i);
      vec.at(i) = vec.at(indexSmallest);
      vec.at(indexSmallest) = temp;
   }
}

void insertionSort(vector<int>& vec) {
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 1; i < vec.size(); ++i) {
      j = i;
      // Insert vec.at(i) into sorted part
      // stopping oncevec.at(i)in correct position
      while (j > 0 && vec.at(j) < vec.at(j-1)) {
         
         // Swap vec.at(j) and vec.at(j-1)
         temp = vec.at(j) ;
         vec.at(j)  = vec.at(j-1);
         vec.at(j-1) = temp;
         --j;
      }
   }
   
   return;
}





int Partition(vector<int>& vec, int i, int k) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   /* Pick middle element as pivot */
   midpoint = i + (k - i) / 2;
   pivot = vec.at(midpoint);
   
   l = i;
   h = k;
   
   while (!done) {
      
      /* Increment l while vec.at(l) < pivot */
      while (vec.at(l) < pivot) {
         ++l;
      }
      
      /* Decrement h while pivot < vec.at(h) */
      while (pivot < vec.at(h)) {
         --h;
      }
      
      /* If there are zero or one elements remaining,
       all numbers are partitioned. Return h */
      if (l >= h) {
         done = true;
      }
      else {
         /* Swap vec.at(l) and vec.at(h),
          update l and h */
         temp = vec.at(l);
         vec.at(l) = vec.at(h);
         vec.at(h) = temp;
         
         ++l;
         --h;
      }
   }
   
   return h;
}

void quickSort(vector<int>& vec, int i, int k) {
   int j = 0;
   
   /* Base case: If there are 1 or zero elements to sort,
    partition is already sorted */
   if (i >= k) {
      return;
   }
   
   /* Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
   j = Partition(vec, i, k);
   
   /* Recursively sort low partition (i to j) and
    high partition (j + 1 to k) */
   quickSort(vec, i, j);
   quickSort(vec, j + 1, k);
   
   return;
}
void  fillVector(vector<int>& vec){
	int i;
	
	cout<<endl<<"Vector:"<<endl;
	for(i=0;i<vec.size();i++){
		vec.at(i)=rand() % 900000 + 100000  ;
		cout<<" "<<vec.at(i);
	}

	cout<<endl<<endl;
}

void printVector(vector<int> vec){
	int i;
	for(i=0;i<vec.size();i++){
		cout<<" "<<vec.at(i);
	}
	cout<<endl;
}