#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>weight,vector<int>profits,int n,int maxWeight){
    vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,0));

    for(int i=0;i<=n;i++){
        for(int w=0;w<=maxWeight;w++){
            if(i==0||w==0){
                dp[i][w]=0;
            }
            else if(weight[i-1]<=w){
                dp[i][w] = max(profits[i-1] + dp[i-1][w - weight[i-1]],dp[i-1][w]);
            }else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }

    cout<<"profit table:"<<endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<maxWeight+1;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return dp[n][maxWeight];
}

int main(){
    int n,maxWeight;
    cout<<"Enter the number of entries: ";
    cin>>n;
    cout<<"Enter the max weight: ";
    cin>>maxWeight;
    vector<int>weight,profits;
    cout<<"Enter the weights and profits:"<<endl;
    for(int i=0;i<n;i++){
        int wt,profit;
        cin>>wt;
        cin>>profit;
        weight.push_back(wt);
        profits.push_back(profit);
    }
    cout<<"Maximum Profit: "<<knapsack(weight,profits,n,maxWeight);
    return 0;
}