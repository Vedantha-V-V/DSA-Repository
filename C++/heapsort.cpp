#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>&heap,int node,int size){
    int largest=node;
    int l=2*largest+1;
    int r=2*largest+2;
    if(l<size && heap[l]>heap[largest]){
        largest=l;
    }
    if(r<size && heap[r]>heap[largest]){
        largest=r;
    }
    if(largest!=node){
        swap(heap[node],heap[largest]);
        heapify(heap,largest,size);
    }
}

void heapsort(vector<int>&heap){
    for(int i=heap.size()/2-1;i>=0;i--){
        heapify(heap,i,heap.size());
    }
    for(int i=heap.size()-1;i>0;i--){
        swap(heap[0],heap[i]);
        heapify(heap,0,i);
    }

}

int main(){
    vector<int>heap={10,20,9,8,2,1};
    heapsort(heap);
    for(auto i:heap){
        cout<<i<<"\t";
    }
    return 0;
}