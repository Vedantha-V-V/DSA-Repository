#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>bfsOfGraph(int num,vector<vector<int>>adj){
    int visited[num]={0};
    visited[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
    return bfs;
}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        int temp;
        cout<<"Enter the number of connected nodes of "<<i<<" : ";
        cin>>temp;
        cout<<"Enter the connected nodes of "<<i<<" : ";
        for(int k=0;k<temp;k++){
            int val;
            cin>>val;
            adj[i].push_back(val);
        }
    }

    vector<int>bfs=bfsOfGraph(n,adj);
    for(int i:bfs){
        cout<<i<<"\t";
    }
}