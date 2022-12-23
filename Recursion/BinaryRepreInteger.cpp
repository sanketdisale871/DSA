#include<bits/stdc++.h>

using namespace std;

vector<int>ans;

void printBinary(int n){
    
    for(int i=32;i>=0;i--){
        
        if( (n & i)!= 0){
            ans.push_back(1);
        }
        else{
            ans.push_back(0);
        }
    }
}


int main(){
    
    int n = 434;
    
    printBinary(n);
    
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}
