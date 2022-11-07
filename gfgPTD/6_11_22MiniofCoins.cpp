//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

vector<int>ans;

void solve(int target,vector<int>&coins)
{
    
    // Base case
    if(target<=0){
        return ;
    }
    
    for(int i=0;i<coins.size();i++){
        
        if(coins[i]<=target){
            ans.push_back(coins[i]);
            
            solve(target-coins[i],coins);
            
            break;
        }
    }
}
    
    vector<int> minPartition(int N)
    {
      vector<int>coins = {
          2000,500,200,100,50,20,10,5,2,1
      };
      
      solve(N,coins);
      
      return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
