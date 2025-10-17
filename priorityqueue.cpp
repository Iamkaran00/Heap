#include<iostream>
#include <queue>
using namespace std;
 void playingwithpq() {
    //max heap->
    priority_queue<int>pq;
    pq.push(3);
    pq.push(4);
    pq.push(92);
    pq.push(49);
   pq.push(30);
   pq.push(50);
   while(!pq.empty()) {
    cout<<pq.top()<<" ";
    pq.pop();
   }
cout<<"\n";
   //min heap ->
   priority_queue<int,vector<int>,greater<int>>minheap;
   minheap.push(3);
   minheap.push(49);
   minheap.push(229);
   while(!minheap.empty()){
    cout<<minheap.top()<<" ";
    minheap.pop();
   }
 }
int main()
{   
    playingwithpq();

    return 0;
}