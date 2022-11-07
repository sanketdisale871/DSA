//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  long long int solve(int n,int cnt){
      
      // base case 
      if(n==1){
          return cnt;
      }
      
      // after reduction of odd position elements the size of arr becomes half
      solve(n/2,cnt+1);
      
  }
  
    long long int nthPosition(long long int n){
        
 
        long long int cnt = solve(n,0);
        
        return (1<<cnt);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout<<ob.nthPosition(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
