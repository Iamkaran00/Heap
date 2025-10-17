#include<iostream>
using namespace std;

class MaxHeap{
 public:
 int max_size , curr_size = 0;
  int *arr;
   
  MaxHeap(int val) {
    max_size = val;
    arr = new int[val];
  }

   void Insertion(int val) {
    if(curr_size >= max_size) {
        cout<<"Heap Overflow \n";  
        return;
    }
     int ind = curr_size;
    arr[ind] = val;
    curr_size++;
     int parentIndx = (ind - 1 )/2;
    while(ind>0&&arr[parentIndx]<arr[ind]) {
        swap(arr[parentIndx],arr[ind]);
        ind = parentIndx;
        parentIndx = (ind - 1)/2;
    }
    return;
   }
   void print() {
    for(int i = 0 ;i < curr_size ;i++){
     cout<<arr[i]<<" ";
    }
   }
    void heapify(int index) {
        int largest = index;
        int left = 2*largest + 1;
        int right = 2*largest + 2;
        if(left<curr_size && arr[left]>arr[largest]) largest = left;
        if(right<curr_size && arr[right]>arr[largest]) largest = right;
        if(largest != index) {
            swap(arr[index],arr[largest]);
            heapify(largest);
        }
    }
     void deletion(){
 //deletion is always from root node;
      if(curr_size == 0) {
          cout<<"Heap is Underflow\n";
          return;
      }
      arr[0] = arr[curr_size-1];
      curr_size--;
      if(curr_size == 0) return;
      heapify(0);
      cout<<"deletion complete ";
     }
};
int main(){
    MaxHeap heap(8);
    heap.Insertion(12);
    heap.Insertion(9);
    heap.Insertion(30);
    
    heap.print();
    cout<<"\n";
    heap.Insertion(78);
    heap.Insertion(40);
    heap.Insertion(15);
    heap.Insertion(89);
    heap.Insertion(1);
    heap.print();
    heap.deletion();
    heap.print();
}
