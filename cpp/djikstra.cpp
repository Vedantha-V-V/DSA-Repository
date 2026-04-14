#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>djikstra(int num,vector<vector<int>>adj[],int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>shdist(num,9999);
    shdist[source]=0;
    pq.push({0,source});

    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto i:adj[node]){
            int edgedist=i[1];
            int adjNode=i[0];
            if(dist+edgedist < shdist[adjNode]){
                shdist[adjNode]=dist+edgedist;
                pq.push({shdist[adjNode],adjNode});
            }
        }
    }
    return shdist;
}

int main(){
    int num;
    cout<<"Enter the number of nodes:"<<endl;
    cin>>num;
    vector<vector<int>>adj[num];
    for(int i=0;i<num;i++){
        int val;
        cout<<"Enter the number of nodes connected to "<<i<<endl;
        cin>>val;
        for(int j=0;j<val;j++){
            int dist,node;
            vector<int>nodset;
            cout<<"Enter the node: ";
            cin>>node;
            cout<<"Enter the distance: ";
            cin>>dist;
            nodset.push_back(node);
            nodset.push_back(dist);
            adj[i].push_back(nodset);
        }
    }

    vector<int>shortestDist=djikstra(num,adj,0);
    cout<<"Shortest Distances from 0"<<endl;
    for(auto i:shortestDist){
        cout<<i<<"\t";
    }
    return 0;
}