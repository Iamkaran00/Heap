#include <iostream>
using namespace std;
void Heapify(int arr[],int ind,int size) {
    int largest = ind;
    int left = 2*largest + 1;
    int right = 2*largest + 2;
    if(left< size && arr[left] > arr[largest]) largest = left;
    if(right<size&& arr[right] > arr[largest]) largest = right;
    if(largest != ind) {
        swap(arr[largest],arr[ind]);
        Heapify(arr,largest,size);
    }
}
 void BuildHeap(int *arr,int size,int ind) {
    for(int i = ind ; i >= 0;i--) {
        Heapify(arr,i,size);
    }
 }
 void print(int arr[],int size) {
for(int i = 0 ;i < size ;i++) cout<<arr[i]<<" ";
cout<<endl;
 }
int main()
{
    int arr[] = {22, 15, 12, 14, 17, 20, 18, 24, 28, 30, 19};
    int size = sizeof(arr)/sizeof(int);
    int startingindex = size/2 - 1;
    BuildHeap(arr,size,startingindex);
    print(arr,size);
     return 0;
}