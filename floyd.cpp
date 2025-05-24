#include<iostream>
#include<vector>
using namespace std;

void floyd(vector<vector<int>>&cost,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cost[j][k]=min(cost[j][k],cost[j][i]+cost[i][k]);
            }
        }
    }

}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    vector<vector<int>>cost(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        cout<<"Enter the edge weights of "<<i<<" wrt to others (9999 for INF):"<<endl;
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    floyd(cost,n);
    cout<<"Optimal Path Matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<cost[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}