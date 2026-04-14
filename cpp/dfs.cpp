#include<iostream>
#include<vector>
using namespace std;

void dfsOfGraph(int node, vector<vector<int>>adj, int visited[],vector<int>&dfs){
    visited[node]=1;
    dfs.push_back(node);
    for(auto i:adj[node]){
        if(!visited[i]){
            dfsOfGraph(i, adj, visited, dfs);
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        int temp;
        cout<<"Enter the number of connected nodes of "<<i<<": ";
        cin>>temp;
        cout<<"Enter the connected nodes of "<<i<<":"<<endl;
        for(int k=0;k<temp;k++){
            int val;
            cin>>val;
            adj[i].push_back(val);
        }
    }

    int visited[n]={0};
    int start = 0;
    vector<int> dfs;
    dfsOfGraph(start,adj,visited,dfs);

    for(int i:dfs){
        cout<<i<<"\t";
    }
}