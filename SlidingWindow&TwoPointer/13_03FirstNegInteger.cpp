//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
                                                 
            vector<long long>ans;
            
            queue<long long>q; // fro adding the negative element index from back side and removing out
            // of bound from front side.
            
            for(long long i=0;i<n;i++){
                // checking out of bound order
                if(i-k >=0){
                    if(!q.empty() && q.front()<=i-k){
                        q.pop();
                    }
                }
                // Pushing the negative elements into the array
                if(arr[i]<0){
                    q.push(i);
                }
                
                if(i>=(k-1)){ /// window size ban gayi hai !
                    if(!q.empty()){
                    ans.push_back(arr[q.front()]);
                    }
                    else{
                        ans.push_back(0);
                    }
                }
            }
            return ans;
                                                 
 }
