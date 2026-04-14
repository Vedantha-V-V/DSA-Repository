#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int spanningTree(int n,vector<vector<int>>adj[]){
    int sum=0;
    vector<int>visited(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0, 0});
    while(!pq.empty()){
        auto i = pq.top();
        pq.pop();
        int node = i.second;
        int weight = i.first;


        if(visited[node]==1) continue;
        visited[node]=1;
        sum+=weight;
        for(auto j:adj[node]){
            int adjNode=j[0];
            int edWt = j[1];
            if(!visited[adjNode]){
                pq.push({edWt,adjNode});
            }
        }
    }
    return sum;
}

int main(){
    return 0;
}