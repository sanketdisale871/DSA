//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    
    // Total possible contugoues subarray
	    ll ans = n *1LL* (n+1)/2;
	     
	    ll cnt = 0;
	    
	    for(int i=0;i<n;i++){
	        
	        if(arr[i]<=k){ // the element which is smaller than k then increase the cnt
	            cnt++;
	        }else{
	            ans-=cnt * (cnt+1)/2; // this smaller element does not produce as we want subarray therfore decrease that number of arrys
	            cnt=0;
	        }
	    }
	    ans-=cnt * (cnt+1)/2; // if cnt has some value then
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
