#include <iostream>
using namespace std;

int main(){
    int k;
    for(int i=0;i<4;i++){
        int k=i+1;
        for(int j=0;j<=i;j++){
            cout << k << " ";
            k-=1;
        }
        cout << "\n";
    }
    return 0;
}