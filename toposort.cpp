#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node, vector<vector<int>>adj, int visited[],stack<int>&st){
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int>TopoSort(int num, vector<vector<int>>adj){
    int visited[num]={0};
    stack<int> st;
    for(int i=0;i<num;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }

    vector<int>result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }

    return result;
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

    vector<int>topodfs=TopoSort(n,adj);
    for(int i: topodfs){
        cout<<i<<"\t";
    }
}