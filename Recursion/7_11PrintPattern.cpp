//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>ans;
    
    void solve(int n){
        
        // Base case
        // we return when we got the number as negative or equal to zeor
        if(n<=0){
            return;
        }
        
        // pehle hum ans vector mai value store karenge n then update karenge
        ans.push_back(n);
        
        int num = n-5;
        
        solve(num);
        // after return we are fillng same value bt we missing last value for that in main function we are adding
        ans.push_back(num);
    }

    vector<int> pattern(int N){
        
        solve(N);
        ans.push_back(N);
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
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
