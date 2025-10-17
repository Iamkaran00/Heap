#include<iostream>
using namespace std;
class MinHeap {
int *arr;
int size = 0,max_size;
public:
MinHeap(int size){
      arr = new int[size];
     max_size = size;
}
 
 void Insertion(int value){
    if(size>=max_size) {
        cout<<"Heap Overflowed \n";
         return;
    }
    arr[size] = value;
     size++;
    int index = size - 1; 
    int pindex = ( index - 1 ) /2;

    while(index>0 && arr[pindex]>arr[index]) {
        swap(arr[pindex],arr[index]);
        index = pindex;
        pindex = (index - 1)/2;
    }
  
 } 
 void heapify(int index){
    int smallestInd = index;
    int left = index*2 + 1;
    int right = index*2 + 2;
    if(left<size && arr[left]<arr[smallestInd]) {
        smallestInd = left;
    }
   else if(right<size && arr[right]<arr[smallestInd]) {
        smallestInd = right;
    }
    if(index != smallestInd) {
        swap(arr[smallestInd],arr[index]);
        heapify(smallestInd);
    }

  
 }
  void deletion(){
     if(size == 0) {
        cout<<"heap underflowed\n";
        return;
     } 
    arr[0] = arr[size-1];
    size--;
    if(size == 0) return;
     heapify(0);
     cout<<"deletion succeed\n";
     return ;
  }
  void print() {
    for(int i = 0 ; i < size ;i++) {
        cout<<arr[i]<<" "; 
    }
  }
};
int main()
{   int val = 10;
      MinHeap heap(val);
      heap.Insertion(8);
      heap.Insertion(9);
      heap.Insertion(17);
      heap.Insertion(0);
      heap.Insertion(12);
      heap.Insertion(89);
      heap.Insertion(79);
      heap.Insertion(30);
      heap.print();
      
    return 0;
}