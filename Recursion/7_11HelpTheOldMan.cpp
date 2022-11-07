//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<int>ans;

void solve(int N,int &n,int src,int des,int help){
    

    // base case as one move completed then then decrease the moth number by one
    if(N==1){
        n--;
        if(n==0){
            ans.push_back(src);
            ans.push_back(des);
             
        }
       return;
    }
    
    // moving src to helper pole using destination pole
    solve(N-1,n,src,help,des);
    
    // last big disk move from src to des
    solve(1,n,src,des,help);
    
    //moving helper to destination using src
    solve(N-1,n,help,des,src);
}

    vector<int> shiftPile(int N, int n){
        
        int src = 1;
        int des = 3;
        int help = 2;
        
        solve(N,n,src,des,help);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
