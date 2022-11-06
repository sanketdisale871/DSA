//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    long long solve(int index,long long sum,long long mul,int n,int num){
        
        // Base condition
        
        if(index>n){
            return sum;
        }
        
        for(int i=1;i<=index;i++){
            mul*=num;
            num++;
        }
        
        solve(index+1,sum+mul,1,n,num);
    }

    long long sequence(int N){
        
        int index = 1;
        long long sum = 0;
        long long mul = 1;
        
        return solve(index,sum,mul,N,1);
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
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
